#include "mapBack.h"
#include <iostream>
#include <exception>

mapBack::mapBack()
{
    for (int i = 0; i<400; i++)
    {
        currentMap[i] = '0';
    }
}

int mapBack::colorAt(int x, int y)
{
    switch(currentMap[y*20+x])
    {
    case '1':
        return 0x888888;
    case '2':
        return 0xFF8888;
    case '3':
        return 0x88FF88;
    case '4':
        return 0x8888FF;
    default:
        return 0xFFFFFF;
    }
}

QString mapBack::setRobot(int i)
{
    switch (i)
    {
    case 1:
        return "A";
    case 2:
        return "Q";
    case 3:
        return "R";
    default:
        return " ";
    }
}

void mapBack::loadEmpty()
{
    char* array = new char[400];
    for (int i = 0; i<400; i++)
    {
        array[i] = '0';
    }
    copyMap(array);
}

void mapBack::loader(QString filename)
{
    try
    {
        QFile loadfile(filename);
        char* array = new char[400];
        if(loadfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream ts(&loadfile);
            for (int lnr = 0; lnr<20; lnr++)
            {
                QString line = ts.readLine();
                for (int i = 0; i < 20; i++)
                {
                    array[lnr*20+i] = line.at(i).toLatin1();
                }
            }
        }
        copyMap(array);
    }
    catch(std::exception e)
    {
        std::cerr<<e.what()<<std::endl<<"Invalid file"<<std::endl;
    }
}
/*
void mapBack::save(char *savename)
{

}
*/
void mapBack::copyMap(char *mArray)
{
    for (int i = 0; i<400; i++)
    {
        currentMap[i]=mArray[i];
    }
    delete mArray;
}

mapBack::~mapBack()
{

}
