//code van http://www.bogotobogo.com/Qt/Qt5_OpenGL_QGLWidget.php
#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QGLWidget>

class openGLWidget : public QGLWidget
{
public:
    openGLWidget();
    ~openGLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
private:
     void draw();
     int xRot;
     int yRot;
     int zRot;
     QPoint lastPos;
};

#endif // OPENGLWIDGET_H
