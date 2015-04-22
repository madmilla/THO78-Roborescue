#include <cstdlib>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
using namespace sql;
using namespace std;
int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "no password specified\nUsage: " << argv[0] <<" [-y] (password)]\n";
        return 0;
    }
    if(std::string(argv[1]) != "-y"){
        cout <<"\033[41m\033[4mThis program stops the mysql database service. Are you sure you want to continue?\033[24m\033[49m\nY if you are sure , N to stop execution \n-run with -y option to always continue-\n-----------------------------------------------\n\033[42mThis program is meant to be executed on the same server as the database server is running on,\n the port of the database server needs to be 3306 \nand the user name needs to be root.\nYou'll also need access to the root priveleges\033[49m\n-----------------------------------------------\n";
        string answer;
        cin >> answer;
        if(answer != "Y"){
            return 0;
        }
    }
    string password = (argc > 2 ? argv[2] : argv[1]);
    bool stopped=false;
    try{
        cout<<"database connection opening\n";
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", password);
        /* Connect to the MySQL test database */
        con->setSchema("test");
        stmt = con->createStatement();
        int i = system("sudo service mysql stop");
        stopped=true;
        stmt->execute("SELECT * FROM test");
        delete stmt;
        delete con;
    }
    catch(exception &e){
        cout<<"error: " << e.what() <<"\nexception catched succefull\n";
    }
    if(stopped){
        int i = system("sudo service mysql start");
    }
    return 0;
}
