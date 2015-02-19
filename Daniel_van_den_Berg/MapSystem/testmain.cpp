#include "Logic.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "This is the test application.";
    Logic *logic = new Logic();
    delete logic;
    return 0;
}

