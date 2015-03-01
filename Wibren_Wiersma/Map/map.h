#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map
{
private:
    std::string filename;
    unsigned int** data;
    unsigned int rows;
    unsigned int colloms;

    std::vector<std::string> dataNames;

    static const int UISize = 4;
public:
    Map(std::string filename);
    ~Map();

    void save();

    unsigned int get(unsigned int row, unsigned int collom);
    void set(unsigned int value, unsigned int row, unsigned int collom);

    unsigned int rowCount() {return rows;}
    unsigned int collomCount() {return colloms;}

    static void createEmpty(std::string filename, unsigned int rows, unsigned int colloms);

    std::vector<std::string> & names(){
        return dataNames;
    }

};

#endif // MAP_H
