#include "emptymapbutton.h"
#include <iostream>

EmptyMapButton::EmptyMapButton(QWidget *parent) : QPushButton(parent)
{

}

void EmptyMapButton::click(){
    std::cout << "Clicked empty map button.";
    QPushButton::click();
}

EmptyMapButton::~EmptyMapButton()
{

}

