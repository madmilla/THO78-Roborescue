#include "map.h"


enum ColorCode{
    Nothing = 0,
    Wall = 1,
    Robot = 2,
    Rosbee = 3
};

struct boxColors{
    QColor wall = Qt::black;
    QColor Nothing = Qt::white;
    QColor Rosbee = Qt::blue;
    QColor Robot = Qt::red;
} boxcolors;

struct toolTips{
    QString Wall = "Wall";
    QString Nothing = "Nothing";
    QString Rosbee = "Rosbee";
    QString Robot = "Robot";
} tooltips;

Map::Map()
{

}

Map::~Map()
{

}

void Map::load(QTableWidget * table){

    QString fileName = QFileDialog::getOpenFileName();
    if (fileName.isEmpty()){
        return;
        std::cout << "Fout" << std::endl;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return;
        std::cout << "Fout" << std::endl;
    }

    std::vector<QStringList> mm;
    QTextStream in(&file);

    while (!in.atEnd()) {
        mm.push_back(in.readLine().split(","));
    }

    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++ ){
            QTableWidgetItem *item = table->item(y, x);
            item->setBackgroundColor(Qt::white);
            int i = mm.at(y).at(x).toInt();

            if(i == 0){
                i = 3;
            }else{
                i--;
            }

            item->setData(Qt::UserRole, QVariant(i));
            changeColor(item);
        }
    }
}

void Map::save(QTableWidget * table){
    QString output;
    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++ ){
            QTableWidgetItem *item = table->item(y, x);
            output.push_back(item->data(Qt::UserRole).toString());
            output.push_back(",");
        }
        output.remove(output.length()-1,1);
        output.append("\n");
    }

    QString fileName = "map.txt";
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }

    QTextStream out(&file);
    out << output;
}

void Map::newMap(QTableWidget * table){
    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++ ){
            if(table->item(y,x) != nullptr)
                table->removeCellWidget(y, x);

            QTableWidgetItem * item = new QTableWidgetItem;

            item->setToolTip("Nothing");
            item->setBackgroundColor(Qt::white);
            item->setData(Qt::UserRole, QVariant(0));
            table->setItem(y, x, item);
        }
    }
}

void Map::changeColor(QTableWidgetItem *item){
    int c = item->data(Qt::UserRole).toInt();

    QColor nextColor;
    QString tp;

    switch(c){
        case ColorCode::Rosbee:
            nextColor = boxcolors.Nothing;
            c = ColorCode::Nothing;
            tp = tooltips.Nothing;
            break;
        case ColorCode::Nothing:
            nextColor = boxcolors.wall;
            c = ColorCode::Wall;
            tp = tooltips.Wall;
            break;
        case ColorCode::Wall:
            nextColor = boxcolors.Robot;
            c = ColorCode::Robot;
            tp = tooltips.Robot;
            break;
        case ColorCode::Robot:
            nextColor = boxcolors.Rosbee;
            c = ColorCode::Rosbee;
            tp = tooltips.Rosbee;
            break;
    }

    item->setBackgroundColor(nextColor);
    item->setToolTip(tp);
    item->setData(Qt::UserRole, QVariant(c));
}

