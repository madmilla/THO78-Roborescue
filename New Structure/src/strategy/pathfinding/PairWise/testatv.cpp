#include "testatv.h"

testATV::testATV(Dimension atv, int x, int y):
    atv{atv},
    x{x},
    y{y}{}

testATV::~testATV(){}


void testATV::goTo(int x, int y){
    this->x = x;
    this->y = y;
}
