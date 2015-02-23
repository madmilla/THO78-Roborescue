#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include "map.h"
#include "maptester.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 *
 * Constructor
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup ui
    ui->setupUi(this);

    // Add map widget
    mapWidget = new MapWidget(parent);
    ui->verticalLayout->addWidget(mapWidget);

    // Add menu listeners
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(actionNew()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(actionLoad()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(actionSaveAs()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(actionExit()));
}

/**
 * @brief MainWindow::~MainWindow
 *
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::actionNew
 *
 * Menu->File->New pressed.
 */
void MainWindow::actionNew()
{
    newMap();
}

/**
 * @brief MainWindow::newMap
 *
 * Create new map.
 */
void MainWindow::newMap()
{
    map = new Map(20, 20);
    mapWidget->setMap(*map);
    currentFileName.clear();
}

/**
 * @brief MainWindow::actionLoad
 *
 * Menu->File->Load pressed.
 */
void MainWindow::actionLoad()
{
    loadFile();
}

/**
 * @brief MainWindow::loadFile
 *
 * Load file with open file dialog.
 */
void MainWindow::loadFile()
{
    //
    currentFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.mapdata)"));
    loadFile(currentFileName);
}

/**
 * @brief MainWindow::loadFile
 * @param fileName
 *
 * Load file using fileName
 */
void MainWindow::loadFile(const QString &fileName)
{
    if(fileName.length() == 0)
        return;

    map = new Map(fileName);
    if(map->getWidth()== 0 || map->getHeight() == 0) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error opening file.", "File corrupted.");
        messageBox.setFixedSize(500,200);
        return;
    }

    // Add map to widget
    mapWidget->setMap(*map);

    // Update window title
    setWindowTitle("Map Reader - " + fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1));
}

/**
 * @brief MainWindow::actionSave
 *
 * Menu->File->Save pressed.
 */
void MainWindow::actionSave()
{
    save();
}

/**
 * @brief MainWindow::actionSaveAs
 *
 * Menu->File->Save As...
 */
void MainWindow::actionSaveAs()
{
    saveFile();
}

/**
 * @brief MainWindow::save
 *
 * If file is known, save;
 * Else use save file dialog.
 */
void MainWindow::save()
{
    if(currentFileName == NULL || currentFileName.length() == 0)
        saveFile();
    else
        saveFile(currentFileName);
}

/**
 * @brief MainWindow::saveFile
 *
 * TODO!!
 * Save current file with save file dialog.
 */
void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("Files (*.mapdata);;All Files (*)"));

    if(fileName == NULL || fileName.length() == 0)
        return;

    saveFile(fileName);
}

/**
 * @brief MainWindow::saveFile
 * @param fileName
 *
 * Save file using fileName.
 */
void MainWindow::saveFile(const QString &fileName)
{
    if(map == NULL)
        return;

    map->save(fileName);
    currentFileName = fileName;
}

/**
 * @brief MainWindow::actionExit
 *
 * Menu->File->Exit pressed.
 */
void MainWindow::actionExit()
{
    exitProgram();
}

/**
 * @brief MainWindow::exitProgram
 *
 * Exit the program.
 */
void MainWindow::exitProgram()
{
    exit(0);
}
