#include "glwidget.h"
#include "GL/glu.h"

#include <stdio.h>
#include <iostream>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
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

    setLinesIso(lines);

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
    glTranslatef(0.0f, 0.4f, Algorithms::ZOOM_OUT_Z); //move along z-axis
    glRotatef(45.0, 1.0, 0.0, 0.0); //rotate 45 degress around x-axis
    glRotatef(45.0, 0.0, 1.0, 0.0); //rotate 45 degress around y-axis

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
    glTranslatef(0.0f, 0.0f, Algorithms::ZOOM_OUT_Z); //move along z-axis

    drawGroundIso();
    const std::vector<Line<float> > normalizedLines = Algorithms::normalizeLines(linesIso);
    const std::vector<Line<float> > normalizedLinesIso = Algorithms::twoDToIsoVector(normalizedLines);
    drawLinesIso(normalizedLinesIso);
}

