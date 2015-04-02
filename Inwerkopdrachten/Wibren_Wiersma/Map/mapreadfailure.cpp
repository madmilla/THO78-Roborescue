#include "mapreadfailure.h"

MapReadFailure::MapReadFailure(const std::string & what) : std::runtime_error{what} {}
MapReadFailure::MapReadFailure(const char* what) : std::runtime_error{what} {}
