
#include "filewriter.h"

FileWriter::FileWriter(Map *map)
    :
      map {map}
{

}

FileWriter::~FileWriter()
{

}

void FileWriter::saveFile(QString fileName)
{
    std::map<ObjectType, QString> typeToStringMap =
    {
        {ObjectType::Empty, QString("empty")},
        {ObjectType::Wall, QString("wall")},
        {ObjectType::Tree, QString("tree")},
        {ObjectType::Quad, QString("quad")},
        {ObjectType::ATV, QString("atv")}
    };

    QFile file (fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(Object & object : map->getObjects())
    {
        out << "x:" << object.position.x() << ", " <<
               "y:" << object.position.y() << ", " <<
               "type:" << typeToStringMap[object.type] <<
               "\n";
    }
    file.close();
}

