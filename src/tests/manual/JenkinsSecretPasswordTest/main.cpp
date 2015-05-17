#include <iostream>
int main(int argc, char* argv[]) {
    if(argc < 3){
        std::cout << "no password specified\nUsage: " << argv[0] <<" [username] [password]\n";
        return 0;
    }
    std::string username = argv[1];
    std::string password = argv[2];
    std::cout<<username<<"  "<<password<<"\n";
    return 0;
}
