#include "mapBack.h"
#include <iostream>
//#include <QTextStream>
#include <exception>
//#include <QTableWidget>

mapBack::mapBack()
{
    //char* array = new char[400];
    for (int i = 0; i<400; i++)
    {
        currentMap[i] = '0';
    }
}

int mapBack::colorAt(int x, int y)
{
    //QColor::QColor temp = new QColor();
    switch(currentMap[y*20+x]){
    case '1':
        return 0x000000;
    case '2':
        return 0xFF0000;
    case '3':
        return 0x00FF00;
    case '4':
        return 0x0000FF;
    default:
        return 0xFFFFFF;
    }
}

void mapBack::loadEmpty()
{

    // create empty array in memory

    char* array = new char[400];
    for (int i = 0; i<400; i++)
    {
        array[i] = '0';
    }

    //draw in GUI
    copyMap(array);
}

void mapBack::loader(QString filename)
{
    //load the file into the char array
    try
    {
        QFile loadfile(filename);
        char* array = new char[400];
        if(loadfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream ts(&loadfile);
            //int linenr = 0;
            for (int lnr = 0; lnr<20; lnr++)
            {
                QString line = ts.readLine();
                for (int i = 0; i < 20; i++)
                {
                    //if (line.at(i)!='\n')
                    //{

                    array[lnr*20+i] = line.at(i).toLatin1();
                    //++linenr;
                    //}
                }
            }
        }

        // display the array on the GUI

        copyMap(array);
    }
    catch(std::exception e)
    {
        std::cerr<<e.what()<<std::endl<<"Invalid file"<<std::endl;
    }

}

//void mapBack::save(char *savename)
//{
//
//}

void mapBack::copyMap(char *mArray)
{

    for (int i = 0; i<400; i++)
    {
        currentMap[i]=mArray[i];
    }





    delete mArray;




    //Debug loaded map into console
    //for (int j = 0; j<400; j++)
    //{
    //    std::cout<<currentMap[j];
    //}
    //std::cout<<std::endl;

}

mapBack::~mapBack()
{

}
