/// @file Window.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "Window.hpp"
#include "Widget.hpp"
#include "MapUi.hpp"
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QSignalMapper>
#include <QFileDialog>

Window::Window(QWidget *parent):
    QMainWindow{parent},
    widget{this},
    menuBar{this},
    fileMenu{"File",this},
    fileMenuNew{"New",this},
    fileMenuOpen{"Open...", this},
    fileMenuSave{"Save", this},
    fileMenuSaveAs{"Save As...", this},
    fileMenuExport{"Export...",this},
    fileMenuExit{"Exit", this},

    editMenu{"Edit",this},
    editMenuGrid{"Grid",this},
    editMenuSizeMenu{"Size",this},
    editMenuSizeMenu10{"10x10",this},
    editMenuSizeMenu20{"20x20",this},
    editMenuSizeMenu40{"40x40",this},
    editMenuSizeMenu80{"80x80",this},
    editMenuMerge{"Merge...", this}

{
    //Add the menu bar to the window.
    setMenuBar(&menuBar);
    //Add file menu to the menu bar.
    menuBar.addMenu(&fileMenu);
    //Add the new action to the file menu.
    fileMenu.addAction(&fileMenuNew);
    //Add shortcut Ctrl-N to the new action.
    fileMenuNew.setShortcut(QKeySequence::New);
    //Link the new action to the newf function.
    connect(&fileMenuNew, SIGNAL(triggered()), this, SLOT(newf()));

    //All code below is adding menus and actions and then linking them
    //in the exact same way as documented above.

    fileMenu.addAction(&fileMenuOpen);
    fileMenuOpen.setShortcut(QKeySequence::Open);
    connect(&fileMenuOpen, SIGNAL(triggered()), this, SLOT(open()));
    fileMenu.addAction(&fileMenuSave);
    fileMenuSave.setShortcut(QKeySequence::Save);
    connect(&fileMenuSave, SIGNAL(triggered()), this, SLOT(save()));
    fileMenu.addAction(&fileMenuSaveAs);
    fileMenuSaveAs.setShortcut(QKeySequence::SaveAs);
    connect(&fileMenuSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));
    fileMenu.addAction(&fileMenuExport);
    connect(&fileMenuExport, SIGNAL(triggered()), this, SLOT(exportf()));
    fileMenu.addAction(&fileMenuExit);
    fileMenuExit.setShortcut(QKeySequence::Quit);
    connect(&fileMenuExit, SIGNAL(triggered()), this, SLOT(exit()));

    menuBar.addMenu(&editMenu);
    editMenu.addAction(&editMenuGrid);
    connect(&editMenuGrid, SIGNAL(triggered()), this, SLOT(grid()));
    editMenu.addMenu(&editMenuSizeMenu);
    editMenuSizeMenu.addAction(&editMenuSizeMenu10);
    editMenuSizeMenu.addAction(&editMenuSizeMenu20);
    editMenuSizeMenu.addAction(&editMenuSizeMenu40);
    editMenuSizeMenu.addAction(&editMenuSizeMenu80);

    //The signal mapper is used if you wish to call action slots using a parameter.
    QSignalMapper* mapper = new QSignalMapper(this);

    //This will map the 10x10 action to the integer value of 10.
    mapper->setMapping(&editMenuSizeMenu10, 10);
    //This will map the 20x20 action to the integer value of 20.
    mapper->setMapping(&editMenuSizeMenu20, 20);
    //Well, you get it...
    mapper->setMapping(&editMenuSizeMenu40, 40);
    mapper->setMapping(&editMenuSizeMenu80, 80);

    //Instead of linking the action directly to a slot, we now
    //link the action to the signal mapper.
    connect(&editMenuSizeMenu10, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(&editMenuSizeMenu20, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(&editMenuSizeMenu40, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(&editMenuSizeMenu80, SIGNAL(triggered()), mapper, SLOT(map()));

    //Last but not least we link the signal mapper to the actual function we
    //wish to call.
    //The signal mapper will then in turn fill in the function parameter with
    //the above mapped parameter.
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(resize(int)));
    //In hindsight was it probably a lot easier and less time consuming to just
    //write 4 separate slot functions.

    //Add the merge action to the edit menu (the normal way).
    editMenu.addAction(&editMenuMerge);
    connect(&editMenuMerge, SIGNAL(triggered()), this, SLOT(merge()));

    //Add the widget to the window.
    //Widget is added in the center.
    setCentralWidget(&widget);
    //Create a new widget size.
    //The size needs to be 1 pixel larger than the actual size you wish it to be.
    //This is because Qt thinks it's fun to draw the window over the widget hiding
    //the last row and column of pixel
    QSize size{481,481};
    //Set the widget to a fixed size so we can't change it.
    widget.setFixedSize(size);
    //Add the map as a drawable.
    widget.addDrawable(&map);
    //Add the map as a mouse listener.
    widget.addMouseListener(&map);

    //Set a window title.
    setWindowTitle("Map");
    //Make window a fixed size.
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //Set the message box icon.
    errorBox.setIcon(QMessageBox::Icon::Warning);
    //Set the message box buttons.
    //There is only a OK button since we dont have any error handelig.
    errorBox.setStandardButtons(QMessageBox::Ok);
    //Set the message box title.
    errorBox.setWindowTitle("Unable to load file!");

}


void Window::newf(){
    //Remove the current loaded file name.
    fileName.clear();
    //Check if there is a currently no map loaded.
    if(map.getDiameter() <= 0){
        //Default new map size.
        int defaultStartSize = 20;
        //Resize the map.
        map.resize(defaultStartSize);
        //Scale the new map size to fit in the window.
        map.fitInWindow(widget.size());
    }
    //Clear the map.
    map.clear();
    //Draw the new map on screen.
    widget.update();
    //Change the window title to indicate we're working on a new map.
    this->setWindowTitle("Map - new");
}

void Window::open(){
    //Create and show a file dialog that asks for a file.
    //The returned string is the absolute path to the file.
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Map (*.map) ;; Files (*.*)"));
    //Check if the returned string is empty.
    //This happens if the user decides to abort the file search.
    if(!file.isEmpty()){
        try{
            //Try to load map.
            //This will throw an exception if it somehow fails.
            map.load(file.toStdString());
            //Scale the loaded map to fit in the window.
            map.fitInWindow(widget.size());
            //Update the widget so we can see the loaded map
            widget.update();
            //Update the currently loaded file name to the new name.
            fileName = file;

        }
        catch(MapLoadException e){
            //Set the text for the message box.
            //The reason for the exception may differ so we need to update it
            //every time a exception is thrown.
            errorBox.setText(tr("Unable to load file: ") + e.what() );
            //Pop up the message box.
            errorBox.exec();
            //Clear the file name.
            //This is to indicate that the load did not complete correctly.
            fileName.clear();
        }
        //Split the file name.
        //The fileName contains the absolute path to the file.
        //While we're are only interested in showing only the actual name of the file.
        QStringList list = fileName.split("/");
        //Show the last last member of the list in the window title.
        //This enable to user to see which file is currently loaded.
        setWindowTitle("Map - " + list.at(list.size()-1));
    }
}

void Window::exit(){
    //Close the window, this will end the application.
    close();
}

void Window::exportf(){
    //Create and show a file dialog that asks for a name and place to save a file.
    //The returned string is the absolute path to the file.
    QString file = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("PNG (*.png)"));
    //Check if the returned string is empty.
    //This happens if the user decides to abort the file search.
    if(!file.isEmpty()){
        //Save the map as a image.
        //RGB32 is acceptable as PNG image.
        //If the file already exists it will be overwritten.
        //If the file did not already exists a new one will be created.
        map.saveAsImage(file.toStdString(),QImage::Format_RGB32);
    }
}

void Window::save(){
    //Check if the filename is set.
    //If so it means that that is the current loaded file and we can
    //save any changes to that file.
    if(fileName.isEmpty()){
       //If not call the saveAs function to fetch a new filename.
       saveAs();
    }
    //Save the map using the filename.
    //If the file already exists it will be overwritten.
    //If the file did not already exists a new one will be created.
    map.save(fileName.toStdString());
}

void Window::saveAs(){
    //Create and show a file dialog that asks for a name and place to save a file.
    //The returned string is the absolute path to the file.
    QString file = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("Map (*.map) ;; Files (*.*)"));
    //Check if the returned string is empty.
    //This happens if the user decides to abort the file search.
    if(!file.isEmpty()){
        //Save the new file name.
        //If a file i saved the the current loaded files becomes the new saved file.
        //This is to avoid accidentally overwriting the original file.
        fileName = file;
        //Save the map to file.
        map.save(fileName.toStdString());
        //Parse the new filename.
        QStringList list = fileName.split("/");
        //Set the new filename in the window title.
        setWindowTitle("Map - " + list.at(list.size()-1));
    }
}

void Window::grid(){
    //Invert the bool, this is to create a toggle effect.
    //Toggel the map grid.
    map.showGrid(!map.isGridShown());
}

void Window::resize(int size){
    //Check if there is no map loaded.
    //Cannot resize if no map is loaded.
    if(fileName.isEmpty()){
        //Load a new map.
        newf();
    }
    //Resize the map to new size.
    map.resize(size);
    //Make the new size fit in window.
    map.fitInWindow(widget.size());
    //Update the window so we can see the new size.
    widget.update();
}

void Window::merge(){
    //Create and show a file dialog that asks for a name of a file to merge with the
    //current file.
    //The returned string is the absolute path to the file.
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Map (*.map) ;; Files (*.*)"));
    //Check if the returned string is empty.
    //This happens if the user decides to abort the file search.
    if(!file.isEmpty()){
        //Create a new temporary map.
        MapUi tmpMap;
        try{
           //Load the map for file.
           //If this fails will throw an exception.
           tmpMap.load(file.toStdString());
           //Merge the temporary map with the current map.
           map.merge(tmpMap);
           //Incase the temporary map was bigger the the current map.
           //The current map was resized.
           //So we have to rescale the map again to make it fit in the window.
           map.fitInWindow(widget.size());
           //Update the widget so we can see the new merged map.
           widget.update();

        }
        catch(MapLoadException e){
            //Set the text for the message box.
            //The reason for the exception may differ so we need to update it
            //every time a exception is thrown.
            errorBox.setText(tr("Unable to load file: ") + e.what() );
            //Pop up the message box.
            errorBox.exec();
        }
    }
}






