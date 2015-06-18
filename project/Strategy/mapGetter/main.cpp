#include <QCoreApplication>
#include <iostream>
#include <vector>



#define times 100000

int main(int argc, char *argv[])
{
    std::cout << "fuck dem bitches";
    QCoreApplication a(argc, argv);
//    std::vector<std::vector<point> > points;
//    try{
//        databaseConnector dbc("127.0.0.1","roborescue","robodata","robodata");
//        dbc.setMap(1);
//        points = dbc.getPolygons();

//    }catch(std::exception &e){
//        std::cout << e.what();
//    }
//    map m{};

    return a.exec();
}
