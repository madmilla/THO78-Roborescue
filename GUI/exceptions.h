#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <stdexcept>

class CannotParseException : public std::runtime_error{
public:
    CannotParseException(const std::string & message) : std::runtime_error(message) {}
};

#endif // EXCEPTIONS

