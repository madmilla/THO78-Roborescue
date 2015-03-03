#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class MapDisplayWidget;
class Map;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /*!
     * String to hold the filename of the currently open file.
     * When this string is empty the currently open file, if any,
     * has yet to be saved.
     */
    QString filename;

    /*!
     * Pointer to a custom QTableWidget used to display the currently loaded
     * map, if any.
     */
    MapDisplayWidget* display;

    /*!
     * Pointer to the currently displayed map, if any.
     */
    Map *currentMap;

    /*!
     * Boolean to hold whether or not the currently displayed map
     * has been saved.
     */
    bool saved;

    /*!
     * \brief Connect signals to their designated slots.
     */
    void connectSignals();

    /*!
     * \brief Method to save or discard the recent changes to the current map.
     *
     * When called this method opens a DiscardDialog to ask whether the current
     * changes should be saved or discarded.
     */
    void saveOrDiscardChanges();

    /*!
     * \brief Saves the current map to the file specified in filename.
     */
    void saveMapFile();

    /*!
     * \brief Loads the current map from the file specified in filename.
     */
    void loadMapFile();

private slots:

    /*!
     * \brief Method to be called when the 'New' signal has been emitted.
     */
    void newActionTriggered();

    /*!
     * \brief Method to be called when the 'Open' signal has been emitted.
     */
    void openActionTriggered();

    /*!
     * \brief Method to be called when the 'Save' signal has been emitted.
     */
    void saveActionTriggered();

    /*!
     * \brief Method to be called when the 'SaveAs' signal has been emitted.
     */
    void saveAsActionTriggered();
};

#endif // MAINWINDOW_H
