/**
* __
* _________ / /_ ____ ________ ____________ _____
* /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
* / / / /_/ / /_/ / /_/ / / / __(__ ) /__/ /_/ / __/
* /_/ \____/_.___/\____/_/ \___/____/\___/\__,_/\___/
*
*
* @file mainwindow.h
* @date Created: 06/16/2015
* @brief A class that handles gui actions
*
* @author Jos Bijlenga
*
* @version 4.0
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "composedpolygon.h"
#include "QMouseEvent"
#include "point.h"
#include "storage.h"
#include "polyobject.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <fstream>
#include <iostream>
#include "square.h"
#include <QMessageBox>
#include <limits>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButtonUndo_clicked();
    void on_pushButton_6_clicked();
    void on_listViewObjects_clicked(const QModelIndex &index);
    void on_pushButtonBegin_clicked();
    void on_pushButton_7_clicked();

private:
    // methods

    //! Undo a the previous drawn line
    void undoLine();

    //! Draw a line to point p from lastpoint
    //! @param The point to draw to
    void drawLine(point p);

    //! Add the number of a point to the graphicsview
    //! @param The point to draw the point number
    void addingPoint(QPoint p);

    //! Add text to the listview of the unfinished polygon
    //! @param The text to write to the listview
    void addTextToObjects(QString s);

    //! Draw and add an object
    //! @param The position to draw the object
    //! @param The name of the object
    void drawAddObject(QPoint pos, QString object);

    //! Get the index of the selected item
    //! @param The selected item
    int getSelectedItemIndex(int cur);

    //! Extract the index from a string
    //! @param The string to extract the index from
    //! @return The index extracted from the string
    int extractStringIndex(QString qs);

    //! Delete the selected object
    void deleteSelectedObject();

    QString retrieveSelectedString(int cur);

    // const variables
    const int drawingPanelWidth = 500;
    const int drawingPanelHeight = 500;

    // QT variables
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QPen blackPen;

    QStringListModel *modelPoints;
    QStringList listPoints;

    QStringListModel *modelShapes;
    QStringList listShapes;

    QRect windowSize;

    // objects
    composedPolygon * poly; // the unfinished polygon
    point lastPoint; // last point of polygon shape
    storage * myStorage; // pointer to square and polygon storage

    // variables
    bool modifying; // is a shape being currently modified?
    bool allowDrawing; // are you allowed to draw?

    int pointCount; // amount of points
    int shapeCount; // amount of shapes

    int selectedObject; // the selected object in the listview

    int height, width; // real height of the map
};

#endif // MAINWINDOW_H
