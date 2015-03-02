#include "mapProcessor.h"

mapProcessor::mapProcessor():
    rectangles(TOTAL_STRINGS*CHARS_PER_STRING)
{
    mapScene = new QGraphicsScene();
    legendScene = new QGraphicsScene();
}

mapProcessor::~mapProcessor() {

}

bool mapProcessor::processMap(QString mapFile, QGraphicsView* map) {
    QFile file(mapFile);
    char **mapArray;

    mapArray = static_cast<char**>(malloc(sizeof(char) * TOTAL_STRINGS));

    for (uint i = 0; i < TOTAL_STRINGS; i++)
        mapArray[i] = static_cast<char*>(malloc(CHARS_PER_STRING));

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return false;

    //Opens the map file
    if (file.size() == 0) { //If file is empty, generates an empty map
        for (ulong i = 0; i < sizeof(mapArray); i++) {
            for (ulong j = 0; j < sizeof(mapArray[i]); j++) {
                mapArray[i][j] = 'e';
            }
        }
    }

    else { //Processes a map file that isn't empty
        for (uint i = 0; i < CHARS_PER_STRING; i++) {
            QString str = file.readLine();
            str.remove('\n');
            if (static_cast<uint>(str.length()) > CHARS_PER_STRING){
                qDebug("Line %u is too long!", i);
                qDebug() << str;
                return false;
            }
            if (static_cast<uint>(str.length()) < CHARS_PER_STRING){
                qDebug("Line %u is too short!", i);
                qDebug() << str;
                return false;
            }
            for (ulong j = 0; j < TOTAL_STRINGS; j++) {
                mapArray[i][j] = tolower(str.at(j).toLatin1());
            }
        }
    }

    //Closes the map file
    file.close();
    qDebug() << "Done processing file!";

    //Fill rectangles vector
    for (uint i = 0; i < CHARS_PER_STRING; i++) {
        for (ulong j = 0; j < TOTAL_STRINGS; j++) {
            rectangles[i*CHARS_PER_STRING + j] = mapRectangle(
                        QRectF(j * (map->width()/CHARS_PER_STRING), i * (map->height()/TOTAL_STRINGS), map->width()/CHARS_PER_STRING, map->height()/TOTAL_STRINGS),
                        mapArray[i][j]);
            switch (mapArray[i][j]){
                case 'e':
                    break;
                case 'q':
                    quadcopterCount++;
                    break;
                case 't':
                    targetCount++;
                    break;
                case 'r':
                    rosbeeCount++;
                    break;
                case 'u':
                    uatvCount++;
                    break;
                case 'o':
                    obstacleCount++;
                    break;
                default:
                    break;
            }
            qDebug() << "Added a rectangle to the vector!";
        }
    }

    for (uint i = 0; i < TOTAL_STRINGS; i++)
        free(mapArray[i]);

    free(mapArray);

    qDebug() << "Finished processing!";
    return true;
}

bool mapProcessor::drawMap(QGraphicsView *map, QGraphicsView *legend){
    mapScene->clear();
    map->setScene(mapScene);
    legendScene->clear();
    legend->setScene(legendScene);

    //Draw the map and legend
    /*
    for (int i = 0; i < rectangles.size(); i++){
        mapScene->addItem(rectangles[i]);
        //qDebug() << "Added item to scene!";
    }
    */

    QFont font;
    font.setPixelSize(10);
    font.setBold(true);
    font.setFamily("Calibri");

    QString quadString = QString("Quadcopters: %1").arg(quadcopterCount);
    quadText.addText(10, 10, font,  quadString);
    legendScene->addPath(quadText, QPen(QBrush(Qt::red), 1), QBrush(Qt::red));

    QString targetString = QString("Targets: %1").arg(targetCount);
    targetText.addText(10, 40, font,  targetString);
    legendScene->addPath(targetText, QPen(QBrush(Qt::yellow), 1), QBrush(Qt::yellow));

    QString rosbeeString = QString("Rosbees: %1").arg(rosbeeCount);
    rosbeeText.addText(10, 70, font,  rosbeeString);
    legendScene->addPath(rosbeeText, QPen(QBrush(Qt::green), 1), QBrush(Qt::green));

    QString uatvString = QString("Unmanned ATVs: %1").arg(uatvCount);
    uatvText.addText(10, 100, font,  uatvString);
    legendScene->addPath(uatvText, QPen(QBrush(Qt::blue), 1), QBrush(Qt::blue));

    QString obstacleString = QString("Obstacles: %1").arg(obstacleCount);
    obstacleText.addText(10, 130, font,  obstacleString);
    legendScene->addPath(obstacleText, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

    map->show();
    legend->show();

    return true;
}
