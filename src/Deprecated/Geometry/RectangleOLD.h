#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include "ShapeOLD.h"
#include "Vector2DOLD.h"
#include "AngleOLD.h"

class Rectangle : Shape
{
public:
    Rectangle(const Vector2D pos = Vector2D(), const Vector2D size = Vector2D(), const Angle angle = 0);

    Vector2D& pos() { return m_pos; }
    Vector2D& size() { return m_size; }
    Angle& angle() { return m_angle; }

    std::vector<Vector2D> corners() const;
    Vector2D center() const override;

    coord_unit area() const override;
    coord_unit perimeter() const override;

    Vector2D get_relative_rotation(Vector2D vector) const; // Like Vector2D::rotate_around but with a predefined angle
    Vector2D get_inverse_rotation(Vector2D vector) const;

    bool surrounds(const Vector2D &vector) const override;
    bool intersects(const Rectangle &other) const;

    void translate(const Vector2D &delta) override;
    void scale(coord_unit scalar) override;
    void rotate(Angle theta, Anchor anchor = Anchor::Corner) override;

private:
    Vector2D m_pos, m_size;
    Angle m_angle;
};