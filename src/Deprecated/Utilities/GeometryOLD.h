#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

typedef int coord_unit; // coordinate unit
typedef double polar_unit;

struct Vector
{
    coord_unit x;
    coord_unit y;

    Vector operator+ (Vector const & obj) { return Vector { x + obj.x, y + obj.y }; }
    Vector operator- (Vector const & obj) { return Vector { x - obj.x, y - obj.y }; }
    Vector operator* (coord_unit const & scalar) { return Vector { x * scalar, y * scalar }; }
    Vector operator/ (coord_unit const & scalar) { return Vector { x / scalar, y / scalar }; } 
    // Vector operator* (Vector const &obj) { return Vector { x * obj.x, y * obj.y }; }
    // Vector operator/ (Vector const &obj) { return Vector { x / obj.x, y / obj.y }; }

    Vector & operator+= (Vector const & obj) { x += obj.x; y += obj.y; return *this; }
    Vector & operator-= (Vector const & obj) { x -= obj.x; y -= obj.y; return *this; }

    // Vector RelativeVector(Vector v2)
    // {
        // return *this + v2;
    // }

    Vector & RotateAround(Vector v2, polar_unit theta);
    // {
        // Vector diff = *this - v2;
        // x = v2.x + (diff.x) * (coord_unit)cos(theta) + (diff.y) * (coord_unit)sin(theta);
        // y = v2.y - (diff.x) * (coord_unit)sin(theta) + (diff.y) * (coord_unit)cos(theta);
        // return *this;
        // // return Vector
        // // {
            // // x + (v2.x - x) * (coord_unit)cos(theta) + (v2.y - y) * (coord_unit)sin(theta),
            // // y - (v2.x - x) * (coord_unit)sin(theta) + (v2.y - y) * (coord_unit)cos(theta)
        // // };
    // }
};

struct Angle
{
    polar_unit angle;

    operator polar_unit() const { return angle; }

    void Rotate(polar_unit theta)
    {
        angle += theta;
        while (angle >= 2*M_PI)
        {
            angle -= 2*M_PI;
        }
    }    
};

enum class Anchor
{
    Corner,
    Center
    // TopLeft,
    // TopRight,
    // BottomLeft,
    // BottomRight
};

class Shape
{

};

class Rectangle
{
private:
    Vector _pos;
    Vector _size;
    Angle _angle;

public:
    Vector & pos() { return _pos; }
    Vector & size() { return _size; }
    Angle & angle() { return _angle; }

    Vector center() 
    { 
        Vector notRotatedCenter = this->_pos + this->_size / 2;
        return notRotatedCenter.RotateAround(this->_pos, this->_angle);
    }

    void Translate();
    void Scale();
    void Rotate(polar_unit theta, Anchor anchor = Anchor::Corner);
};