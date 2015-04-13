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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL(){
    //delete color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::vector<Line<int> > lines;
    //voorbeeld lijnen
    Line<int> line1(0, 0, 0, 1);
    Line<int> line2(0, 1, 1, 1);
    Line<int> line3(1, 1, 1, 0);
    Line<int> line4(1, 0, 0, 0);
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);

    setLines(lines);

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

void GLWidget::drawGround(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.0f); //Green
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
    glColor3f(0.8f, 0.0f, 0.0f); // Red

    for(std::vector<Line<float> >::const_iterator it = linesNormalized.begin(); it != linesNormalized.end(); ++it) {
        drawLine(*it);
    }
    glEnd();
}

void GLWidget::setLines(const std::vector<Line<int> > lines){
    glTranslatef(xPan, yPan, zPan); //move
    glRotatef(xRotate, 1.0, 0.0, 0.0); //rotate x degress around x-axis
    glRotatef(yRotate, 0.0, 1.0, 0.0); //rotate y degress around y-axis
    glRotatef(zRotate, 0.0, 0.0, 1.0); //rotate z degress around z-axis

    drawGround();
    const std::vector<Line<float> > normalizedLines = Algorithms::normalizeLines(lines);
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
    const std::vector<Line<float> > normalizedLines = Algorithms::normalizeLines(linesIso);
    const std::vector<Line<float> > normalizedLinesIso = Algorithms::twoDToIsoVector(normalizedLines);
    drawLinesIso(normalizedLinesIso);
}

void GLWidget::rotateX(int angle) {
    angle = angle % 360;
    while(angle < 0) {
        angle += 360;
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

void GLWidget::rotateZ(int angle) {
    angle = angle % 360;
    while(angle < 0) {
        angle += 360;
    }
    zRotate = (float)angle;
    emit zRotationChanged(angle);
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
    zLevel= zoomLevel;
    if(zLevel < 0){
        zLevel = 0;
    }
    else if(zLevel > 100){
        zLevel = 100;
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
    } else if (event->buttons() & Qt::RightButton) {
        rotateX(xRotate + dy/10);
        rotateZ(zRotate + dx/10);
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
