#include "GeometryOLD.h"


Vector & Vector::RotateAround(Vector v2, polar_unit theta)
{
    Vector diff = *this - v2;
    x = v2.x + (diff.x) * (coord_unit)cos(theta) + (diff.y) * (coord_unit)sin(theta);
    y = v2.y - (diff.x) * (coord_unit)sin(theta) + (diff.y) * (coord_unit)cos(theta);
    return *this;
    // return Vector
    // {
        // x + (v2.x - x) * (coord_unit)cos(theta) + (v2.y - y) * (coord_unit)sin(theta),
        // y - (v2.x - x) * (coord_unit)sin(theta) + (v2.y - y) * (coord_unit)cos(theta)
    // };
}


void Rectangle::Rotate(polar_unit theta, Anchor anchor)
{
    switch (anchor)
    {
    case Anchor::Corner:
        _angle.Rotate(theta);
        break;
    case Anchor::Center:

        //this = pos
        this->_pos.RotateAround(center(), theta);
        _angle.Rotate(theta);
        break;
    default:
        break;
    }

    // Translate point to origin
    // coord_unit xOriginRel = pos().x - center().x;
    // coord_unit yOriginRel = pos().y - center().y;

    // Apply rotation
    // coord_unit rotatedX = xOriginRel * cos(theta) - yOriginRel * sin(theta);
    // coord_unit rotatedY = xOriginRel * sin(theta) + yOriginRel * cos(theta);

    // Translate back
    
}