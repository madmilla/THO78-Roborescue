#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

class Display : public QWidget
{
   Q_OBJECT
public:
   explicit Display(QWidget *parent = 0);
   ~Display();

signals:

public slots:

protected:
   void paintEvent(QPaintEvent *);
};

#endif // DISPLAY_H
