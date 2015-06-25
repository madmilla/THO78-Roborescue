/*
 * Parser.h
 *
 *  Created on: 24 jun. 2015
 *      Author: Nathan
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>

class Parser {
public:
	Parser();

	template<typename T, typename J>
	static T bitCast(J j){
		T ret = *reinterpret_cast<T *>(&j);
		T mask = 0;
		for(unsigned int i=0; i<sizeof(J)*8; ++i){
			mask <<= 1;
			mask |= 1;
		}
		ret &= mask;

		return ret;
	}

	template<typename T>
	static void print(T t){
		for(int i=(sizeof(T)*8)-1; i>= 0; i--){
			if(t & 0x01 << i){
				std::cout << "1";
			}
			else{
				std::cout << "0";
			}
		}
		std::cout << std::endl;
	}

};

#endif /* PARSER_H_ */
