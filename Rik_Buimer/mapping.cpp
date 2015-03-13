#include "mapping.h"

Mapping::Mapping()
{

}

Mapping::~Mapping()
{

}


void Mapping::writeDataBack(std::vector<int> inVector) {
    dataVector = inVector;
}

int Mapping::saveFile() {
    return 0;
}

std::vector<int> Mapping::openFile(QFile& file)
{
    QTextStream inStream(&file);
    while(!inStream.atEnd())
    {
        QString line = inStream.read(1);
        if (line != "\n")
        {
            int data = line.toInt();
            dataVector.push_back(data);
        }
    }
    file.close();
    return dataVector;
}
