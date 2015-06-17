#include <iostream>

using namespace std;

#include <databaseconnector.h>

int main()
{
    cout << "Hello World!" << endl;
    databaseConnector db("a","b","c","d");
    db.getAllPositions(1);
    return 0;
}

