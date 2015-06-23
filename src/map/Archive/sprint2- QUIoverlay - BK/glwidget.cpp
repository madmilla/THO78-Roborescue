#include "glwidget.h"
#include "GL/glu.h"

#include <stdio.h>
#include <iostream>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    xRotate = X_ROTATE_DEFAULT;
    yRotate = Y_ROTATE_DEFAULT;
    zRotate = Z_ROTATE_DEFAULT;

    zPan = MIN_ZOOM;
    xPan = 0.0f;
    yPan = 0.4f;
}

void GLWidget::initializeGL(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    //glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL(){
    //delete color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    map m;
    drawMap(&m);
}

void GLWidget::resizeGL (int width, int height){
    glViewport( 0, 0, (GLint)width, (GLint)height );
    /* create viewing cone with near and far clipping planes */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum( Algorithms::MIN_X, Algorithms::MAX_X, Algorithms::MIN_Y,
               Algorithms::MAX_Y, Algorithms::NEAR_VAL, Algorithms::FAR_VAL);
    glMatrixMode( GL_MODELVIEW );
}

void GLWidget::drawMap(map *m) {
    std::vector<line> mapData = m->getMapData();
    std::vector<Lines<int> > mapDataInt;

    std::vector<line>::iterator it;

    for(it = mapData.begin(); it != mapData.end(); ++it) {
        Lines<int> l(it->getPoint(0).getX(), it->getPoint(0).getY(), it->getPoint(1).getX(), it->getPoint(1).getY());
        mapDataInt.push_back(l);
    }
    Algorithms::getMinMax(mapDataInt, minX, maxX, minY, maxY);
    setLines(mapDataInt, minX, maxX, minY, maxY);
}

void GLWidget::addGridSquare(int x, int y, int length, int width, int color){
    int difX = maxX - minX;
    int difY = maxY - minY;

    //Normalizes the x, y, width and length from the lines between -1 and 1
    //Depending on what the minimal (minX, minY) and maximal (maxX, maxY) value,
    //a coordinate for example x will be normalizes between the -1 and 1
    float normalizedX = ((float(x - minX) / difX) * Algorithms::DIF_X) + Algorithms::MIN_X;
    float normalizedY = ((float(y - minY) / difY) * Algorithms::DIF_Y) + Algorithms::MIN_Y;
    float normalizedWidth = ((float(width - minX) / difX) * Algorithms::DIF_X) + Algorithms::MIN_X;
    float normalizedLength = ((float(length - minY) / difY) * Algorithms::DIF_Y) + Algorithms::MIN_Y;

    if(color == 2){
        //green
        green = 1.0f;
    }
    if(color == 3){
        //blue
        blue = 1.0f;
    }
    if(color == 4){
        //orange
        red = 1.0f;
        green = 0.5f;
    }
    if(color == 5){
        //cyan
        green = 1.0f;
        blue = 1.0f;
    }
    if(color == 6){
        //red
        red = 1.0f;
        blue = 1.0f;
    }
    if(color == 7){
        //black
        red = 0.5f;
        green = 0.5f;
        blue = 0.5f;
    }

    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex3f( normalizedX ,                   Algorithms::BOTTOM, normalizedY );
    glVertex3f( normalizedX + normalizedLength, Algorithms::BOTTOM, normalizedY );
    glVertex3f( normalizedX + normalizedLength, Algorithms::BOTTOM, normalizedY  + normalizedWidth );
    glVertex3f( normalizedX ,                   Algorithms::BOTTOM, normalizedY + normalizedWidth );

    glEnd();
}

void GLWidget::drawGround(){
    glBegin(GL_QUADS);
    glColor3f(115.0f/255.0f, 5.0f/255.0f, 110.0f/255.0f); //Grey
    //Ground
    glVertex3f( 1.0, Algorithms::BOTTOM,  1.0);
    glVertex3f( 1.0, Algorithms::BOTTOM, -1.0);
    glVertex3f(-1.0, Algorithms::BOTTOM, -1.0);
    glVertex3f(-1.0, Algorithms::BOTTOM,  1.0);
    glEnd();

}

void GLWidget::drawLine(const Lines<float> &line){
    glVertex3f(line.x1, Algorithms::BOTTOM,                      line.y1);
    glVertex3f(line.x2, Algorithms::BOTTOM,                      line.y2);
    glVertex3f(line.x2, Algorithms::BOTTOM + Algorithms::HEIGHT, line.y2);
    glVertex3f(line.x1, Algorithms::BOTTOM + Algorithms::HEIGHT, line.y1);
}

void GLWidget::drawLines(const std::vector<Lines<float> > linesNormalized){
    glBegin(GL_QUADS);
    glColor3f(254.0f/255.0f, 254.0f/255.0f, 33.0f/255.0f); // Black

    for(std::vector<Lines<float> >::const_iterator it = linesNormalized.begin(); it != linesNormalized.end(); ++it) {
        drawLine(*it);
    }
    glEnd();
}

void GLWidget::setLines(const std::vector<Lines<int> > lines, int minX, int maxX, int minY, int maxY){
    glTranslatef(xPan, yPan, zPan); //move
    glRotatef(xRotate, 1.0, 0.0, 0.0); //rotate x degress around x-axis
    glRotatef(yRotate, 0.0, 1.0, 0.0); //rotate y degress around y-axis
    glRotatef(zRotate, 0.0, 0.0, 1.0); //rotate z degress around z-axis

    drawGround();
    addGridSquare(50, 30, 13, 43, 7);
    const std::vector<Lines<float> > normalizedLines = Algorithms::normalizeLines(lines,  minX,  maxX,  minY,  maxY);
    drawLines(normalizedLines);
}

void GLWidget::drawGroundIso(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.0f); //Green
    //Ground
    glVertex2f( -1.0,  0.0);
    glVertex2f(  0.0, -1.0);
    glVertex2f(  1.0,  0.0);
    glVertex2f(  0.0,  1.0);
    glEnd();
}

void GLWidget::drawLineIso(const Lines<float> &lineIso){
    glVertex2f(lineIso.x1, lineIso.y1);
    glVertex2f(lineIso.x2, lineIso.y2);
    glVertex2f(lineIso.x2, lineIso.y2 + Algorithms::HEIGHT_ISO);
    glVertex2f(lineIso.x1, lineIso.y1 + Algorithms::HEIGHT_ISO);
}

void GLWidget::drawLinesIso(const std::vector<Lines<float> > linesNormalizedIso){
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f); // Red
    for(std::vector<Lines<float> >::const_iterator it = linesNormalizedIso.begin(); it != linesNormalizedIso.end(); ++it) {
        drawLineIso(*it);
    }
    glEnd();
}

void GLWidget::setLinesIso(const std::vector<Lines<int> > linesIso){
    glTranslatef(0.0f, 0.0f, zPan); //move along z-axis

    drawGroundIso();
    const std::vector<Lines<float> > normalizedLines = Algorithms::normalizeLines(linesIso,  minX,  maxX,  minY,  maxY);
    const std::vector<Lines<float> > normalizedLinesIso = Algorithms::twoDToIsoVector(normalizedLines);
    drawLinesIso(normalizedLinesIso);
}

void GLWidget::setPolygons(const std::vector<std::vector<points> >& polygons){
    glTranslatef(xPan, yPan, zPan); //move
    glRotatef(xRotate, 1.0, 0.0, 0.0); //rotate x degress around x-axis
    glRotatef(yRotate, 0.0, 1.0, 0.0); //rotate y degress around y-axis
    glRotatef(zRotate, 0.0, 0.0, 1.0); //rotate z degress around z-axis

    drawGround();
    const std::vector<Lines<float> > normalizedLines = Algorithms::getNormalizedLinesForPolygons(polygons);
    drawLines(normalizedLines);
}

void GLWidget::rotateX(int angle) {
    if(angle > 90){
       angle = 90;
    }
    else if( angle < 0){
        angle = 0;
    }
    xRotate = (float)angle;
    emit xRotationChanged(angle);
    updateGL();
}

void GLWidget::rotateY(int angle) {
    angle = angle % 360;
    while(angle < 0) {
        angle += 360;
    }
    yRotate = (float)angle;
    emit yRotationChanged(angle);
    updateGL();
}

void GLWidget::panLeft(){
    xPan -= 0.1f;
    updateGL();
}

void GLWidget::panRight(){
    xPan += 0.1f;
    updateGL();
}

void GLWidget::panUp(){
    yPan += 0.1f;
    updateGL();
}

void GLWidget::panDown(){
    yPan -= 0.1f;
    updateGL();
}

void GLWidget::zoom(int zoomLevel) {
    zLevel = zoomLevel;
    if(zLevel < 0){
        zLevel = 0;
    }
    else if(zLevel > 50){
        zLevel = 50;
    }
    zPan = MIN_ZOOM + ((float(zLevel) / 100) * (MAX_ZOOM - MIN_ZOOM));
    emit zoomChanged(zLevel);
    updateGL();
}

//Rotate with mouse
void GLWidget::mousePressEvent(QMouseEvent *event) {
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton) {
        rotateX(xRotate + dy/10);
        rotateY(yRotate + dx/10);
    }
}

//Zoom with mouse
void GLWidget::wheelEvent(QWheelEvent *event){
    zoom(zLevel + event->delta()/10);
}

//Pan with keyboard
void GLWidget::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        panLeft();
    }else if(event->key() == Qt::Key_Right){
        panRight();
    }else if(event->key() == Qt::Key_Up){
        panUp();
    }else if(event->key() == Qt::Key_Down){
        panDown();
    }
}
