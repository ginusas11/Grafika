#include "stack.h"

void init_stack(MatrixStack* stack){
	stack->top = -1;
}

int push_matrix(MatrixStack* stack, float matrix[3][3]) {
	if(stack->top >= STACK_SIZE - 1){
		printf("Stack overflow!"\n);
		return 0;
		}
		
	stack->++;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			stack->data[stack->top][i][j] = matrix[i][j];
		}
	}
	
	return 1;
}
	
int pop_matrix(MatrixStack* stack, float matrix[3][3]) {
    if (stack->top < 0) {
        printf("Stack underflow!\n");
        return 0;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrix[i][j] = stack->data[stack->top][i][j];
		}
	}

    stack->top--;

    return 1;
}