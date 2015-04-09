#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "atv.h"

namespace Ui {
class ATVWindow;
}

/**
* @class  ATVWindow
* @author Wibren Wiersma (wibrenwiersma@hotmail.com)
* @date   April, 2015
* @brief  this class handles ui input from the ATVWindow
*/
class ATVWindow : public QMainWindow
{
    Q_OBJECT

public:
   /**
   *  Construts an ATVWindow
   *	@param atv pointer to the ATV object that needs to be controlled / displayed
   *  @param parent use this param if this is a sub window of some QWidget
   */
   explicit ATVWindow(ATV & atv, QWidget *parent = 0);
   /**
   * Deconstructs the atv window
   */
   ~ATVWindow();

private slots:
   void handleButton();

   void scrollbarValueChanged(int value);

   void timerTick();

   void armed(bool is_armed);

private:
   ATV & atv;
   QTimer timer;
   Ui::ATVWindow *ui;
};

#endif // ATVWINDOW_H
