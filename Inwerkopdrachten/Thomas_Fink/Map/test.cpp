#include "test.h"
#include "maplogic.h"
#include <QCryptographicHash>

Test::Test()
{

}

Test::~Test()
{

}

int Test::run(){
    int error = 0;
    if(!QFile::copy("defaultMap.default", "testMap.tmp")) error++;

    MapLogic testMap("testMap.tmp");

    if(testMap.mapLayout.size() != 20) error++;

    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++){
            if(testMap.mapLayout[y].size() != 20) error++;

            if(testMap.getMapData(y,x) != 0) error++;
            testMap.updateMap(y,x,3);
        }
    }

    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++){
            if(testMap.getMapData(y,x) != 3) error++;
        }
    }

    testMap.updateMap(5,5,2);
    if(testMap.getMapData(5,5) != 2) error++;

    testMap.updateMap(0,0,1);
    if(testMap.getMapData(0,0) != 1) error++;

    testMap.updateMap(19,19,1);
    if(testMap.getMapData(19,19) != 1) error++;

    testMap.updateMap(20,20,1);
    if(testMap.getMapData(20,20) != 0) error++;

    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++){
            testMap.updateMap(y,x,0);
        }
    }

    testMap.saveMap();

    QFile defaultMapFile("defaultMap.default");
    QFile testMapFile("testMap.tmp");

    QCryptographicHash hashDefault( QCryptographicHash::Sha1 );
    QCryptographicHash hashTest( QCryptographicHash::Sha1 );

    if ( defaultMapFile.open( QIODevice::ReadOnly ) &&
         testMapFile.open( QIODevice::ReadOnly ) ) {

        hashDefault.addData( defaultMapFile.readAll() );
        hashTest.addData( testMapFile.readAll() );
    }
    else{
        error++;
    }
    // Retrieve the SHA1 signature of the file
    QByteArray sigDefault = hashDefault.result();
    QByteArray sigTest = hashTest.result();

    if(sigDefault != sigTest) error++;
    defaultMapFile.close();
    testMapFile.close();



    QFile::remove("testMap.tmp");
    return error;
}
