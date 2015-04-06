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
    //void drawCube(int x, int y);
    void drawGround();
    void drawGroundIso();

    void drawLine(const Line<float> &line);
    void drawLines(const std::vector<Line<float> > linesNormalized);

    void drawLineIso(const Line<float> &lineIso);
    void drawLinesIso(const std::vector<Line<float> > linesNormalizedIso);

    void setLines(const std::vector<Line<int> > lines);
    void setLinesIso(const std::vector<Line<int> > linesIso);

};

#endif // GLWIDGET_H
