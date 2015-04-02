#ifndef GRIDLABEL_H
#define GRIDLABEL_H

#include <QLabel>
#include <QPixmap>


class Gridlabel : public QLabel
{

public:
    Gridlabel(QWidget *parent);

    Qt::GlobalColor convertColor(int code);
    void setColor(int colorCode);

private:
    static const int height = 30;
    static const int width = 30;
    QPixmap qpix = QPixmap(height,width);
};

#endif // GRIDLABEL_H
