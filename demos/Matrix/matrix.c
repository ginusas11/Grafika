#include <math.h>
#include "matrix.h"

#include <stdio.h>

void init_identity_matrix(float matrix[3][3]){	
	int i;
	int j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(i==j){
				matrix[i][j]=1.0;
			} else{
				matrix[i][j]=0.0;
			}
		}
	}
}

void skalar_szorzas(float matrix[3][3], float s){
	int i;
	int j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			matrix[i][j] *= s;
		}
	}
}

void multiply_matrices(const float m1[3][3],const float m2[3][3], float m[3][3]){
	int i;
	int j;
	int k;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{ 
			m[i][j] = 0.0;
			for(k=0; k<3; k++){
				m[i][j] += (m1[i][k] * m2[k][j]) ;
			}
			
		}
	}
}

void transform_point(float point[3], float t[3][3], float trans[3]){
	int i;
	int j;
	
	for(i=0; i<3; i++){
		trans[i] = 0.0;
		for(j=0 ;j<3; j++){
			trans[i] += t[i][j] * point[j];
		}
	}
}

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void scale(float t[3][3], float sx, float sy){
    float s[3][3] = {
        {sx, 0,  0},
        {0,  sy, 0},
        {0,  0,  1}
    };

    float result[3][3];
    multiply_matrices(t, s, result);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            t[i][j] = result[i][j];
}

void shift(float t[3][3], float dx, float dy){
    float s[3][3] = {
        {1, 0, dx},
        {0, 1, dy},
        {0, 0, 1}
    };

    float result[3][3];
    multiply_matrices(t, s, result);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            t[i][j] = result[i][j];
}

void rotate(float t[3][3], float angle){
    float r[3][3] = {
        {cos(angle), -sin(angle), 0},
        {sin(angle),  cos(angle), 0},
        {0,           0,          1}
    };

    float result[3][3];
    multiply_matrices(t, r, result);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            t[i][j] = result[i][j];
}