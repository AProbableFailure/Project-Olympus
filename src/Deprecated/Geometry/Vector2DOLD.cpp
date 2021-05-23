#include "ShapeOLD.h"
#include "Vector2DOLD.h"

// Vector2D::Vector2D() : x(0), y(0) { }

Vector2D::Vector2D(coord_unit x, coord_unit y) : x(x), y(y) { }

// Vector2D::Vector2D(const Vector2D &other) : Vector2D(other.x, other. y) { }

// Vector2D::Vector2D(Vector2D &&other) noexcept : Vector2D() { swap(*this, other); }

// Vector2D& Vector2D::operator=(Vector2D rhs)
// {
    // swap(*this, rhs);
    // return *this;
// }

// Vector2D& Vector2D::operator=(Vector2D &&rhs) noexcept
// {
    // swap(*this, rhs);
    // return *this;
// }

// void swap(Vector2D &first, Vector2D &second)
// {
    // std::swap(first.x, second.x);
    // std::swap(first.y, second.y);
// }

Vector2D& Vector2D::operator+=(const Vector2D &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector2D& Vector2D::operator*=(coord_unit scalar)
{
    x *= scalar;
    y /= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(coord_unit scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

Vector2D& Vector2D::operator++()
{
    x++; 
    y++;
    return *this;
}

Vector2D Vector2D::operator++(int)
{
    Vector2D tmp(*this);
    operator++();
    return tmp;
}

Vector2D& Vector2D::operator--()
{
    x--; 
    y--;
    return *this;
}

Vector2D Vector2D::operator--(int)
{
    Vector2D tmp(*this);
    operator--();
    return tmp;
}

Vector2D Vector2D::zero() { return Vector2D(0, 0); }

Vector2D Vector2D::one() { return Vector2D(1, 1); }

Vector2D& Vector2D::rotate_around(const polar_unit theta, const Vector2D &anchor)
{
    double sine = sin(theta);
    double cosine = cos(theta); 

    Vector2D diff = *this - anchor;
    x = anchor.x + (diff.x) * cosine + (diff.y) * sine;
    y = anchor.y - (diff.x) * sine + (diff.y) * cosine;
    return *this;
}

Vector2D rotate_around(Vector2D vector, const polar_unit theta, const Vector2D &anchor)
{
    vector.rotate_around(theta, anchor);
    return vector;
}

coord_unit Vector2D::length() const
{
    return std::sqrt(x*x + y*y);
}

Vector2D& Vector2D::normalize()
{
    return (*this /= length());
}

bool Vector2D::is_inside(Shape &shape)
{
    return shape.surrounds(*this);
}