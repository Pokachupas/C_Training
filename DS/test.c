#include "DataStructures.h"

int main(){
    Matrix *matrix = createMatrix();
    setLinearSystem(matrix,2);
    showLinearSystem(*matrix);
    freeMatrix(matrix);
    printf("Adios...\n");

    return 0;
}