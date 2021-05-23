#pragma once

#include "Math/Units.h"

#include <iostream>
#include <vector>

struct Vector2D;

class Matrix
{
public:
    // matrix_unit m11, m12, m13, m21, m22, m23, m31, m32, m33;
    Matrix
    (
        matrix_unit m00 = 0, matrix_unit m01 = 0, matrix_unit m02 = 0,
        matrix_unit m10 = 0, matrix_unit m11 = 0, matrix_unit m12 = 0,
        matrix_unit m20 = 0, matrix_unit m21 = 0, matrix_unit m22 = 0
    );

    // MAKE RULE OF FIVE

    const static Matrix zero();
    const static Matrix identity();

    Matrix& operator*=(matrix_unit scalar);

    const matrix_unit& operator()(unsigned int row, unsigned int col) const;
    matrix_unit& operator()(unsigned int row, unsigned int col);
    //matrix_unit operator()(unsigned int row, unsigned int col) const;
    //matrix_unit& operator()(unsigned int row, unsigned int col);


    Vector2D right() const;   //  m00,  m01  [ x]
    void set_right(const Vector2D& value);
    Vector2D left() const;    // -m01, -m01  [-x]
    void set_left(const Vector2D& value);
    Vector2D up() const;      //  m10,  m11  [ y]
    void set_up(const Vector2D& value);
    Vector2D down() const;    // -m10, -m11  [-y]
    void set_down(const Vector2D& value);
    Vector2D translation() const;   //  m02,  m12

    void decompose(Vector2D& translation, Vector2D& scale, polar_unit& rotation);

    matrix_unit determinant2x2(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) const;
    matrix_unit determinant() const;

    static Matrix create_rotation(polar_unit theta);
    static void create_rotation(polar_unit theta, Matrix& result);

    static Matrix create_scale(coord_unit scale);
    static void create_scale(coord_unit scale, Matrix& result);
    static Matrix create_scale(Vector2D scale);
    static void create_scale(Vector2D scale, Matrix& result);
    static Matrix create_scale(coord_unit x_scale, coord_unit y_scale);
    static void create_scale(coord_unit x_scale, coord_unit y_scale, Matrix& result);

    static Matrix create_translation(Vector2D pos);
    static void create_translation(Vector2D pos, Matrix& result);
    static Matrix create_translation(coord_unit x_pos, coord_unit y_pos);
    static void create_translation(coord_unit x_pos, coord_unit y_pos, Matrix& result);

private:
    std::vector<matrix_unit> m_inner;
    const static unsigned int m_dim = 3;
};

inline std::ostream& operator<<(std::ostream &os, const Matrix &value)
{
    os  << "[ " << value(0,0) << "  " << value(0,1) << "  " << value(0,2) << " ]" << std::endl
        << "[ " << value(1,0) << "  " << value(1,1) << "  " << value(1,2) << " ]" << std::endl
        << "[ " << value(2,0) << "  " << value(2,1) << "  " << value(2,2) << " ]" << std::endl;
    return os;
}