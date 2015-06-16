/*!
 *  Class performing all the draw operations, as well as capturing events
 *  performed on the GLWidget itself (e.g. mouseclicks and keypresses)
 *  \author    Bianca Krieger
 */

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

    int minX, maxX, minY, maxY;

private:

    void addGridSquare(int x, int y, int length, int width);

    /*!
    *   Draws a 3D green square at the bottom of the OpenGL widget
    */
    void drawGround();

    /*!
    *   Draws an isometric green square at the bottom of the OpenGL widget
    */
    void drawGroundIso();

    /*!
    *   Draws a single line as a wall in 3D on top of the ground drawn by drawGround.
    *   Since the line (x1, y1, x2, y2) has no height, a default constant height is used.
    *   The x and y values of the line should already be normalized between MIN_X(-1) and MAX_X(1)
    *   by the Algorithm::normalizeLines function.
    *   @param line Normalized line to draw
    */
    void drawLine(const Line<float> &line);

    /*!
    *   Draws a vector of lines as a set of walls in 3D on top of the ground drawn by drawGround.
    *   Since the lines (x1, y1, x2, y2) have no height, a default constant height is used.
    *   The x and y values of the lines should already be normalized between MIN_X(-1) and MAX_X(1)
    *   by the Algorithm::normalizeLines function.
    *   @param linesNormalized Vector of normalized lines to draw
    */
    void drawLines(const std::vector<Line<float> > linesNormalized);

    /*!
    *   Draws a single line isometric on top the ground drawn by drawGroundIso
    *   Since the line (x1, x2, y1, y2) has no height, a default constant height is used.
    *   The x and y values of the line should already be normalized between MIN_X(-1) and MAX_X(1)
    *   by the Algorithm::normalizeLines function and the isometric coordinates should have been
    *   calculated by Algorithms::twoDToIso.
    *   @param lineIso Normalized line of which the isometric coordinates have been calculated
    */
    void drawLineIso(const Line<float> &lineIso);

    /*!
    *   Draws a vector of lines in 2.5D (isometric) on top the ground drawn by drawGroundIso
    *   Since the line (x1, x2, y1, y2) has no height, a default constant height is used.
    *   The x and y values of the line should already be normalized between MIN_X(-1) and MAX_X(1)
    *   by the Algorithm::normalizeLines function and the isometric coordinates should have been
    *   calculated by Algorithms::twoDToIso.
    *   @param linesNormalizedIso Vector of normalized lines of which the isometric coordinates have been calculated
    */
    void drawLinesIso(const std::vector<Line<float> > linesNormalizedIso);

    /*!
    *   Draws the ground and a vector of lines in 3D.
    *   Before the lines are drawn, they will be normalized within this function
    *   @param lines Vector of lines to draw
    */
    void setLines(const std::vector<Line<int> > lines, int minX, int maxX, int minY, int maxY);

    /*!
    *   Draws the ground and a vector of lines isometricly (2.5D).
    *   Before the lines are drawn, they will be normalized within this function
    *   @return linesIso Vector of lines to draw
    */
    void setLinesIso(const std::vector<Line<int> > linesIso);

    /*!
      TODO DO
    *   Draws the ground and a vector of lines isometricly (2.5D).
    *   Before the lines are drawn, they will be normalized within this function
    *   @return linesIso Vector of lines to draw
    */
    void setPolygons(const std::vector<std::vector<point> >& polygons);

    /*!
    *   Remembers the begin click position for the mouseMoveEvent
    *   @param event Default argument for mousePressEvents
    */
    void mousePressEvent(QMouseEvent *event);

    /*!
    *   When the mouse button is hold, the camera will be rotated relative to the
    *   begin click position
    *   @param event Default argument for mouseMoveEvents
    */
    void mouseMoveEvent(QMouseEvent *event);

    /*!
    *   When the scroll wheel is used, the camera will either zoom in or out
    *   @param event Default argument for wheelEvents
    */
    void wheelEvent(QWheelEvent *event);

    /*!
    *   When one of the keys Left, Right, Up or Down is pressed, the camera will move
    *   relatively to that direction.
    *   @param event Default argument for keyPressEvents
    */
    void keyPressEvent(QKeyEvent *event);

    static const float X_ROTATE_DEFAULT = 45.0;
    static const float Y_ROTATE_DEFAULT = 45.0;
    static const float Z_ROTATE_DEFAULT = 0.0;

    float xRotate;
    float yRotate;
    float zRotate;

    static const float MIN_ZOOM = -8.0f;
    static const float MAX_ZOOM = -4.0f;
    float zPan;
    float xPan;
    float yPan;

    int zLevel;

    QPoint lastPos;


public slots:
    /*!
    *   Rotate the GLWidget around the X axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    void rotateX(int angle);

    /*!
    *   Rotate the GLWidget around the Y axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    void rotateY(int angle);

    /*!
    *   Rotate the GLWidget around the Z axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    /*void rotateZ(int angle);*/

    /*!
    *   Pan the camera to the left
    */
    void panLeft();

    /*!
    *   Pan the camera to the right
    */
    void panRight();

    /*!
    *   Pan the camera upwards
    */
    void panUp();

    /*!
    *   Pan the camera downwards
    */
    void panDown();

    /*!
    *   Zoom the camera
    *   @param zoomLevel Zoom level (between 0 and 100)
    */
    void zoom(int zoomLevel);

signals:
    /*!
    *   Event that is raised when the camera has turned around its X axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    void xRotationChanged(int angle);

    /*!
    *   Event that is raised when the camera has turned around its Y axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    void yRotationChanged(int angle);

    /*!
    *   Event that is raised when the camera has turned around its Z axis
    *   @param angle Angle (degrees, 0-360) of the camera
    */
    void zRotationChanged(int angle);

    /*!
    *   Event that is raised when the camera has changed its zoom-level
    *   @param zoomLevel Zoom factor (between 0 and 100)
    */
    void zoomChanged(int zoomLevel);
};

#endif // GLWIDGET_H
