#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <iostream>


class file
{
public:
    file(std::string nameread, std::string namewrite);
    int map(std::string name,std::string writename);

private:
    std::string nameread;
    std::string namewrite;
};

#endif // FILE_H
