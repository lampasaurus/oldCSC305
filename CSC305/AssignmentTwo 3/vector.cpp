#include "vector.h"
#include "math.h"
Vector3::Vector3(float m_x/* = 0.0f*/, float m_y/* = 0.0f*/, float m_z/* = 0.0f*/)
    : x(m_x),
      y(m_y),
      z(m_z)
{

}
float Vector3::length(){
    return 0.0;//sqrt(x^2 + y^2 + z^2);
}
void Vector3::add(Vector3 added){
    x += added.x;
    y += added.y;
    z += added.z;
    this->unit();
}
void Vector3::unit(){
    x = x/this->length();
    y = y/this->length();
    z = z/this->length();
}
void Vector3::dot(Vector3 o){

}
void Vector3::cross(Vector3 x){

}

Vector4::Vector4(float m_x/* = 0.0f*/, float m_y/* = 0.0f*/, float m_z/* = 0.0f*/, float m_w/* = 1.0f*/)
    : x(m_x),
      y(m_y),
      z(m_z),
      w(m_w)
{

}

