#include "matrix.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);
	
	skalar_szorzas(a, 2.0f);
    printf("\nA * 2:\n");
    print_matrix(a);
	
	float t[3][3];
    init_identity_matrix(t);
	
	scale(t, 2, 2);
    shift(t, 1, 1);
    rotate(t, M_PI/4);
	
	printf("\nTranszformacios matrix:\n");
    print_matrix(t);
	
	float p[3] = {1, 1, 1};
    float result[3];
	
	transform_point(p, t, result);

	printf("\nEredeti pont: (%f, %f)\n", p[0], p[1]);
    printf("Transzformalt pont: (%f, %f)\n", result[0], result[1]);

	return 0;
}

