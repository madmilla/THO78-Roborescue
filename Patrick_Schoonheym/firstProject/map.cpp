#include "map.h"

Map::Map()
{

}

Map::~Map()
{

}

const bool Map::readFile(const QString & name) {
    QFile file(name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "could not load image with path" << name << "\n";
        return false;
    }

    QTextStream file_stream(&file);
    while(!file_stream.atEnd()) {
        map.push_back(file_stream.readLine());
    }
    file.close();

    return true;
}

const int Map::getHeight() {
    return static_cast<int>(map.size());
}

const int Map::getWidth() {
    return static_cast<int>(map.back().length());
}

std::vector<QString>& Map::getMap() {
    return map;
}

const bool Map::legit_char_checker() {
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

const bool Map::hasData() {
    if(getHeight() == 0 || getWidth() == 0) {
        return false;
    }
    return true;
}

const bool Map::legit_size_checker() {
    size_t size = map[0].length();

    for(const auto & s : map) {
        for(const QChar & c : s) {

            if(size != s.length()) {
                return false;
            }
        }
    }
    return true;
}

