#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 100

typedef struct{
	float data[STACK_SIZE][3][3];
	int top;
} MatrixStack;

void init_stack(MatrixStack* stack);

int push_matrix(MatrixStack* stack, float matrix[3][3]);

int pop_matrix(MatrixStack* stack, float matrix[3][3]);

#endif