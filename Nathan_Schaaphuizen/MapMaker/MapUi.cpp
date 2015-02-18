/// @file MapUi.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "MapUi.hpp"
#include "Map.hpp"
#include "Drawable.hpp"
#include "MouseListener.hpp"
#include <fstream>
#include <QEvent>
#include <QMouseEvent>
#include <QSize>
#include <QPainter>

MapLoadException::MapLoadException(const std::string &newError):
    //String holding the error.
    error{newError}
{}
const char * MapLoadException::what() const{
    //Return messages as a c string.
    return error.c_str();
}

MapUi::MapUi():
//Default tile size
tileSize{20},
//Default grid shown
isShowGrid{true}
{
    //Unknown tile type color = gray.
    tileColors[TileType::Unknown] = Qt::gray;
    //Free tile type color = white.
    tileColors[TileType::Free] = Qt::white;
    //Blocked tile type color = black.
    tileColors[TileType::Blocked] = Qt::black;
    //ATV tile type color = yellow.
    tileColors[TileType::ATV] = Qt::yellow;
    //Quadcopter tile type color = yellow.
    tileColors[TileType::QC] = Qt::red;
    //Rosbee ile type color = blue.
    tileColors[TileType::Rosbee] = Qt::blue;
}

void MapUi::draw(QPainter &p) const{
    //For each tile:
    for(int x=0;x<tiles.size();++x){
        for(int y=0;y<tiles[x].size();++y){
            //Create a rectangle based on position and tile size.
            //We're going to draw this one later.
            QRect rect{x*tileSize, y*tileSize, tileSize, tileSize};
            //Color we're going to use on our rectangle.
            QColor color;
            //Try to find color:
            try{
               //Find the color matching the tile type.
               //If there is no match found a exception is thrown.
               color = tileColors.at(static_cast<TileType>(tiles[x][y]));
            }
            catch(std::out_of_range e){
               //Set default color.
               color = Qt::gray;
            }
            //Draw the rectangle and fill it with color.
            p.fillRect(rect, color);
            //Check if we need to draw the grid.
            if(isShowGrid){
                //Set draw color to red.
                p.setPen(Qt::red);
                //Draw an empty box over the just draw fill box.
                //If done for every tile this will create a nice grid.
                p.drawRect(rect);
            }
        }
    }
}

void MapUi::mouseButtonPressed(const Qt::MouseButton &button, int x, int y){
    //Check if there are tiles.
    //You can't click on tiles if there aren't any.
    if(tileCount > 0){
        //Divide the mouse x position by the tile size.
        //This will give the tile on position x in the tile array.
        x = (x / tileSize);
        //Divide the mouse y position by the tile size.
        //This will give the tile on position y in the tile array.
        y = (y / tileSize);
        //Check if it was a right mouse click.
        if (button == Qt::MouseButton::RightButton){
            //Lower the tile type by 1.
            tiles[x][y]--;
            //Check if the first tile type is reached.
            if (static_cast<signed char>(tiles[x][y]) < 0){
                //Set tile to the last tile type -1, this is the last valid tile type.
                tiles[x][y] = static_cast<unsigned char>(TileType::Last) - 1;
            }
        }
        //Check if it was a lef mouse click.
        else if (button == Qt::MouseButton::LeftButton){
            //Raise the tile type by 1.
            tiles[x][y]++;
            //Chec if the last tile type is reached.
            if (tiles[x][y] >= static_cast<unsigned char>(TileType::Last)){
                //Set tile to the fist tile type.
                tiles[x][y] = static_cast<unsigned char>(TileType::Unknown);
            }
        }
    }
}

void MapUi::save(const std::string &fileName) const{
    //Create a standard output stream.
    std::ofstream out;
    //Open file for binary writing.
    out.open(fileName, std::ofstream::out | std::ios_base::binary);
    //Create and get a new serialized version of the map.
    Serializable *s = serialise();
    //Calculate the amount of bytes to write.
    //This is not the size of the struct as might be expected.
    //But rather the map diameter squared plus for extra bytes for the size.
    int writeSize = (s->size * s->size) + sizeof(s->size);
    //Write struct to file.
    //Because the struct only contains primitive types and no pointers,
    //references or other type of addresses.
    //Can it be cast to a char array and directly written as data.
    (void)out.write(reinterpret_cast<char*>(s),writeSize);
    //Close the file, no longer need it.
    out.close();
    //Remove the struct we just created.
    delete s;
}

void MapUi::load(const std::string &fileName){
    //Create a standard input stream.
    std::ifstream in;
    //Open file for binary reading.
    in.open(fileName, std::ofstream::in | std::ios_base::binary);
    //Create and get a new serialized version of the map.
    Serializable *s = new Serializable;
    //Calculate the amount of bytes to read.
    //This is the size of the struct, because this is the maximum we can read.
    //The struct does not have to be filled to its maximum.
    //So it's ok to read smaller files.
    int readSize = sizeof(*s);
    //Read the file and put the bytes in the struct.
    (void)in.read(reinterpret_cast<char*>(s), readSize);
    //Call other load function that will parse the map from the struct.
    load(s);
    //Remove the struct we just created.
    delete s;
}

void MapUi::load(const Serializable* serializedMap){
    //Get rid of all the tiles previously stored.
    tiles.clear();
    //Set tile count to 0, we just got rid of all the tiels.
    tileCount = 0;
    //Check if the file will fit in the buffer.
    //A error is better than reading half a map because it won't fit.
    if(serializedMap->size > maxMapSize){
        //Throw exception.
        throw MapLoadException{"File size too large for buffer."};
    }
    //Check if the file is not empty, no point in reading empty files.
    if(serializedMap->size <= 0){
        //Throw exception.
        throw MapLoadException{"Empty file."};
    }
    //Position in the tiles array from the struct. Starting at the beginning.
    int p = 0;
    //Resize the map to make new loaded map fit.
    resize(serializedMap->size);
    //For each tile in the struct:
    for(unsigned int x=0;x<serializedMap->size;++x){
        for(unsigned int y=0;y<serializedMap->size;++y){
            //Check if the read byte represents a known file type.
            //If not, the file may got corrupted, someone messed with it
            //or you're trying to load a completely different file.
            if(serializedMap->tiles[p] >= static_cast<unsigned char>(TileType::Last)){
                //Resize to map back to 0.
                //All privious read data may also be wrong.
                //Since there's is no way to know for sure we just dump it.
                resize(0);
                //Throw exception.
                throw MapLoadException{"File data could not be read."};
            }
            //Add a new tile to map.
            //Tile type based on the type tile type in the struct.
            addTile(x,y,static_cast<TileType>(serializedMap->tiles[p++]));
        }
    }
}

void MapUi::saveAsImage(const std::string &fileName, const QImage::Format &format)const{
   //Create a new image.
   //Giving it the size of the map in pixels. (This is the same as the widget size fyi.)
   //Using the format specified as parameter.
   QImage img{tileCount*tileSize,tileCount*tileSize,format};
   //Fill image with pixels.
   //No clue what this does.
   //Image won't draw correct without fill, no clue why.
   img.fill(20);
   //Color we're going to draw.
   QColor c;
   //For each tile:
   for(int x=0;x<tileCount;++x){
       for(int y=0;y<tileCount;++y){
           //Get color of the tile.
           c = tileColors.at(static_cast<TileType>(tiles[x][y]));
           //For each pixel in tile:
           for(int i=0;i<tileSize;++i){
               for(int j=0;j<tileSize;++j){
                   //Set the color of the pixel of the tile.
                   img.setPixel(x*tileSize+i,y*tileSize+j,c.rgb());
                   //Check if we need to draw the grid.
                   //And if we are on a current pixel is no the edge of a tile.
                   //Or the last pixel on the image border.
                   if( isShowGrid && (
                           j==0 ||
                           i==0  ||
                           ((x == tileCount-1) && i == (tileSize-1)) ||
                           ((y == tileCount-1) && j == (tileSize-1))
                           )
                   ){
                       //Set pixel color the default red grid color.
                       img.setPixel(x*tileSize+i,y*tileSize+j,QColor{Qt::red}.rgb());
                   }
               }
           }
       }
   }
   //Save image to file.
   img.save(fileName.c_str());
}

void MapUi::showGrid(bool b){
    //Set whenever to draw grid or not.
    isShowGrid = b;
}

bool MapUi::isGridShown() const{
    //Return the grid show status.
    return isShowGrid;
}

void MapUi::fitInWindow(const QSize &windowSize){
    //Calculate tile size to fit in window.
    //Size is based on the window width.
    //Since the map is always squerd the window also should be squared.
    //If not the map will not fit over the y-axis of the window.
    tileSize = (windowSize.width() / tileCount);
}

