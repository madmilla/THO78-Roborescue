#ifndef ARRAYMAP_H
#define ARRAYMAP_H
#include <vector>
#include "databaseconnector.h"
using namespace std;
class ArrayMap {
public:
  ArrayMap(int i);
  databaseConnector Connector;
  vector<vector<int> *> bufferdata;
  ~ArrayMap();
  void setLocationValue(int x, int y,int value);
  void print();
  int getLocationValue(int x, int y);
  bool contains(int);
};

#endif // ARRAYMAP_H
