/*
 * tests.cpp
 *
 *  Created on: 1 apr. 2015
 *      Author: Wibren
 */

#include "tests.h"

#include <iostream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	for(Test * t : tests){
		delete t;
	}
}

int Tests::run(){
    int returner = 0;
    std::cout << "Start tests\n";
    for(Test * t : tests){
        std::cout << "[" << t->name() << "] Started\n";
        bool result = t->test();
        if(result){
            std::cout << "[" << t->name() << "] Succeed!\n";
        }else{
            std::cerr << "[" << t->name() << "] Failed!\n";
            std::cerr << "##########\n";
            returner++;
        }
    }
    return returner;
}
