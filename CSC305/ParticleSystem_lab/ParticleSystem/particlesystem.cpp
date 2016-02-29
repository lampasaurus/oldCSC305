#define GL_GLEXT_PROTOTYPES

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include "particlesystem.h"
#include <QFile>
#include <QGLBuffer>
#include "iostream"
#include "string"
#include "sstream"
#include "fstream"


ParticleSystem::ParticleSystem()
     :
     mParticleCount(100)
    , mShader(0)
   , mVertexArray(0)
{
    mParticleSize = 30.0;

    mSystemTime.start();
}


bool ParticleSystem::Render(QMatrix4x4 matrix, GLuint textureId)
{

    if(mShader == 0)
        linkShaderProgram();
    mShader->activate();

    if(mVertexArray == 0)
    createVertexBuffer();


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glEnable(GL_POINT_SPRITE); // example code forgot to mention this little trap!
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);

     // @to do : enable blending:

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    float tempMatrix[16];
    qreal * matrixData = matrix.data();
    for(size_t i = 0; i < 16; ++i)
    {
        tempMatrix[i] = matrixData[i];
    }
    glUniformMatrix4fv(mMatrixUni,
                       1,
                       false,
                        tempMatrix);

    GLfloat elapsedTime = (GLfloat)mSystemTime.elapsed();
    glUniform1f(mTimeElapsedUni,
                elapsedTime);
    glUniform1f(mMaxPointSizeUni,
                mParticleSize);

    float startPos[3] = {0.0f, 0.0f, 0.0f};
    glUniform3fv(mStartVectorUni,
                 1,
                 startPos);

    glBindVertexArray(mVertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, velocityBuffer);
    glEnableVertexAttribArray(mVelocityAttr);
    glVertexAttribPointer(mVelocityAttr,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          0);

    glBindBuffer(GL_ARRAY_BUFFER, velocityBuffer);
    glEnableVertexAttribArray(mTimeStartedAttr);
    glVertexAttribPointer(mTimeStartedAttr,
                          1,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          0);

    glDrawArrays ( GL_POINTS, 0, mParticleCount);

    glDisableVertexAttribArray(mTimeStartedAttr);
    glDisableVertexAttribArray(mVelocityAttr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    mShader->deactivate();
// @to do : disable blending:

    return true;
}

void ParticleSystem::linkShaderProgram()
{
    Q_ASSERT( mShader == 0 );
    mShader = new Program;



    std::ifstream vt("../../../../ParticleSystem/particle_v.vert");
    std::stringstream vbuffer;
    vbuffer << vt.rdbuf();
    std::string vertexShader = vbuffer.str();

    std::ifstream ft("../../../../ParticleSystem/particle_f.frag");
    std::stringstream fbuffer;
    fbuffer << ft.rdbuf();
    std::string fragmentShader = fbuffer.str();

    Shader * vShader = new Shader(vertexShader, Shader::VERTEX);
    vShader->load();
    Shader * fShader = new Shader(fragmentShader, Shader::FRAGMENT);
    fShader->load();

    mShader->push_back(vShader);
    mShader->push_back(fShader);

    mShader->link();

    mTimeStartedAttr = mShader->getAttribute("timeStarted")->getHandle();
    mTimeElapsedUni = mShader->getParameter("timeElapsed")->getHandle();
    mMaxPointSizeUni = mShader->getParameter("maxPointSize")->getHandle();
    mMatrixUni = mShader->getParameter("matrix")->getHandle();
    mVelocityAttr = mShader->getAttribute("vVelocity")->getHandle();
    mStartVectorUni = mShader->getParameter("startPosition")->getHandle();

}

void ParticleSystem::createVertexBuffer()
{

    int lengthOfArray = 3*mParticleCount;// 3: startVec3D; 3: color4D;
    GLfloat* velocities = new GLfloat[lengthOfArray];

    GLfloat * timeStarted = new GLfloat[mParticleCount];

    qsrand( QDateTime::currentDateTime().toTime_t() );


    mStartedtime.start();

    for(size_t i = 0; i < lengthOfArray; ++i)
    {
        velocities[i] = randomNum(-3.0, 3.0);
    }

    for(size_t i = 0; i < mParticleCount; ++i)
    {
        timeStarted[i] = i * 100;
    }

    glGenVertexArrays(1, & mVertexArray);
    glBindVertexArray(mVertexArray);

    glGenBuffers(1, & velocityBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, velocityBuffer);
    glBufferData(GL_ARRAY_BUFFER, 3 * mParticleCount * sizeof(GLfloat), & velocities[0], GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, & timeBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, velocityBuffer);
    glBufferData(GL_ARRAY_BUFFER, mParticleCount * sizeof(GLfloat), & timeStarted[0], GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] velocities;
    delete[] timeStarted;
}
//--------------------------------------------------------------
float ParticleSystem::randomNum(float min, float max)
    {
        if (min>max)
            return max+float((min-max+1)*qrand()/(RAND_MAX+1.0));
        else
            return min+float((max-min+1)*qrand()/(RAND_MAX+1.0));
    }
//--------------------------------------------------------------
