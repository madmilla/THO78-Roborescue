#include "file.h"


file::file(std::string nameread, std::string namewrite)
{
    map(nameread,namewrite);
}

int file::map(std::string name, std::string namewrite){
    std::ifstream myReadFile;
    std::ofstream outPutFile;
    outPutFile.open(namewrite);
    string line;
    myReadFile.open(name);
    if (!myReadFile.is_open()){
        std::cout << ("kan het eerste bestand niet openen bestand niet openen");
    }
    else{
        std::cout << ("Het eerste bestand wordt wel geopend en gelezen \n");
    }

    while(getline(myReadFile,line)){
        outPutFile << line << "\n";
    }

    myReadFile.close();
    return 0;
}

