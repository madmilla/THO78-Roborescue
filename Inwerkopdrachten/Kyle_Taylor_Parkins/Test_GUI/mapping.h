#ifndef MAPPING_H
#define MAPPING_H

#include <vector>
#include <QString>
#include <QTextStream>
#include <QFile>

class Mapping
{
public:
    Mapping();
    ~Mapping();
    std::vector<int> openFile(QFile& file);
    void writeDataBack(std::vector<int> inVector);
    int saveFile();
private:
    std::vector<int> dataVector;
};

#endif // MAPPING_H
