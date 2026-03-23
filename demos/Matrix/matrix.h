#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

void init_identity_matrix(float matrix[3][3]);

void skalar_szorzas(float matrix[3][3], float s);

void multiply_matrices(const float m1[3][3],const float m2[3][3], float m[3][3]);

void transform_point(float point[3], float t[3][3], float trans[3]);

void scale(float t[3][3], float sx, float sy);

void shift(float t[3][3], float dx, float dy);

void rotate(float t[3][3], float angle);


#endif // MATRIX_H

