#ifndef ARRAYMAP_H
#define ARRAYMAP_H
#include <vector>
using namespace std;
class ArrayMap
{
public:

    ArrayMap();
    vector< vector<int>* > data;
    ~ArrayMap();
    void print();
    bool contains(int);
};

#endif // ARRAYMAP_H
