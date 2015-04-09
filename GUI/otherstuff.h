#ifndef OTHERSTUFF
#define OTHERSTUFF

#include <string>
#include <sstream>
#include "exceptions.h"

struct DPoint{
    double x, y, z;

    DPoint(double x, double y, double z = 0.0) : x(x), y(y), z(z) {}
    DPoint(const std::string & str) : DPoint(fromString(str)) {}
    DPoint() : DPoint(0,0,0){}
    DPoint(const DPoint & p) : x(p.x), y(p.y), z(p.z) {}

    static DPoint fromString(const std::string & str){
        std::stringstream stream;
        stream << str;

        double x = 0,y = 0,z = 0;
        char c;

        if(!(stream >> x >> c >> y) || c != ','){
            throw CannotParseException("Cannot parse string to DPoint");
        }

        if (stream >> c && c == ','){
            if(!(stream >> z)){
                 throw CannotParseException("Cannot parse string to DPoint");
            }
        }

        return DPoint(x, y, z);
    }

};

class Map{};

#endif // OTHERSTUFF

