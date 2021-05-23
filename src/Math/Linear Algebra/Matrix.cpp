#include "Math/Linear Algebra/Matrix.h"
#include "Math/Geometry/Vector2D.h"
#include "Math/MathHelper.h"
#include <cassert>
#include <cmath>
#include <utility>
// #include <functional>

Matrix::Matrix
(
    matrix_unit m00, matrix_unit m01, matrix_unit m02,
    matrix_unit m10, matrix_unit m11, matrix_unit m12,
    matrix_unit m20, matrix_unit m21, matrix_unit m22
) : m_inner
{
    m00, m01, m02,
    m10, m11, m12,
    m20, m21, m22
} { }

const Matrix Matrix::zero()
{
    return Matrix();
}

const Matrix Matrix::identity()
{
    return Matrix
    (
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

Matrix& Matrix::operator*=(matrix_unit scalar)
{
    for (auto i : m_inner)
    {
        i *= scalar;
    }
    return (*this);
}

//matrix_unit Matrix::operator()(unsigned int row, unsigned int col) const
const matrix_unit& Matrix::operator()(unsigned int row, unsigned int col) const
{
    //return (*this)(row, col);
    assert((row >= m_dim || col >= m_dim) && "Matrix indices out of range");
    return m_inner[row * m_dim + col];
}

//matrix_unit& Matrix::operator()(unsigned int row, unsigned int col)
matrix_unit& Matrix::operator()(unsigned int row, unsigned int col)
{
    return const_cast<matrix_unit&>(std::as_const(*this).operator()(row, col));
    //assert((row >= m_dim || col >= m_dim) && "Matrix indices out of range");
    //return m_inner[row * m_dim + col];
}

// matrix_unit&

Vector2D Matrix::right() const { return Vector2D((*this)(0,0), (*this)(0,1)); }
void Matrix::set_right(const Vector2D& value) { (*this)(0,0) = value.x; (*this)(0,1) = value.y; }
Vector2D Matrix::left() const { return Vector2D(-(*this)(0,0), -(*this)(0,1)); }
void Matrix::set_left(const Vector2D& value) { (*this)(0,0) = -value.x; (*this)(0,1) = -value.y; }
Vector2D Matrix::up() const { return Vector2D((*this)(1,0), (*this)(1,1)); }
void Matrix::set_up(const Vector2D& value) { (*this)(1,0) = value.x; (*this)(1,1) = value.y; }
Vector2D Matrix::down() const { return Vector2D(-(*this)(1,0), -(*this)(1,1)); }
void Matrix::set_down(const Vector2D& value) { (*this)(1,0) = -value.x; (*this)(1,1) = -value.y; }
Vector2D Matrix::translation() const { return Vector2D((*this)(0,2), (*this)(1,2)); }

void Matrix::decompose(Vector2D& translation, Vector2D& scale, polar_unit& rotation)
{
    translation = Matrix::translation();

    scale = Vector2D(sgn((*this)(0,0)) * sqrt(pow((*this)(0,0), 2) + pow((*this)(0,1), 2)), 
                    sgn((*this)(1,1)) * sqrt(pow((*this)(1,0), 2) + pow((*this)(1,1), 2)));

    rotation = atan2((*this)(1,0), (*this)(1,1));
}

matrix_unit Matrix::determinant2x2(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) const
{
    return (*this)(row1, col1) * (*this)(row2, col2) - (*this)(row1, col2) * (*this)(row2, col1);
}

matrix_unit Matrix::determinant() const
{
    return (*this)(0,0) * determinant2x2(1,1,2,2) - (*this)(0,1) * determinant2x2(1,0,2,2) + (*this)(0,2) * determinant2x2(1,0,2,1);
}

Matrix Matrix::create_rotation(polar_unit theta)
{
    Matrix result;
    create_rotation(theta, result);
    return result;
}

void Matrix::create_rotation(polar_unit theta, Matrix& result)
{
    result = identity();
    matrix_unit cosine = cos(theta);
    matrix_unit sine = sin(theta);
    result(0,0) = cosine;
    result(0,1) = -sine;
    result(1,0) = sine;
    result(1,1) = cosine;
}

Matrix Matrix::create_scale(coord_unit scale)
{
    Matrix result;
    create_scale(scale, scale, result);
    return result;
}

void Matrix::create_scale(coord_unit scale, Matrix& result)
{
    create_scale(scale, scale, result);
}

Matrix Matrix::create_scale(Vector2D scale)
{
    Matrix result;
    create_scale(scale.x, scale.y, result);
    return result;
}

void Matrix::create_scale(Vector2D scale, Matrix& result)
{
    create_scale(scale.x, scale.y, result);
}

Matrix Matrix::create_scale(coord_unit x_scale, coord_unit y_scale)
{
    Matrix result;
    create_scale(x_scale, y_scale, result);
    return result;
}

void Matrix::create_scale(coord_unit x_scale, coord_unit y_scale, Matrix& result)
{
    result = zero();
    result(0,0) = x_scale;
    result(1,1) = y_scale;
    result(2,2) = 1;
}

Matrix Matrix::create_translation(Vector2D pos)
{
    Matrix result;
    create_translation(pos.x, pos.y, result);
    return result;
}

void Matrix::create_translation(Vector2D pos, Matrix& result)
{
    create_translation(pos.x, pos.y, result);
}

Matrix Matrix::create_translation(coord_unit x_pos, coord_unit y_pos)
{
    Matrix result;
    create_translation(x_pos, y_pos, result);
    return result;
}

void Matrix::create_translation(coord_unit x_pos, coord_unit y_pos, Matrix& result)
{
    result = identity();
    result(0,2) = x_pos;
    result(1,2) = y_pos;
}

