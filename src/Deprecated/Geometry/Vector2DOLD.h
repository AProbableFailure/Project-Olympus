#pragma once

// #define _USE_MATH_DEFINES
#include <cmath>
// #include <algorithm>
#include <iostream>

#include "AngleOLD.h"

typedef int coord_unit;

class Shape;

struct Vector2D
{
public:
    coord_unit x, y;

    // Vector2D();
    Vector2D(coord_unit x = 0, coord_unit y = 0);

    // ~Vector2D() = default;
    // Vector2D(const Vector2D &other);
    // Vector2D(Vector2D &&other) noexcept;
    // Vector2D& operator=(Vector2D rhs);
    // //Vector2D& operator=(const Vector2D &other) { return *this = Vector2D(other); }
    // Vector2D& operator=(Vector2D &&rhs) noexcept;

    // friend void swap(Vector2D &first, Vector2D &second);

    Vector2D& operator+=(const Vector2D &rhs);
    Vector2D& operator-=(const Vector2D &rhs);
    Vector2D& operator*=(coord_unit scalar);
    Vector2D& operator/=(coord_unit scalar);

    Vector2D& operator++();
    Vector2D operator++(int);
    Vector2D& operator--();
    Vector2D operator--(int);

    Vector2D zero();
    Vector2D one();

    Vector2D& rotate_around(const polar_unit theta, const Vector2D &anchor);
    friend Vector2D rotate_around(Vector2D vector, const polar_unit theta, const Vector2D &anchor);
    
    inline coord_unit length() const;
    Vector2D& normalize();

    bool is_inside(Shape &shape);
};

inline bool operator==(const Vector2D &lhs, const Vector2D &rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline bool operator!=(const Vector2D &lhs, const Vector2D &rhs) { return !operator==(lhs, rhs); }

inline Vector2D operator+(Vector2D lhs, const Vector2D &rhs) { lhs += rhs; return lhs; }
inline Vector2D operator-(Vector2D lhs, const Vector2D &rhs) { lhs -= rhs; return lhs; }
inline Vector2D operator*(Vector2D vector, coord_unit scalar) { vector *= scalar; return vector;}
inline Vector2D operator/(Vector2D vector, coord_unit scalar) { vector /= scalar; return vector;}

inline std::ostream& operator<<(std::ostream &os, const Vector2D &vector)
{
    os << "(x: " << vector.x << ", y: " << vector.y << ")" << std::endl;
    return os;
}

inline coord_unit dot_product(const Vector2D &lhs, const Vector2D &rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
//inline Vector2D cross_product(const Vector2D &lhs, const Vector2D &rhs) { return lhs.x * }