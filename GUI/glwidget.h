#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
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

//private:

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

};

#endif // GLWIDGET_H
