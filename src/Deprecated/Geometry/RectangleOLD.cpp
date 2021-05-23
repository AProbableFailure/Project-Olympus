#include "RectangleOLD.h"

Rectangle::Rectangle(const Vector2D pos, const Vector2D size, const Angle angle) : m_pos(pos), m_size(size), m_angle(angle) { }

std::vector<Vector2D> Rectangle::corners() const
{
    std::vector<Vector2D> vector2d_list = //= { m_pos, get_relative_vector(m_pos)};
                        { m_pos, 
                        Vector2D(m_pos.x + m_size.x, m_pos.y),
                        Vector2D(m_pos.x + m_size.x, m_pos.y + m_size.y),
                        m_pos + m_size
                        };

    // auto push_tracer = [&]()
    // {
        // tracer = get_relative_vector2d(tracer);
        // vector2d_list.push_back(tracer);
    // };
    // for (auto i = vector2d_list.begin(); i != vector2d_list.end(); ++i)
    // {
        // vector2d_list[i] = get_relative_rotation(vector2d_list[i]);   
    // }
    for (auto i : vector2d_list)
    {
        i = get_relative_rotation(i);
    }
    // vector2d_list.push_back(tracer);
    // tracer.x += m_size.x; 
    // push_tracer();
    // tracer.y += m_size.y; 
    // push_tracer();
    // tracer.x -= m_size.x;
    // push_tracer();

    return vector2d_list;
}

Vector2D Rectangle::center() const
{
    Vector2D not_rotated_center = this->m_pos + this->m_size / 2;
    return not_rotated_center.rotate_around(this->m_angle, this->m_pos);
}

coord_unit Rectangle::area() const
{
    return m_size.x * m_size.y;
}

coord_unit Rectangle::perimeter() const
{
    return 2*m_size.x + 2*m_size.y;
}

Vector2D Rectangle::get_relative_rotation(Vector2D vector) const
{
    return vector.rotate_around(m_angle, m_pos);
}

Vector2D Rectangle::get_inverse_rotation(Vector2D vector) const
{
    return vector.rotate_around(-1 * m_angle, m_pos);
}

bool Rectangle::surrounds(const Vector2D &vector) const
{
    Vector2D check = get_inverse_rotation(vector);// get_relative_vector2d(vector);
    return check.x > m_pos.x && check.x < m_pos.x + m_size.x 
        && check.y > m_pos.y && check.y < m_pos.y + m_size.y;
}

bool Rectangle::intersects(const Rectangle &other) const
{

}

void Rectangle::translate(const Vector2D &delta)
{
    m_pos += delta;
}

void Rectangle::scale(coord_unit scalar)
{
    m_size *= scalar;
}

void Rectangle::rotate(Angle theta, Anchor anchor)
{
    switch (anchor)
    {
    case Anchor::Corner:
        m_angle.rotate(theta);
        break;
    case Anchor::Center:
        this->m_pos.rotate_around(theta, center());
        break;
    default:
        break;
    }
}
