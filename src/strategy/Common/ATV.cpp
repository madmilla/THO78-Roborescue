#include "ATV.h"

ATV::ATV(Dimension atv, int x, int y):
    atv{atv},
    x{x},
    y{y}{}

ATV::~ATV(){}


void ATV::goTo(int x, int y){
    this->x = x;
    this->y = y;
}
