#include "mapProcessor.h"

mapProcessor::mapProcessor()
{
    mapScene = new QGraphicsScene();
    legendScene = new QGraphicsScene();
}

mapProcessor::~mapProcessor() {

}

bool mapProcessor::processMap(QString mapFile, drawArea* map, drawArea *legend) {
    if (!mapFile.isEmpty())
        return false;
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
    //qDebug() << "Done processing file!";

    QVector<mapRectangle> rectangles(TOTAL_STRINGS * CHARS_PER_STRING);

    int quadcopterCount = 0, targetCount = 0, obstacleCount = 0, uatvCount = 0, rosbeeCount = 0;
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
            //qDebug() << "Added a rectangle to the vector!";
        }
    }
    if (map) //Map may be null for testing
        map->setRectangles(rectangles);

    QVector<QString> strings(5);
    strings.append(QString("Quadcopters: %1").arg(quadcopterCount));
    strings.append(QString("Targets: %1").arg(targetCount));
    strings.append(QString("Rosbees: %1").arg(rosbeeCount));
    strings.append(QString("Unmanned ATVs: %1").arg(uatvCount));
    strings.append(QString("Obstacles: %1").arg(obstacleCount));

    if (legend) //legend may be null for testing
        legend->setStrings(strings);

    for (uint i = 0; i < TOTAL_STRINGS; i++)
        free(mapArray[i]);

    free(mapArray);

    qDebug() << "Finished processing!";
    return true;
}
