#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modifying = false;
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    blackPen = QPen(Qt::black);
    blackPen.setWidth(2);

    myStorage = new storage();
    modelPoints = new QStringListModel();
    modelShapes = new QStringListModel();

    windowSize = QRect(10,10,500,500);

    shapeCount = 0;
    selectedObject = -1;
    allowDrawing = false;

    ui->graphicsView->setEnabled(false);
}

// destructor
MainWindow::~MainWindow()
{
    delete myStorage;
    delete modelPoints;
    delete modelShapes;
    delete scene;
    delete poly;
    delete ui;
}

// add a point to drawing panel
void MainWindow::addingPoint(QPoint p){
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(p);
    io->setPlainText(QString::number(pointCount));
    io->setData(0, pointCount);

    scene->addItem(io);
    QString tmp =
            QString::number(pointCount) + ": " + "(" +
            QString::number((int)(p.x() * width / drawingPanelWidth)) + ", " +
            QString::number((int)(p.y() * height / drawingPanelHeight)) + ")";
    listPoints << tmp;
    ++pointCount;

    modelPoints->setStringList(listPoints);
    ui->listViewPoints->setModel(modelPoints);
}

// clicked on drawing panel
void MainWindow::mousePressEvent(QMouseEvent * event){
    if(allowDrawing){
        if (event->button() == Qt::LeftButton) {
            if(windowSize.contains(event->pos())){
                if(ui->radioButtonShape->isChecked()){
                    if(!modifying){
                        pointCount = 0;
                        listPoints.clear();

                        point tmp = point(event->pos().x(), event->pos().y());
                        lastPoint = tmp;
                        poly = new composedPolygon(tmp);
                        modifying = true;
                        addingPoint(event->pos());
                    }
                    else{
                        if(poly != nullptr){
                            point tmp = point(event->pos().x(), event->pos().y());
                            if(pointCount > 0){
                                drawLine(tmp);
                            }
                            lastPoint = tmp;
                            poly->nextPoint(tmp);
                            addingPoint(event->pos());
                        }
                    }
                }
                else if(ui->radioButtonQR->isChecked()){
                    drawAddObject(event->pos(), QString("QR"));
                }
                else if(ui->radioButtonRos->isChecked()){
                    drawAddObject(event->pos(), QString("Rosbee"));
                }
                else if(ui->radioButtonATV->isChecked()){
                    drawAddObject(event->pos(), QString("ATV"));
                }
                else{
                    drawAddObject(event->pos(), QString("QuadCopter"));
                }
            }
        }
    }
}

// drawing a line
void MainWindow::drawLine(point p){
    QGraphicsLineItem * io = new QGraphicsLineItem;
    io->setLine(lastPoint.getX(),
                lastPoint.getY(),
                p.getX(),
                p.getY());
    io->setPen(blackPen);
    io->setData(0, pointCount);

    scene->addItem(io);
}

// drawing an object at position with set width and height of the object
// and adding it to the storage
void MainWindow::drawAddObject(QPoint pos, QString object){
    QGraphicsRectItem * obj = new QGraphicsRectItem;
    //obj->setPos(pos->getX(), pos->getY());
    obj->setData(0, shapeCount);
    obj->setData(1, object);

    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(pos);
    io->setPlainText(object);
    io->setData(0, shapeCount);
    io->setData(1, object);

    QString tmp;
    tmp.append(QString::number(shapeCount));

    point p;
    int xB = (int)(pos.x() * width / drawingPanelWidth);
    int yB = (int)(pos.y() * height / drawingPanelHeight);
    int w, h;
    char t;

    if(object == "QR"){
        w = 100*drawingPanelWidth/width;
        h = 100*drawingPanelHeight/height;
        p = point(xB, yB);
        t = 'q';

        tmp.append(": QR [(");
    }
    else if(object == "Rosbee"){
        w = 350*drawingPanelWidth/width;
        h = 390*drawingPanelHeight/height;
        p = point(xB, yB);
        t = 'r';

        tmp.append(": Rosbee [(");
    }
    else if(object == "ATV"){
        w = 250*drawingPanelWidth/width;
        h = 400*drawingPanelHeight/height;
        p = point(xB, yB);
        t = 'a';

        tmp.append(": ATV [(");
    }
    else{
        // quadcopter
        w = 360*drawingPanelWidth/width;
        h = 360*drawingPanelHeight/height;
        p = point(xB, yB);
        t = 'c';

        tmp.append(": QuadCopter [(");
    }

    myStorage->addObject(p, w, h, t);
    obj->setRect(pos.x(), pos.y(), w, h);

    tmp.append(QString::number((int)(pos.x() * width / drawingPanelWidth)));
    tmp.append(", ");
    tmp.append(QString::number((int)(pos.y() * height / drawingPanelHeight)));
    tmp.append("), " + QString::number(w) + ", " + QString::number(h) + ", ");
    tmp.append(QString(QChar(t)) + ")]");
    addTextToObjects(tmp);

    scene->addItem(obj);
    scene->addItem(io);
    ++shapeCount;
}

// apply the shape button :: shape gets added to storage->add
void MainWindow::on_pushButton_clicked()
{
    modifying = false;
    pointCount = 0;
    polyObject tmp = polyObject(poly->applyPolygon());
    myStorage->addPolyObject(tmp);
    point p = tmp.getShape().back();

    scene->addLine(lastPoint.getX(),
                   lastPoint.getY(),
                   p.getX(),
                   p.getY(),
                   blackPen
                   );

    QString str;
    str.append(QString::number(shapeCount) + ": [");

    for(unsigned int i = 0; i < tmp.getShape().size()-1; i++){
        str.append("(");
        str.append(QString::number((int)(tmp.getShape().at(i).getX() * width / drawingPanelWidth)));
        str.append(", ");
        str.append(QString::number((int)(tmp.getShape().at(i).getY() * height / drawingPanelHeight)));
        str.append("), ");
    }

    int end = tmp.getShape().size()-1;
    str.append("(");
    str.append(QString::number((int)(tmp.getShape().at(end).getX() * width / drawingPanelWidth)));
    str.append(", ");
    str.append(QString::number((int)(tmp.getShape().at(end).getY() * height / drawingPanelHeight)));
    str.append(")]");

    addTextToObjects(str);
    ++shapeCount;
}

// add text to listview in gui
void MainWindow::addTextToObjects(QString s){
    listShapes << s;

    modelShapes->setStringList(listShapes);
    ui->listViewObjects->setModel(modelShapes);
}

// undo whole shape button
void MainWindow::on_pushButton_2_clicked()
{
    while(pointCount > 0){
        undoLine();
    }
    modifying = false;
    pointCount = 0;
}

// undo one line and number
void MainWindow::undoLine(){
    if(pointCount > 0){
        QList<QGraphicsItem *> tmp = scene->items();
        std::vector<int> indices;
        int delItems = 2;
        int items = 0;

        if(tmp.size() < 2){
            delItems = 1;
        }

        for(int i = 0; i < tmp.size(); i++){
            if(tmp.at(i)->data(0) == pointCount-1){
                indices.push_back(i);
                ++items;
            }
            if(items >= delItems){
                break;
            }
        }
        for(unsigned int i = 0; i < indices.size(); i++){
            scene->removeItem(tmp.at(indices.at(i)));
        }
        listPoints.removeLast();
        modelPoints->setStringList(listPoints);

        --pointCount;

        QList<QGraphicsItem *> latestTmp = scene->items();
        for(int i = 0; i < latestTmp.size(); i++){
           if(latestTmp.at(i)->data(0) == pointCount-1){
               //std::cout << "Found the point: " << latestTmp.at(i)->pos().x() << ", " << latestTmp.at(i)->pos().y() << std::endl;
               lastPoint = point(latestTmp.at(i)->pos().x(), latestTmp.at(i)->pos().y());
               if(!lastPoint.equals(point(0, 0))){
                   break;
               }
           }
        }
    }
}

// undo one line and number button
void MainWindow::on_pushButtonUndo_clicked()
{
    // go one step back (line and numer)
    undoLine();
}

// write to text file button
void MainWindow::on_pushButton_6_clicked()
{
    std::ofstream mapFile;
    mapFile.open("map.map");

    std::vector<square> objects = myStorage->getObjects();
    std::vector<polyObject> polyObjects = myStorage->getPolyObjects();

    for(square & sq : objects){
        mapFile << sq.getType() << "(" << sq.getStart().getX();
        mapFile << ", " << sq.getStart().getY() << ", " << sq.getHeight();
        mapFile << ", " << sq.getWidth() << ")\n";
    }

    for(polyObject & po : polyObjects){
        std::vector<point> tmp = po.getShape();
        for(unsigned int i = 0; i < tmp.size() - 1; i++){
            mapFile << "l(" << tmp[i].getX() << ", " << tmp[i].getY();
            mapFile << ", " << tmp[i+1].getX() << ", " << tmp[i+1].getY();
            mapFile << ")\n";
        }
    }

    mapFile.close();

    QMessageBox Msgbox;
    Msgbox.setText("File has been written");
    Msgbox.exec();
}

// set the selected object
void MainWindow::on_listViewObjects_clicked(const QModelIndex &index)
{
    (void)index;
    QString s = ui->listViewObjects->currentIndex().data().toString();
    s = s.left(s.indexOf(':'));
    selectedObject = getSelectedItemIndex(s.toInt());
}

// get index from selected item
int MainWindow::getSelectedItemIndex(int cur){
    QAbstractItemModel* model = ui->listViewObjects->model();
    for(int i = 0; i < model->rowCount(); ++i){
        if(extractStringIndex(model->index(i, 0).data().toString()) == cur){
            return i;
        }
    }
    return -1; // not found
}

// extract index from string
int MainWindow::extractStringIndex(QString qs){
    QString s = qs;
    s = s.left(s.indexOf(':'));
    return s.toInt();
}

QString MainWindow::retrieveSelectedString(int cur){
    QAbstractItemModel* model = ui->listViewObjects->model();
    for(int i = 0; i < model->rowCount(); ++i){
        if(extractStringIndex(model->index(i, 0).data().toString()) == cur){
            return model->index(i, 0).data().toString();
        }
    }
    return "";
}

// function below deletes the object from the GUI and storage.
void MainWindow::deleteSelectedObject(){
    if(selectedObject != -1 && shapeCount > 0){
        QList<QGraphicsItem *> tmp = scene->items();
        std::vector<int> indices;

        for(int i = 0; i < tmp.size(); i++){
            if(tmp.at(i)->data(0) == selectedObject){
                indices.push_back(i);
            }
        }
        for(unsigned int i = 0; i < indices.size(); i++){
            scene->removeItem(tmp.at(indices.at(i)));
        }

        QString objectData = retrieveSelectedString(selectedObject);

        --shapeCount;

        listShapes.removeAt(selectedObject);
        modelShapes->setStringList(listShapes);

        if(objectData == "") return;
        // format = <index>: [(<point>), <width>, <height>, <type>)]s
        // 0: QR [(710, 970), 10, 10, q)]

        QStringList tmpLi = objectData.split(' ');
        QString name = tmpLi[1]; // xxxxxxxx
        QString pointX = tmpLi[2]; // [(xxx,
        QString pointY = tmpLi[3]; // xxx),
        QString rWidth = tmpLi[4]; // xx,
        QString rHeight = tmpLi[5]; // xx,
        QString rType = tmpLi[6]; // x)]

        name = name.mid(0, name.indexOf(','));
        pointX = pointX.mid(2, pointX.indexOf(',')-2);
        pointY = pointY.mid(0, pointY.length()-2);
        rWidth = rWidth.mid(0, rWidth.length()-1);
        rHeight = rHeight.mid(0, rHeight.length()-1);

        int px = pointX.toInt();
        int py = pointY.toInt();
        int rw = rWidth.toInt();
        int rh = rHeight.toInt();

        if(name == "QR"){
            myStorage->deleteObject(point(px, py), rw, rh, 'q');
        }
        else if(name == "ATV"){
            myStorage->deleteObject(point(px, py), rw, rh, 'a');
        }
        else if(name == "Rosbee"){
            myStorage->deleteObject(point(px, py), rw, rh, 'r');
        }
        else{
            //quadcopter
            myStorage->deleteObject(point(px, py), rw, rh, 'c');
        }
    }
}

// begin button enabling drawing on panel
void MainWindow::on_pushButtonBegin_clicked()
{
    try{
        height = ui->plainTextEditHeight->toPlainText().toInt();
        width = ui->plainTextEditWidth->toPlainText().toInt();

        if(
            ((height > 999) && (width > 999)) &&
            (height < std::numeric_limits<int>::max()
             && width < std::numeric_limits<int>::max())
           ){
            allowDrawing = true;
            ui->frame_3->setEnabled(false);
            ui->graphicsView->setEnabled(true);
        }
    }
    catch(std::exception){
        std::cout << "Invalid values\n";
    }
}

// delete object button
void MainWindow::on_pushButton_7_clicked()
{
    deleteSelectedObject();
}
