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

    std::vector<Line<int> > lines;
    //buitenkant
    Line<int> line1(0,      0,      10000,  0);
    Line<int> line2(10000,  0,      10000,  5000);
    Line<int> line3(10000,  5000,   0,      5000);
    Line<int> line4(0,      5000,   0,      0);
    //Vierkant 1
    Line<int> line5(2000, 3000, 3000, 3000);
    Line<int> line6(3000, 3000, 3000, 4000);
    Line<int> line7(3000, 4000, 2000, 4000);
    Line<int> line8(2000, 4000, 2000, 3000);
    //Vierkant 2
    Line<int> line9(5000, 2000, 6000, 2000);
    Line<int> line10(6000, 2000, 6000, 3500);
    Line<int> line11(6000, 3500, 5000, 3500);
    Line<int> line12(5000, 3500, 5000, 2000);
    //Vierkant 3
    Line<int> line13(7000, 1000, 8000, 1000);
    Line<int> line14(8000, 1000, 8000, 1500);
    Line<int> line15(8000, 1500, 7000, 1500);
    Line<int> line16(7000, 1500, 7000, 1000);
    //Random lijnen
    Line<int> line17(1800, 1300, 5000, 1300);
    Line<int> line18(2000, 3000, 1000, 2500);
    Line<int> line19(1000, 2500, 3000, 3000);
    Line<int> line20(7300, 3500, 9000, 2750);

    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
    lines.push_back(line5);
    lines.push_back(line6);
    lines.push_back(line7);
    lines.push_back(line8);
    lines.push_back(line9);
    lines.push_back(line10);
    lines.push_back(line11);
    lines.push_back(line12);
    lines.push_back(line13);
    lines.push_back(line14);
    lines.push_back(line15);
    lines.push_back(line16);
    lines.push_back(line17);
    lines.push_back(line18);
    lines.push_back(line19);
    lines.push_back(line20);

    Algorithms::getMinMax(lines, minX, maxX, minY, maxY);
    setLines(lines, minX, maxX, minY, maxY);
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

void GLWidget::addGridSquare(int x, int y, int length, int width){
    int difX = maxX - minX;
    int difY = maxY - minY;

    float normalizedX = ((float(x - minX) / difX) * Algorithms::DIF_X) + Algorithms::MIN_X;
    float normalizedY = ((float(y - minY) / difY) * Algorithms::DIF_Y) + Algorithms::MIN_Y;
    float normalizedWidth = ((float(width - minX) / difX) * Algorithms::DIF_X) + Algorithms::MIN_X;
    float normalizedLength = ((float(length - minY) / difY) * Algorithms::DIF_Y) + Algorithms::MIN_Y;

    std::cout << "x: " << normalizedX << "\n";
    std::cout << "y: " << normalizedY << "\n";
    std::cout << "w: " << normalizedWidth << "\n";
    std::cout << "l: " << normalizedLength << "\n";

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex3f( normalizedX , Algorithms::BOTTOM,                   normalizedY );
    glVertex3f( normalizedX + normalizedLength,Algorithms::BOTTOM, normalizedY );
    glVertex3f( normalizedX + normalizedLength, Algorithms::BOTTOM,normalizedY  + normalizedWidth );
    glVertex3f( normalizedX ,   Algorithms::BOTTOM,                normalizedY + normalizedWidth );

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

void GLWidget::drawLine(const Line<float> &line){
    glVertex3f(line.x1, Algorithms::BOTTOM, line.y1);
    glVertex3f(line.x2, Algorithms::BOTTOM, line.y2);
    glVertex3f(line.x2, Algorithms::BOTTOM + Algorithms::HEIGHT, line.y2);
    glVertex3f(line.x1, Algorithms::BOTTOM + Algorithms::HEIGHT, line.y1);
}

void GLWidget::drawLines(const std::vector<Line<float> > linesNormalized){
    glBegin(GL_QUADS);
    glColor3f(254.0f/255.0f, 254.0f/255.0f, 33.0f/255.0f); // Black

    for(std::vector<Line<float> >::const_iterator it = linesNormalized.begin(); it != linesNormalized.end(); ++it) {
        drawLine(*it);
    }
    glEnd();
}

void GLWidget::setLines(const std::vector<Line<int> > lines, int minX, int maxX, int minY, int maxY){
    glTranslatef(xPan, yPan, zPan); //move
    glRotatef(xRotate, 1.0, 0.0, 0.0); //rotate x degress around x-axis
    glRotatef(yRotate, 0.0, 1.0, 0.0); //rotate y degress around y-axis
    glRotatef(zRotate, 0.0, 0.0, 1.0); //rotate z degress around z-axis

    drawGround();
    addGridSquare(3245, 2345, 1244, 4633);
    const std::vector<Line<float> > normalizedLines = Algorithms::normalizeLines(lines,  minX,  maxX,  minY,  maxY);
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

void GLWidget::drawLineIso(const Line<float> &lineIso){
    glVertex2f(lineIso.x1, lineIso.y1);
    glVertex2f(lineIso.x2, lineIso.y2);
    glVertex2f(lineIso.x2, lineIso.y2 + Algorithms::HEIGHT_ISO);
    glVertex2f(lineIso.x1, lineIso.y1 + Algorithms::HEIGHT_ISO);
}

void GLWidget::drawLinesIso(const std::vector<Line<float> > linesNormalizedIso){
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f); // Red
    for(std::vector<Line<float> >::const_iterator it = linesNormalizedIso.begin(); it != linesNormalizedIso.end(); ++it) {
        drawLineIso(*it);
    }
    glEnd();
}

void GLWidget::setLinesIso(const std::vector<Line<int> > linesIso){
    glTranslatef(0.0f, 0.0f, zPan); //move along z-axis

    drawGroundIso();
    const std::vector<Line<float> > normalizedLines = Algorithms::normalizeLines(linesIso,  minX,  maxX,  minY,  maxY);
    const std::vector<Line<float> > normalizedLinesIso = Algorithms::twoDToIsoVector(normalizedLines);
    drawLinesIso(normalizedLinesIso);
}

void GLWidget::setPolygons(const std::vector<std::vector<point> >& polygons){
    glTranslatef(xPan, yPan, zPan); //move
    glRotatef(xRotate, 1.0, 0.0, 0.0); //rotate x degress around x-axis
    glRotatef(yRotate, 0.0, 1.0, 0.0); //rotate y degress around y-axis
    glRotatef(zRotate, 0.0, 0.0, 1.0); //rotate z degress around z-axis

    drawGround();
    const std::vector<Line<float> > normalizedLines = Algorithms::getNormalizedLinesForPolygons(polygons);
    drawLines(normalizedLines);
}

void GLWidget::rotateX(int angle) {
    if(angle >90){
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
/*
void GLWidget::rotateZ(int angle) {
    if(angle >90){
       angle = 90;
    }
    else if( angle < 0){
        angle = 0;
    }
    zRotate = (float)angle;
    emit zRotationChanged(angle);
    updateGL();
}
*/

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
    } /*else if (event->buttons() & Qt::RightButton) {
        rotateX(xRotate + dy/10);
        rotateZ(zRotate + dx/10);
    }*/
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
