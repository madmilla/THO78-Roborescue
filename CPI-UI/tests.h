/*
 * tests.h
 *
 *  Created on: 1 apr. 2015
 *      Author: Wibren
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "test.h"
#include <vector>

class Tests
{
public:
	Tests();
    ~Tests();

    int run();
private:
    std::vector<Test*> tests;
};

#endif /* TESTS_H_ */
