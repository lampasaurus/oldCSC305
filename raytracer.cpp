
//Creatued using the tutorial from www.scratchapixel.com

//What they provided:
//Names of the methods with a description of what they do
//The Sphere class
//A blank template for the Trace class
//Geometry
//Basically any line with //(comment explaining the line) after it)
//Save image as a .ppm


//What I did:
//Calculate colours
//  Transparency, reflection, refraction, highlights
//Calculate ray intersection
//Calculate reflection
//If it's on here, doesn't have a //(comment) after it, and wasn't mentioned above, I either wrote it or found it somewhere else.

//Yes, this code is an abomination of concepts I only half understand pieced togeather and modified to work with each other.

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#define MAX_RAY_DEPTH 4

template<typename T>
class Vec3
{
public:
    T x, y, z;
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(T xx) : x(xx), y(xx), z(xx) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    Vec3& normalize()
    {
        T nor = x * x + y * y + z * z;
        if (nor > 0) {
            T invNor = 1 / sqrt(nor);
            x *= invNor, y *= invNor, z *= invNor;
        }
        return *this;
    }
    Vec3<T> operator * (const T &f) const { return Vec3<T>(x * f, y * f, z * f); }
    Vec3<T> operator * (const Vec3<T> &v) const { return Vec3<T>(x * v.x, y * v.y, z * v.z); }
    T dot(const Vec3<T> &v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3<T> operator - (const Vec3<T> &v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
    Vec3<T> operator + (const Vec3<T> &v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
    Vec3<T>& operator += (const Vec3<T> &v) { x += v.x, y += v.y, z += v.z; return *this; }
    Vec3<T>& operator *= (const Vec3<T> &v) { x *= v.x, y *= v.y, z *= v.z; return *this; }
    Vec3<T> operator - () const { return Vec3<T>(-x, -y, -z); }
    friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v)
    {
        os << "[" << v.x << " " << v.y << " " << v.x << "]";
        return os;
    }
};

template<typename T>
class Sphere
{
public:
    Vec3<T> center;                         /// position of the sphere
    T radius, radius2;                      /// sphere radius and radius^2
    Vec3<T> surfaceColor, emissionColor;    /// surface color and emission (light)
    T transparency, reflection;             /// surface transparency and reflectivity
    Sphere(const Vec3<T> &c, const T &r, const Vec3<T> &sc, 
        const T &refl = 0, const T &transp = 0, const Vec3<T> &ec = 0) :
        center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
        transparency(transp), reflection(refl)
    {}
    // Takes a
    bool intersect(const Vec3<T> &ray, const Vec3<T> &raydir, T *t0 = NULL, T *t1 = NULL) const
    {
        Vec3<T> l = center - ray;
        T tca = l.dot(raydir);
        if (tca < 0) return false;
        T d2 = l.dot(l) - tca * tca;
        if (d2 > radius2) return false;
        T thc = sqrt(radius2 - d2);
        if (t0 != NULL && t1 != NULL) {
            *t0 = tca - thc;
            *t1 = tca + thc;
        }
        return true;
    }
};

template<typename T>
class Plane{
public:
    Vec3<T> pos;
    Vec3<T> facing;
    Vec3<T> color;
    Plane(const Vec3<T> c, const Vec3<T> p, const Vec3<T> f ) :
        pos(p), color(c), facing(f)
    {}
    bool intersect(const Vec3<T> &ray, const Vec3<T> &raydir) const{

    }
};

template<typename T>
T mix(const T &a, const T &b, const T &mix)
{
    return b * mix + a * (T(1) - mix);
}

// This is the main trace function. It takes a ray as argument (defined by its origin
// and direction). We test if this ray intersects any of the geometry in the scene.
// If the ray intersects an object, we compute the intersection point, the normal
// at the intersection point, and shade this point using this information.
// Shading depends on the surface property (is it transparent, reflective, diffuse).
// The function returns a color for the ray. If the ray intersects an object that
// is the color of the object at the intersection point, otherwise it returns
// the background color.
template<typename T>
Vec3<T> trace(const Vec3<T> &rayorig, const Vec3<T> &raydir, 
    const std::vector<Sphere<T> *> &spheres, const int &depth)
{
    T tnear = INFINITY;
    const Sphere<T> *sphere = NULL;
    // find intersection of this ray with the sphere in the scene
    for (int i = 0; i < spheres.size(); ++i) {

        T t0 = INFINITY, t1 = INFINITY;
        if (spheres[i]->intersect(rayorig, raydir, &t0, &t1)) {
            if (t0 < 0) t0 = t1;
            if (t0 < tnear) {
                tnear = t0;
                sphere = spheres[i];
            }
        }

    }
    // if there's no intersection return black or background color
    if (!sphere) return Vec3<T>(2);
    Vec3<T> surfaceColor = 0; // color of the ray/surfaceof the object intersected by the ray
    Vec3<T> phit = rayorig + raydir * tnear; // point of intersection
    Vec3<T> nhit = phit - sphere->center; // normal at the intersection point
    // if the normal and the view direction are not opposite to each other 
    // reverse the normal direction
    if (raydir.dot(nhit) > 0) nhit = -nhit;
    nhit.normalize(); // normalize normal direction
    T bias = 1e-5; // add some bias to the point from which we will be tracing

    //Calculates sphere's colour if the sphere is visible
    if ((sphere->transparency > 0 || sphere->reflection > 0) && depth < MAX_RAY_DEPTH) {
        T IdotN = raydir.dot(nhit);
        T refPower = std::max(T(0), -IdotN);

        //calculates highlights
        T specular = mix<T>(pow(1 - refPower, 3), 1, 0.1);

        //calculates reflection
        Vec3<T> refldir = raydir - nhit * 2 * raydir.dot(nhit);
        Vec3<T> reflection = trace(phit + nhit * bias, refldir, spheres, depth + 1);
        Vec3<T> refraction = 0;

        //Calculates refraction
        if (sphere->transparency) {
            T ior = 1.2, eta = 1 / ior;
            T k = 1 - eta * eta * (1 - IdotN * IdotN);
            Vec3<T> refrdir = raydir * eta - nhit * (eta *  IdotN + sqrt(k));
            refraction = trace(phit - nhit * bias, refrdir, spheres, depth + 1);
        }
        surfaceColor = (reflection * specular +
            refraction * (1 - specular) * sphere->transparency) * sphere->surfaceColor;
    }
    //else: calculate any light sources off screen
    else {
        for (unsigned i = 0; i < spheres.size(); ++i) {
            if (spheres[i]->emissionColor.x > 0) {
                Vec3<T> transmission = 1;
                Vec3<T> lightDirection = spheres[i]->center - phit;
                lightDirection.normalize();
                for (unsigned j = 0; j < spheres.size(); ++j) {
                    if (i != j) {
                        T t0, t1;
                        if (spheres[j]->intersect(phit + nhit * bias, lightDirection, &t0, &t1)) {
                            transmission = 0;
                            break;
                        }
                    }
                }
                surfaceColor += sphere->surfaceColor * transmission * 
                    std::max(T(0), nhit.dot(lightDirection)) * spheres[i]->emissionColor;
            }
        }
    }
    return surfaceColor + sphere->emissionColor;
}

//The Ray "Fireing" function.
template<typename T>
void render(const std::vector<Sphere<T> *> &spheres)
{
    unsigned width = 640, height = 480;
    Vec3<T> *image = new Vec3<T>[width * height], *pixel = image;
    T invWidth = 1 / T(width), invHeight = 1 / T(height);
    T fov = 30, aspectratio = width / T(height);
    T angle = tan(M_PI * 0.5 * fov / T(180));
    // Trace rays
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x, ++pixel) {
            T xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio;
            T yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
            Vec3<T> raydir(xx, yy, -1);
            raydir.normalize();

            *pixel = trace(Vec3<T>(0), raydir, spheres, 0);
        }
    }
    // Save result to a PPM image
    std::ofstream ofs("./untitled.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i) {
        ofs << (unsigned char)(std::min(T(1), image[i].x) * 255) <<
            (unsigned char)(std::min(T(1), image[i].y) * 255) <<
            (unsigned char)(std::min(T(1), image[i].z) * 255);
    }
    ofs.close();
    delete [] image;
}

int main(int argc, char **argv)
{
    std::vector<Sphere<float> *> spheres;
    //Put Scenes here
    // position, radius, surface color, reflectivity, transparency, light emission color
    spheres.push_back(new Sphere<float>(Vec3<float>(-3, 0, -10), 1.5, Vec3<float>(0.00, 0.72, 0.36),1.0 , 1.0, 0.0));
    spheres.push_back(new Sphere<float>(Vec3<float>(3, 0, -10), 1.5, Vec3<float>(0.50, 0.32, 0.36),1.0 , 1.0, 0.0));
    spheres.push_back(new Sphere<float>(Vec3<float>(0, 0, -20), 1.5, Vec3<float>(1.00, 0.32, 0.36),1.0 , 1.0, 0.0));
    spheres.push_back(new Sphere<float>(Vec3<float>(0, 3, -20), 1.5, Vec3<float>(1.00, 0.62, 0.36),1.0 , 1.0, 0.0));
    spheres.push_back(new Sphere<float>(Vec3<float>(0, -3, -20), 1.5, Vec3<float>(1.00, 0.32, 0.36),1.0 , 1.0, 0.0));



    // light
    //spheres.push_back(new Sphere<float>(Vec3<float>(0, 10, -17), 3, Vec3<float>(0), 0, 0, Vec3<float>(0.0, 0.5, 0.7)));

    render<float>(spheres);
    while (!spheres.empty()) {
        Sphere<float> *sph = spheres.back();
        spheres.pop_back();
        delete sph;
    }
    return 0;
}

