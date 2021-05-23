#include "AngleOLD.h"

// Angle::Angle() : angle(0) { }

Angle::Angle(polar_unit theta) : angle(theta) { }

// Angle::Angle(const Angle &other) : Angle(other.angle) { }

// Angle::Angle(Angle &&other) noexcept : Angle() { swap(*this, other); }

// Angle& Angle::operator=(Angle rhs)
// {
    // swap(*this, rhs);
    // return *this;
// }

// Angle& Angle::operator=(Angle &&rhs) noexcept
// {
    // swap(*this, rhs);
    // return *this;
// }

// void swap(Angle &first, Angle &second)
// {
    // std::swap(first.angle, second.angle);
// }

Angle& Angle::operator+=(const Angle &rhs)
{
    angle += rhs.angle;
    return *this;
}

Angle& Angle::operator-=(const Angle &rhs)
{
    angle -= rhs.angle;
    return *this;
}

Angle& Angle::operator*=(polar_unit rhs)
{
    angle *= rhs;
    return *this;
}

Angle& Angle::operator/=(polar_unit rhs)
{
    angle /= rhs;
    return *this;
}

Angle& Angle::operator%=(polar_unit rhs)
{
    //angle %= rhs;
    angle = std::fmod(angle, rhs);
    return *this;
}

Angle& Angle::operator++()
{
    angle++;
    return *this;
}

Angle Angle::operator++(int)
{
    Angle tmp(*this);
    operator++();
    return tmp;
}

Angle& Angle::operator--()
{
    angle--;
    return *this;
}

Angle Angle::operator--(int)
{
    Angle tmp(*this);
    operator--();
    return tmp;
}

Angle& Angle::rotate(polar_unit theta)
{
    angle += theta;
    clamp_angle();
    return *this;
}

void Angle::clamp_angle()
{
    *this %= 2*M_PI;
}