#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "atv.h"
#include "Listener.h"

namespace Ui {
class ATVWindow;
}

/**
* @class  ATVWindow
* @author Wibren Wiersma (wibrenwiersma@hotmail.com)
* @date   April, 2015
* @brief  this class handles ui input from the ATVWindow
*/
class ATVWindow : public QMainWindow, public Listener
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

private:
   ATV & atv;
   Ui::ATVWindow *ui;

   void notifyListener(Subject&, StatusText statusText) override;
};

#endif // ATVWINDOW_H
