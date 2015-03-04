#include "map.h"

Map::Map()
{

}

Map::~Map()
{

}

bool Map::readFile(const QString & name) {
    QFile file(name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cout << "could not load image with path" << name.toStdString() << std::endl;
        return false;
    }

    QTextStream file_stream(&file);
    while(!file_stream.atEnd()) {
        map.push_back(file_stream.readLine());
    }
    file.close();

    return true;
}

int Map::getHeight() {
    return static_cast<int>(map.size());
}

int Map::getWidth() {
    return static_cast<int>(map.back().length());
}

std::vector<QString>& Map::getMap() {
    return map;
}

bool Map::legit_char_checker() {
    const QChar values[] = {'0', '1', '2', '3', '4' };

    for(const auto & s : map) {
        for(const QChar & c : s) {
            int i = 0;
            for(const QChar & val : values) {
                if(c != val) {
                    i++;
                }
                else {
                    break;
                }
            }
            if( i >= 5) {
                return false;
            }
        }
    }
    return true;
}

bool Map::hasData() {
    if(getHeight() == 0 || getWidth() == 0) {
        return false;
    }
    return true;
}

bool Map::legit_size_checker() {
    const int size = getWidth();

    for(const auto & s : map) {
        if(size != s.length()) {
            return false;
        }
    }
    return true;
}

