#include "Math/Linear Algebra/MatrixFactory.h"
#include "Math/Linear Algebra/Matrix.h"
#include "Math/Geometry/Vector2D.h"
#include <cmath>

const Matrix create_zero_matrix()
{
    return Matrix();
}
const Matrix create_identity_matrix()
{
    return Matrix
    (
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

Matrix create_rotation_matrix(polar_unit theta)
{
    Matrix result = create_identity_matrix();
    matrix_unit cosine = cos(theta);
    matrix_unit sine = sin(theta);
    result(0,0) = cosine;
    result(0,1) = -sine;
    result(1,0) = sine;
    result(1,1) = cosine;
    return result;
}
void create_rotation_matrix(polar_unit theta, Matrix& result)
{
    result = create_rotation_matrix(theta);
}

Matrix create_scale_matrix(coord_unit scale)
{
    Matrix result;
    create_scale_matrix(scale, scale, result);
    return result;
}
void create_scale_matrix(coord_unit scale, Matrix& result);
Matrix create_scale_matrix(Vector2D scale);
void create_scale_matrix(Vector2D scale, Matrix& result);
Matrix create_scale_matrix(coord_unit x_scale, coord_unit y_scale);
void create_scale_matrix(coord_unit x_scale, coord_unit y_scale, Matrix& result);

Matrix create_translation_matrix(Vector2D pos);
void create_translation_matrix(Vector2D pos, Matrix& result);
Matrix create_translation_matrix(coord_unit x_pos, coord_unit y_pos);
void create_translation_matrix(coord_unit x_pos, coord_unit y_pos, Matrix& result);







