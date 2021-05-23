#pragma once

#include <cmath>

#include "ShapeOLD.h"
#include "Vector2DOLD.h"
#include "AngleOLD.h"

class Triangle : Shape
{
public:
    Triangle(const Vector2D a = Vector2D(), const Vector2D b = Vector2D(), const Vector2D c = Vector2D());

    Vector2D& pos() { return m_a ;}

    Vector2D center() const override;

    coord_unit area() const override;
    coord_unit perimeter() const override;

    bool surrounds(const Vector2D &vector) const override;
    bool intersects(const Triangle &other) const;

    void translate(const Vector2D &delta) override;
    void scale(coord_unit scalar) override;
    void rotate(Angle theta, Anchor anchor = Anchor::Corner) override;

private:
    Vector2D m_a, m_b, m_c;
};