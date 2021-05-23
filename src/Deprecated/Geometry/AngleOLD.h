#pragma once

#define _USE_MATH_DEFINES
// #include <math.h>
#include <cmath>
// #include <algorithm>
#include <iostream>

typedef double polar_unit;

struct Angle
{
public:
    polar_unit angle;

    // Angle();
    Angle(polar_unit theta = 0);

    // ~Angle() = default;
    // Angle(const Angle &other);
    // Angle(Angle &&other) noexcept;
    // Angle& operator=(Angle rhs);
    // Angle& operator=(Angle &&rhs) noexcept;

    // friend void swap(Angle &first, Angle &second);

    Angle& operator+=(const Angle &rhs);
    Angle& operator-=(const Angle &rhs);
    Angle& operator*=(polar_unit rhs);
    Angle& operator/=(polar_unit rhs);
    Angle& operator%=(polar_unit rhs);

    Angle& operator++();
    Angle operator++(int);
    Angle& operator--();
    Angle operator--(int);

    operator polar_unit() const { return angle; }

    Angle& rotate(polar_unit theta);

private:
    void clamp_angle();
};

inline polar_unit to_radians(polar_unit degrees) { return degrees * M_PI / 180; }
inline polar_unit to_degrees(polar_unit radians) { return radians * 180 / M_PI; }

inline bool operator==(const Angle &lhs, const Angle &rhs) { return lhs.angle == rhs.angle; }
inline bool operator!=(const Angle &lhs, const Angle &rhs) { return !operator==(lhs, rhs); }
inline bool operator<(const Angle &lhs, const Angle &rhs) { return lhs.angle < rhs.angle; }
inline bool operator>(const Angle &lhs, const Angle &rhs) { return operator<(rhs, lhs); }
inline bool operator<=(const Angle &lhs, const Angle &rhs) { return !operator>(lhs, rhs); }
inline bool operator>=(const Angle &lhs, const Angle &rhs) { return !operator<(lhs, rhs); }

inline Angle operator+(Angle lhs, const Angle &rhs) { lhs += rhs; return lhs; }
inline Angle operator-(Angle lhs, const Angle &rhs) { lhs -= rhs; return lhs; }
inline Angle operator*(Angle lhs, polar_unit rhs) { lhs *= rhs; return lhs; }
inline Angle operator/(Angle lhs, polar_unit rhs) { lhs /= rhs; return lhs; }
inline Angle operator%(Angle lhs, polar_unit rhs) { lhs %= rhs; return lhs; }

inline std::ostream& operator<<(std::ostream &os, const Angle &angle)
{
    os << angle.angle << " radians, " << to_degrees(angle.angle) << " degrees";
    return os;
}
