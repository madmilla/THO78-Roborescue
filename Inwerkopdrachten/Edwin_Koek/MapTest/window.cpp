/// @file window.cpp
/// @author Edwin Koek
/// @version 1.0

#include <QLayout>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <iostream>
#include <QInputEvent>
#include <QInputDialog>

#include "window.h"



Window::Window(Grid& grid):
  m_boxLayout(new QVBoxLayout(this)),
  m_menuBar(new QMenuBar()),
  m_fileMenu(new QMenu("File")),
  m_new(new QAction{"New",nullptr}),
  m_save(new QAction{"Save",nullptr}),
  m_load(new QAction{"Load",nullptr}),
  m_exit(new QAction{"Exit",nullptr}),
  m_grid(grid)
{
    this->setMouseTracking(true);
    this->resize(QSize(800,600));
    m_menuBar->addMenu(m_fileMenu);
    connect(m_new,&QAction::triggered,this, &Window::create);
    connect(m_save,&QAction::triggered,this, &Window::save);
    connect(m_load,&QAction::triggered,this, &Window::load);
    connect(m_exit,&QAction::triggered,this, &Window::close);
    m_fileMenu->addAction(m_new);
    m_fileMenu->addAction(m_save);
    m_fileMenu->addAction(m_load);
    m_fileMenu->addAction(m_exit);

    this->layout()->setMenuBar(m_menuBar);
}

void Window::load(){
    QString path = QFileDialog::getOpenFileName(0,"Select map","",
                                                "Images (*.png *.xpm *.jpg)");
    m_grid.load(path);
}

void Window::create(){
    float x = static_cast<float>(QInputDialog::getInt(this,"Grid width","Width:"));
    float y = static_cast<float>(QInputDialog::getInt(this,"Grid height","Height:"));
    QVector2D newSize(x,y);
    m_grid.newCleanGrid(newSize);
    update();
}

void Window::save(){
    QString path = QFileDialog::getSaveFileName(0,"Save map","",
                                                "Images (*.png *.xpm *.jpg)");
    m_grid.save(path);
}

void Window::paintEvent(QPaintEvent *){
    QPainter painter(this);
    m_grid.draw(painter);
}

void Window::mousePressEvent(QMouseEvent * mouseEvent){
    cout << mouseEvent->x() <<  ',' << mouseEvent->y() << endl;
    Tile* tile = m_grid.tileAt({static_cast<float>(mouseEvent->x()),
                                static_cast<float>(mouseEvent->y())});
    if (tile) {
        m_grid.selectTile(tile);
        update();
    }
}

void Window::mouseMoveEvent(QMouseEvent * mouseEvent){
    m_menuBar->setVisible(mouseEvent->y() < 8);
}

void Window::keyPressEvent(QKeyEvent * keyEvent){
    if(keyEvent->key() == Qt::Key::Key_0 ){
        m_grid.colorTile(m_grid.typeToColor(TileType::Undefined));
        update();
    }else if(keyEvent->key() == Qt::Key::Key_1){
        m_grid.colorTile(m_grid.typeToColor(TileType::Walkable));
        update();
    }else if(keyEvent->key() == Qt::Key::Key_2){
        m_grid.colorTile(m_grid.typeToColor(TileType::Blocked));
        update();
    }else if(keyEvent->key() == Qt::Key::Key_3){
        m_grid.colorTile(m_grid.typeToColor(TileType::Dangerous));
        update();
    }else if(keyEvent->key() == Qt::Key::Key_4){
        m_grid.colorTile(m_grid.typeToColor(TileType::Object));
        update();
    }else if(keyEvent->key() == Qt::Key::Key_S){
        m_grid.setStartTile();
        update();
    }
}

