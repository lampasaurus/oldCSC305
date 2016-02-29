#include "renderwidget.h"

QGLWidget* RenderWidget::static_QGLWidget= 0;

RenderWidget::RenderWidget(QWidget *parent) :
    QWidget(parent)
    ,zNear(0.1f), zFar(100.0f), fov(90.0f)
{

}
void RenderWidget::initializeGL()
{
#ifndef __APPLE__
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cerr << "Glew could not initialize" << std::endl;
    }
#endif
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    std::cout<<glGetString(GL_VERSION)<<std::endl;
#else
    if(this->format().majorVersion() < 3 && this->format().minorVersion() < 2)
    {
        QMessageBox msgBox;
        msgBox.setText("The OpenGL version available on this computer is too old.");
        msgBox.setInformativeText("OpenGL 3.2 or higher required to run this application.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        msgBox.exec();
        QCoreApplication::quit();
    }
#endif

}
void RenderWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);

    aspect = width/height;
    // set projection matrix
    QMatrix4x4 projMatrix;
    projMatrix.setToIdentity();
    projMatrix.perspective(fov, aspect, zNear, zFar);

    // set view matrix
    QMatrix4x4 viewMat;
    viewMat.setToIdentity();

    viewMat.lookAt(QVector3D(4,4,4),QVector3D(0,0,0), QVector3D(0,1.0,0) );

     matrix = projMatrix * viewMat;
}
void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}
void RenderWidget::mousePressEvent(QMouseEvent *event)
{

}

void RenderWidget::mouseReleaseEvent(QMouseEvent *event)
{

}

void RenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    float eventX = (float)event->x() / width();
    float eventY = 1.0f - (float) event->y() / height();

    eventX -= 0.5f;
    eventY -= 0.5f;
    eventX *= 2.0f;
    eventY *= 2.0f;

    QVector3D curPoint(eventX, eventY, 0);

}

void RenderWidget::keyPressEvent(QKeyEvent *event)
{

}

void RenderWidget::keyReleaseEvent(QKeyEvent *event)
{

}
