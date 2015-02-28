#include "map.h"

#include <fstream>
#include "mapreadfailure.h"

Map::Map(std::string filename) :
    filename{filename},
    data{nullptr}
{
    std::ifstream file{filename, std::ios::in | std::ios::binary};
    if(!file.is_open()){
        throw MapReadFailure{"Cannot open file: " + filename};
    }

    file.read(reinterpret_cast<char *>(&rows), UISize);
    file.read(reinterpret_cast<char *>(&colloms), UISize);

    if(!file.good()){
        throw MapReadFailure{"Fail while reading rows or colloms"};
    }

    data = new unsigned int*[rows];
    for(unsigned int r = 0; r < rows; r++){
        data[r] = new unsigned int[colloms];
    }

    for(unsigned int r = 0; r < rows; r++){
        file.read(reinterpret_cast<char *>(data[r]), UISize * colloms);
        if(file.fail()){
            throw MapReadFailure{"Fail while reading data"};
        }else if(file.eof()){
            throw MapReadFailure{"File is to small"};
        }
    }

    if(file.fail()){
        throw MapReadFailure{"Fail while reading data"};
    }

    char eofCheck;
    file.read(&eofCheck, 1);

    if(!file.eof()){
        throw MapReadFailure{"File is to large"};
    }

    file.close();
}

Map::~Map()
{
    for(unsigned int r = 0; r < rows; r++){
        delete[] data[r];
        data[r] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

void Map::save(){
    std::ofstream file{filename, std::ios::out | std::ios::binary};
    file.write(reinterpret_cast<char *>(&rows), UISize);
    file.write(reinterpret_cast<char *>(&colloms), UISize);

    for(unsigned int r = 0; r < rows; r++){
        file.write(reinterpret_cast<char *>(data[r]), UISize * colloms);
    }

    file.close();
}

unsigned int Map::get(unsigned int row, unsigned int collom){
    if(row >= rows)
        throw std::range_error{"There are " + std::to_string(rows) + " rows, but request is: " + std::to_string(row)};
    if(collom >= colloms)
        throw std::range_error{"There are " + std::to_string(colloms) + " colloms, but request is: " + std::to_string(collom)};
    return data[row][collom];
}

void Map::set(unsigned int value, unsigned int row, unsigned int collom){
    if(row >= rows)
        throw std::range_error{"There are " + std::to_string(rows) + " rows, but request is: " + std::to_string(row)};
    if(collom >= colloms)
        throw std::range_error{"There are " + std::to_string(colloms) + " colloms, but request is: " + std::to_string(collom)};
    data[row][collom] = value;
}

void Map::createEmpty(std::string filename, unsigned int rows, unsigned int colloms){
    std::ofstream file{filename, std::ios::out | std::ios::binary};
    file.write(reinterpret_cast<char *>(&rows), UISize);
    file.write(reinterpret_cast<char *>(&colloms), UISize);

    unsigned int * temp = new unsigned int[colloms];

    for(unsigned int c = 0; c < colloms; c++){
        temp[c] = 0;
    }

    for(unsigned int r = 0; r < rows; r++){
        file.write(reinterpret_cast<char *>(temp), UISize * colloms);
    }

    delete[] temp;

    file.close();
}
