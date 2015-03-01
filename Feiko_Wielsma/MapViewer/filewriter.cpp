#include <QFileDialog>
#include "filewriter.h"

FileWriter::FileWriter(Map *map)
    :
      map {map}
{

}

FileWriter::~FileWriter()
{

}

void FileWriter::saveFile(QWidget* parent)
{
    auto fileName = QFileDialog::getSaveFileName(parent,
                      "Save Map", "/home/", "Map Files (*.map)");
    QFile file (fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(Object & object : map->getObjects())
    {
        out << "x:" << object.location.x() << ", " <<
               "y:" << object.location.y() << ", " <<
               "cr:" << object.color.red() << ", " <<
               "cg:" << object.color.green() << ", " <<
               "cb:" << object.color.blue() <<
               "\n";
    }
    file.close();
}

