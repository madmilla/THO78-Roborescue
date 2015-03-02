#include "mapProcessor.h"

mapProcessor::mapProcessor() {
    mapScene = new QGraphicsScene();
    legendScene = new QGraphicsScene();
}

mapProcessor::~mapProcessor() {

}

bool mapProcessor::processMap(QString mapFile, QGraphicsView* map, QGraphicsView* legend) {
    QFile file(mapFile);
    char **mapArray;

    mapScene->clear();
    map->setScene(mapScene);
    legendScene->clear();
    legend->setScene(legendScene);

    uint charsPerString = 20;
    uint totalStrings = 20;

    rectangles.clear();
    for (uint i = 0; i < totalStrings; i++)
        rectangles[i].resize(charsPerString);

    rectangles.resize(totalStrings);

    int quadcopterCount = 0;
    int targetCount = 0;
    int obstacleCount = 0;
    int uatvCount = 0;
    int rosbeeCount = 0;

    mapArray = static_cast<char**>(malloc(sizeof(char) * totalStrings));

    for (uint i = 0; i < totalStrings; i++)
        mapArray[i] = static_cast<char*>(malloc(charsPerString));

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
        for (uint i = 0; i < charsPerString; i++) {
            QString str = file.readLine();
            str.remove('\n');
            if (static_cast<uint>(str.length()) > charsPerString){
                qDebug("Line %u is too long!", i);
                qDebug() << str;
                return false;
            }
            if (static_cast<uint>(str.length()) < charsPerString){
                qDebug("Line %u is too short!", i);
                qDebug() << str;
                return false;
            }
            for (ulong j = 0; j < totalStrings; j++) {
                mapArray[i][j] = tolower(str.at(j).toLatin1());
            }
        }
    }

    //Closes the map file
    file.close();
    qDebug() << "Done processing file!";

    //Draw the map and legend
    for (uint i = 0; i < charsPerString; i++) {
        for (ulong j = 0; j < totalStrings; j++) {
            QGraphicsRectItem *rect = new QGraphicsRectItem();

            switch (mapArray[i][j]){
                case 'q':
                    quadcopterCount++;
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::red));
                    break;
                case 't':
                    targetCount++;
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::yellow));
                    break;
                case 'r':
                    rosbeeCount++;
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::green));
                    break;
                case 'u':
                    uatvCount++;
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::blue));
                    break;
                case 'o':
                    obstacleCount++;
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::black));
                    break;
                default:
                    rect->setRect(i * (map->width()/charsPerString), j * (map->height()/totalStrings), map->width()/charsPerString, map->height()/totalStrings);
                    rect->setBrush(QBrush(Qt::cyan, Qt::CrossPattern));
                    break;
            }
            rectangles[i][j] = rect;
            qDebug() << "Added a rectangle to the vector!";
        }
    }
    //Draw the map and legend
    for (uint i = 0; i < charsPerString; i++) {
        for (ulong j = 0; j < totalStrings; j++) {
            mapScene->addItem(rectangles[i][j]);
        }
    }

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

    for (uint i = 0; i < totalStrings; i++)
        free(mapArray[i]);

    free(mapArray);

    //map->show();
    //legend->show();
    qDebug() << "Finished processing!";
    return true;
}
