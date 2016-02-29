#ifndef RAYTRIANLE_H
#define RAYTRIANLE_H

#include "QtGui"

class RayTrianle
{
public:
    RayTrianle();
    QVector3D barycentric(QVector3D p);
private:
    QVector3D rayOrigin;  // where ray starts
    QVector3D direction;  // direction of the ray
    QVector3D v1, v2, v3;  // three vertices of a triangle
};

#endif // RAYTRIANLE_H
