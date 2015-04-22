#include "arraymap.h"
#include "iostream"
ArrayMap::ArrayMap()
{
    static const int arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    static const int arr2[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    static const int arr3[] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1};
    std::vector<int> * one;
    std::vector<int> * three;
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);
    std::vector<int> * two;
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
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
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    two = new vector<int> (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    data.push_back(two);
    one = new vector<int> (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    data.push_back(one);
}

ArrayMap::~ArrayMap()
{

}
bool ArrayMap::contains(int search){
    for(int i=0; i< data.size();i++){
        std::vector<int>* tmp;
        tmp = data.at(i);
        for(int ii=0; ii<tmp->size();ii++){
        if(tmp->at(ii) == search){return true; }


        }
    //std::cout <<"array";


    }
    return false;


}
void ArrayMap::print(){

    for(int i=0; i< data.size();i++){
        std::vector<int>* tmp;
        tmp = data.at(i);
        for(int ii=0; ii<tmp->size();ii++){
        std::cout <<tmp->at(ii);


        }
    std::cout <<"array";


    }




}
