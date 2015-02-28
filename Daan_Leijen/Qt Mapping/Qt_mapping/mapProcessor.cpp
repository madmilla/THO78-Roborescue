#include "mapProcessor.h"

mapProcessor::mapProcessor() {

}

mapProcessor::~mapProcessor() {

}

bool processMap(QString mapFile, QFrame* frame) {
    QFile file(mapFile);
    char mapArray[20][20];

    //Opens the map file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { //If file is empty, generates an empty map
        for (ulong i = 0; i < sizeof(mapArray); i++) {
            for (ulong j = 0; j < sizeof(mapArray[i]); j++) {
                mapArray[i][j] = 'e';
            }
        }
    }
    else {
        for (ulong i = 0; i < sizeof(mapArray); i++) {
            QString str = file.readLine();
            str.remove('\n');
            if (str.length() > 20){
                qDebug("Line %lu is too long!", i);
                return false;
            }
            if (str.length() < 20){
                qDebug("Line %lu is too short!", i);
                return false;
            }
            for (ulong j = 0; j < sizeof(mapArray[i]); j++) {
                mapArray[i][j] = str.at(j).toLatin1();
            }
        }
    }

    //Closes the map file
    file.close();

    for (ulong i = 0; i < sizeof(mapArray); i++) {
        for (ulong j = 0; j < sizeof(mapArray[i]); j++) {
            qDebug() << mapArray[i][j];
        }
        qDebug() << '\n';
    }

    return true;
}
