#pragma once

#include "Math/Units.h"
// #include "Math/Linear Algebra/"

class Matrix;
struct Vector2D;

const Matrix create_zero_matrix();
const Matrix create_identity_matrix();

Matrix create_rotation_matrix(polar_unit theta);
void create_rotation_matrix(polar_unit theta, Matrix& result);

Matrix create_scale_matrix(coord_unit scale);
void create_scale_matrix(coord_unit scale, Matrix& result);
Matrix create_scale_matrix(Vector2D scale);
void create_scale_matrix(Vector2D scale, Matrix& result);
Matrix create_scale_matrix(coord_unit x_scale, coord_unit y_scale);
void create_scale_matrix(coord_unit x_scale, coord_unit y_scale, Matrix& result);

Matrix create_translation_matrix(Vector2D pos);
void create_translation_matrix(Vector2D pos, Matrix& result);
Matrix create_translation_matrix(coord_unit x_pos, coord_unit y_pos);
void create_translation_matrix(coord_unit x_pos, coord_unit y_pos, Matrix& result);
