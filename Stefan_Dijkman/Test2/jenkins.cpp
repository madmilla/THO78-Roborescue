
#include <iostream>
#include <fstream>

void test(const char* path);
const char* path1 = "Stefan_Dijkman/Test2/testMapGoed.txt";
const char* path2 = "Stefan_Dijkman/Test2/testMapFout.txt";

// normal main
int main(int argc, char *argv[])
{

 /********************************begin of test***********************************************/
    std::cout << "eerste test" << std::endl;
    test(path1);
    std::cout << "tweede test" << std::endl;
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
                  std::cout << "map klopt" << std::endl;
          }
          else {
                  std::cout << "map klopt niet" << std::endl;
          }
}
