#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include "QtGui"
#include <QGLWidget>
#include "QGLShader"
#include "QGLShaderProgram"
#include <QtOpenGL>

#include "supporting_files/s_program.h"


class QGLBuffer;
//class QGLShaderProgram;

class ParticleSystem
{
public:
    ParticleSystem();


    bool Render(QMatrix4x4 matrix, GLuint textureId); // returns false if the animation is finished (==nothing drawn!)

    float randomNum(float min, float max);

    bool update(const float& deltaTime_s); // allow system to update its uniform variables

    signals:

    private:
        void linkShaderProgram();
        void createVertexBuffer();


        int mParticleCount;
        GLuint mTextureId;
        GLfloat mParticleSize;
        QVector3D mGravity;
        QVector4D mColor;

        QTime mSystemTime;
        QTime mStartedtime;
        GLfloat mTimeMax;

        Program* mShader;
        int mMatrixUni, mCenterVectorUni, mGravityVectorUni, mTimeStartedAttr, mTimeElapsedUni, mMaxPointSizeUni, mColorUni, mStartVectorUni, mVelocityAttr;


        GLuint mVertexArray;
        GLuint velocityBuffer;
        GLuint timeBuffer;


};

#endif // PARTICLESYSTEM_H
