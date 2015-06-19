#include "ATV.h"

ATV::ATV(Dimension size, int x, int y):
    size{size},
    x{x},
    y{y}{}

ATV::~ATV(){}


void ATV::goTo(int x, int y){
    this->x = x;
    this->y = y;
}
