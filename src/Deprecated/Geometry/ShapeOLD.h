#pragma once

#include <math.h>
#include <algorithm>
#include <iostream>

// #include "Angle.h"
#include "Vector2DOLD.h"

//struct Vector2D;
struct Angle;

enum class Anchor
{
    Corner, Center
};

class Shape
{
public: 
    virtual Vector2D center() const = 0;

    virtual coord_unit area() const = 0;
    virtual coord_unit perimeter() const = 0;

    virtual bool surrounds(const Vector2D &vector) const = 0;

    virtual void translate(const Vector2D &delta) = 0;
    virtual void scale(coord_unit scalar) = 0;
    virtual void rotate(Angle theta, Anchor anchor = Anchor::Corner) = 0;
};