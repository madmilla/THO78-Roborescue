#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>
#include "line.h"
#include "algorithms.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:

    // Draws a 3D green square at the bottom of the OpenGL widget
    void drawGround();
    // Draws an isometric green square at the bottom of the OpenGL widget
    void drawGroundIso();

    // Draws a single line in 3D on top of the ground drawn by drawGround.
    // Since the line (x1, y1, x2, y2) has no height, a default constant height
    void drawLine(const Line<float> &line);
    // Draws a vector of lines in 3D
    void drawLines(const std::vector<Line<float> > linesNormalized);

    // Draws a single line isometric on top the ground drawn by drawGroundIso
    // Since the line (x1, x2, y1, y2) has no height, a default constant height is used.
    // The x and y values of the line should already be normalized between MIN_X(-1) and MAX_X(1)
    // by the Algorithm::normalizeLines function
    void drawLineIso(const Line<float> &lineIso);
    // Draws a vector of lines in 2.5D (isometric)
    void drawLinesIso(const std::vector<Line<float> > linesNormalizedIso);

    // Draws the ground and a vector of lines in 3D.
    // Before the lines are drawn, they will be normalized within this function
    void setLines(const std::vector<Line<int> > lines);
    // Draws the ground and a vector of lines isometricly.
    // Before the lines are drawn, they will be normalized within this function
    void setLinesIso(const std::vector<Line<int> > linesIso);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

    constexpr static const float X_ROTATE_DEFAULT = 45.0;
    constexpr static const float Y_ROTATE_DEFAULT = 45.0;
    constexpr static const float Z_ROTATE_DEFAULT = 0.0;

    float xRotate;
    float yRotate;
    float zRotate;

    constexpr static const float MIN_ZOOM = -8.0f;
    constexpr static const float MAX_ZOOM = -4.0f;
    float zPan;
    float xPan;
    float yPan;

    int zLevel;

    QPoint lastPos;


public slots:
    // Rotate the GLWidget around the X axis
    void rotateX(int angle);
    // Rotate the GLWidget around the Y axis
    void rotateY(int angle);
    // Rotate the GLWidget around the Z axis
    void rotateZ(int angle);

    void panLeft();
    void panRight();
    void panUp();
    void panDown();

    // Zoom
    void zoom(int zoomLevel);


signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

    void zoomChanged(int zoomLevel);
};

#endif // GLWIDGET_H
