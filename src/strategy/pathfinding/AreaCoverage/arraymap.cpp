/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file arraymap.cpp
* @date Created: 4/28/2015
*
* @author Mathijs Arends
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/#include "arraymap.h"
#include "iostream"
ArrayMap::ArrayMap(int i)
{
    if(i==1){
    static const int arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    static const int arr2[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr3[] = {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::vector<int> * one;
    std::vector<int> * three;
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);
    std::vector<int> * two;
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);

    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);

    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);}
    if(i==2){
    static const int arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    static const int arr2[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr3[] = {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::vector<int> * one;
    std::vector<int> * three;
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);
    std::vector<int> * two;
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);

    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);

    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);}
    if(i==3){
    static const int arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    static const int arr2[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr3[] = {1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1};
    std::vector<int> * one;
    std::vector<int> * three;
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);
    std::vector<int> * two;
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);


    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);

    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);}
    if(i==4){
    static const int arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    static const int arr2[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr3[] = {1,0,1,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr4[] = {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1};
    std::vector<int> * one;
    std::vector<int> * two;
    std::vector<int> * three;
    std::vector<int> * four;
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);

    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    three = new vector<int> (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    data.push_back(three);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    four = new vector<int> (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]) );
    data.push_back(four);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);}
}

ArrayMap::~ArrayMap()
{

}
bool ArrayMap::contains(int search){
    for(int i=0; i< int(data.size());i++){
        std::vector<int>* tmp;
        tmp = data.at(i);
        for(int ii=0; ii<int(tmp->size());ii++){
        if(tmp->at(ii) == search){return true; }


        }
    //std::cout <<"array";


    }
    return false;


}
void ArrayMap::print(){

    for(int i=0; i< int(data.size());i++){
        std::vector<int>* tmp;
        tmp = data.at(i);
        for(int ii=0; ii<int(tmp->size());ii++){
        std::cout <<tmp->at(ii);


        }
    std::cout <<"array";


    }




}
