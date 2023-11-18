#include "DataStructures.c"


//Arrays

Array* createArray();
void freeArray(Array* array);
void setData(Array * array, int data);
void showArray(Array array);


//Matrices

Matrix* createMatrix();
void addRow(Matrix *matrix, Array array);
void showMatrix(Matrix matrix);
void freeMatrix(Matrix *matrix);


//Sitemas de ecuaciones lineales
void setLinearSystem(Matrix* matrix, int size);
void showLinearSystem(Matrix matrix);


