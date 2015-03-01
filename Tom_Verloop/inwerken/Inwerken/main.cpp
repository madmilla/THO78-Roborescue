
#include "mappinglogic.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    MappingLogic mappinglogic;
    if(argc > 1 && std::strcmp("-test",argv[1]) == 0)
    {
        //Test 1
        //setting tiles and saving them
        for(int i = 0;i < 20; i++)
        {
            for(int j = 0;j < 20; j++)
            {
                mappinglogic.set_tile(i,j,2);
            }
        }
        mappinglogic.save_file();
        for(int i = 0;i < 20; i++)
        {
            for(int j = 0;j < 20; j++)
            {
                if(mappinglogic.get_tile(i,j)!= 2)
                {
                    std::cout << "problems in test 1.1";
                    return 1;
                }
            }
        }
        std::cout << "no problems in test 1.1";
        mappinglogic.load_file();
        for(int i = 0;i < 20; i++)
        {
            for(int j = 0;j < 20; j++)
            {
                if(mappinglogic.get_tile(i,j)!= 2)
                {
                    std::cout << "problems in test 1.2";
                    return 1;
                }
            }
        }
        std::cout << "no problems in test 1.2";
        //Test 2
        //clearing tiles and reloading them
        for(int i = 0;i < 20; i++)
        {
            for(int j = 0;j < 20; j++)
            {
                mappinglogic.set_tile(i,j,0);
            }
        }
        mappinglogic.save_file();
        mappinglogic.load_file();
        if(mappinglogic.getTiles().size() > 0)
        {
            std::cout << "problems in test 2.1";
            return 2;
        }
        std::cout << "no problems in test 2.1";
    }
    else
    {
        QApplication a(argc, argv);

        MainWindow w(&mappinglogic);
        w.show();
        return a.exec();
    }
}
