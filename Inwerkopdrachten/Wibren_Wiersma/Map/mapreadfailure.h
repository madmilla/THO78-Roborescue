#ifndef MAPREADFAILURE_H
#define MAPREADFAILURE_H

#include <stdexcept>

class MapReadFailure : public std::runtime_error
{
public:
    MapReadFailure(const std::string & what);
    MapReadFailure(const char* what);
};

#endif // MAPREADFAILURE_H
