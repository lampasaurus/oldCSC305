#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include <QGLWidget>
#include "QtGui"
#include <QWidget>
#include "iostream"
#include "particlesystem.h"

class RenderWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = 0);

protected:

    /**
      * function called automatically by QT after the OpenGL context is created
      * in here, do all OpenGL setup stuff, that you can before the actual program
      * execution starts
      */
    void initializeGL();
    /**
          * the function called whenever our Widget is being redrawn.
          * assume that the BasicOpenGLView's OpenGL context has already
          * been made the current one, so no need to call
          * this->makeCurrent(); anymore
          * Do all your rendering loop related code in there
          */
    void paintGL();

    /**
          * method called when the widget is resized.
          * we need code in there, to react to the changed window size
          * otherwise the rendering will look skewed and ugly
          */
    void resizeGL(int width, int height);

    /**
          * function called when a mouse button is pressed and the cursor is hovering
          * over our widget
          * use the QMouseEvent classmembers to access the mouse information
          */
    void mousePressEvent(QMouseEvent *event);

    /**
         * function called when a mouse button is released and/or the cursor stopped hovering
         * over our widget
         * use the QMouseEvent classmembers to access the mouse information
         */
    void mouseReleaseEvent(QMouseEvent *event);

    /**
          * function called when mouse cursor is moved inside our widgets region
          * use the QMouseEvent classmembers to access the mouse information
          */
    void mouseMoveEvent(QMouseEvent *event);

    /**
         * keyPressEvent is called when the window has focus and a key on the
         * keyboard is pressed
         * @param event
         */
    void keyPressEvent ( QKeyEvent * event );

    /**
         * keyReleaseEvent is called when the window has focus and a key on the
         * keyboard is released
         * @param event
         */
    void keyReleaseEvent ( QKeyEvent * event );
    
signals:
    
public slots:


private:
    ParticleSystem *particle;

    QMatrix4x4 matrix;

    GLfloat zNear;
    GLfloat zFar;
    GLfloat aspect;
    GLfloat fov;

    GLuint mTextureId;
    
};

#endif // RENDERWIDGET_H
