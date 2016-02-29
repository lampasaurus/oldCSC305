#include "raytrianle.h"

RayTrianle::RayTrianle()
{
    rayOrigin = QVector3D(-9.4, -4.2, 9.2);
    direction = QVector3D (2, 0.6, -10);
    v1= QVector3D (-3, -4, 2);
    v2= QVector3D (2, -3, -1);
    v3= QVector3D (0, 7, -3);
}
RayTriangle::barycentric(QVector3D p){
    QVector3D f0 = v2 - v1;
    QVector3D f1 = v3 - v1;
    QVector3D f2 = p - v1;
    float d00 = dot(f0, f0);
    float d01 = dot(f0, f1);
    float d11 = dot(f1, f1);
    float d20 = dot(f2, f0);
    float d21 = dot(f2, f1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;
    QVector3D final = QVector3D (v, w, u);
    return final;
}

//@todo : calculate barycentric coordinates


//@todo: calculate intersection of ray and triangle


// @todo: test the calculated point to see it's inside the triangle or not
