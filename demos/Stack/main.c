#include "stack.h"
#include "matrix.h"

int main() {
    MatrixStack stack;
    init_stack(&stack);

    float t[3][3];
    init_identity_matrix(t);

    printf("Kezdeti matrix:\n");
    print_matrix(t);

    //mentés
    push_matrix(&stack, t);

    //skálázás
    scale(t, 2, 2);
    printf("\nScale utan:\n");
    print_matrix(t);

    //mentés
    push_matrix(&stack, t);

    //eltolás
    shift(t, 3, 1);
    printf("\nShift utan:\n");
    print_matrix(t);

    //visszavonás (shift undo)
    pop_matrix(&stack, t);
    printf("\nPop utan (shift visszavonva):\n");
    print_matrix(t);

    //visszavonás (scale undo)
    pop_matrix(&stack, t);
    printf("\nPop utan (scale visszavonva):\n");
    print_matrix(t);

    return 0;
}