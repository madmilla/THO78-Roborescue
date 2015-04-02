#include <iostream>
#include <fstream>
#include <vector>

void test(const char* path);
const char* path1 = "map1.txt";
const char* path2 = "map2.txt";

// normal main
int main(int argc, char *argv[])
{

 /********************************begin of test***********************************************/
    std::cout << "first test" << std::endl;
    test(path1);
    std::cout << "second test" << std::endl;
    test(path2);
    return 0;

/********************************end of test*************************************************/
}

std::vector<int> getFile(const char* path){
    std::vector<int> testVector; //for testing only
    std::ifstream input; 

    input.open(path);
        if (!input.is_open()){
            std::cout << "ERROR\n";
        }
        else{
            char a;
            int t;
            while (input >> a)
            {
                if (a != '\n'){
                    t = a;
                  testVector.push_back(t);
                  }
            }
            input.close();
        }
        return testVector;
}

void test(const char* path){
  std::vector<int> temp = getFile(path);
          if (temp.size() == 400) {
                  std::cout << "Map has the right size" << std::endl;
          }
          else {
                  std::cout << "Map has the wrong size" << std::endl;
          }
}
