#include "map.hpp"

Map::Map(std::string loc) : location{loc}
{
    std::ifstream map(loc);
    std::string row;
    if (!map.is_open()){
        exit(1);
    }
    while (getline(map, row)){
        addLine(explode(',',row));
    }
}
void Map::save(std::string loc){
     if(loc == ""){loc = location;}
     std::ofstream output(std::string(loc + ".dat"));
     int x = 0;
     for(auto item : mapping){
        x++;
        if(x == width()){
            output << item << "\n";
            x=0;
        }else{
             output << item << ",";
        }
     }

}
std::vector<std::string> Map::explode(char delimeter, std::string subject){
    std::string next;
    std::vector<std::string> result;
    for (std::string::const_iterator it = subject.begin(); it != subject.end(); it++) {
        if (*it == delimeter) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        }
        else {
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

void Map::addLine(std::vector<std::string> lines){
    mapWidth = static_cast<int>(lines.size());

    for (auto line : lines){
        mapping.push_back(stoi(line));
    }
    mapHeight = static_cast<int>(mapping.size() / mapWidth);
}

int Map::cellAt(int x, int y, bool next){
    int tar = mapping.at(y * width() + x);
    if(next){
        ++tar;
        if(tar > 4){tar =0;}
        mapping[y * width() +x ] = tar;

    }

    switch(tar){
    case 1:
        return 0x00;
        break;
    case 2:
        return 0x0000ff;
        break;
    case 3:
        return 0x00ff00;
        break;
    case 4:
        return 0xff0000;
        break;
    default:
        return 0xffffff;
        break;

    }

}



Map::~Map()
{

}

