#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int len;
    int cap;
    int *data;
}Array;

void freeArray(Array* array){
    free(array->data);
    free(array);
}

Array* createArray(){
    Array* array = (Array*)malloc(sizeof(Array));
    if(array == NULL){
        printf("Error de asignacion de memoria para el array.\n");
        exit(EXIT_FAILURE);
    }else{
        array->data = (int *)malloc(sizeof(int));
        if(array->data == NULL){
            printf("Error de asignación de memoria para datos.\n");
            exit(EXIT_FAILURE);
        }else{
            array->len = 0;
            array->cap = 1;
        }
        return(array);
    }
}

void setData(Array * array, int data){
    if(array == NULL || array->data == NULL){
        printf("El arreglo no esta asignado.\n");
        exit(EXIT_FAILURE);
    }else{
        if(array->cap == array->len){
            void* temp = (int *)realloc(array->data, (1 + array->cap)*sizeof(int));
            if(temp == NULL){
                printf("Ocurrio un error en la asignacion de memoria.\n");
                exit(EXIT_FAILURE);
            }else{
                array->cap++;
                array->data = (int *)temp;
                array->data[array->len] = data;
                array->len++;
            }
        }else{
            array->data[array->len] = data;
            array->len++;
        }
    }
}

void showArray(Array array){
    int i = 0;
    for(i = 0; i < array.len; i++){
        if(i == array.len - 1){
            printf("= %i\n",array.data[i]);
        }
        else if(i == array.len - 2){
            printf("%ix_%i ", array.data[i], i);
        }else{
            printf("%ix_%i + ",array.data[i], i);
        }
    }
}

typedef struct{
    int numRows;
    Array *rows;
}Matrix;

Matrix* createMatrix(){
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    if(matrix == NULL){
        printf("Error en la asignacion de memoria para matriz.\n");
        exit(EXIT_FAILURE);
    }else{
        matrix->rows = (Array*)malloc(sizeof(Array));
        if(matrix->rows == NULL){
            printf("Error en asignacion de memorias para datos m.\n");
            exit(EXIT_FAILURE);
        }else{
            matrix->numRows = 0;
            return matrix;
        }
    }
}

void addRow(Matrix *matrix, Array array){
    if(matrix == NULL){
        printf("La matriz no existe.\n");
        exit(EXIT_FAILURE);
    }else{
        if(matrix->rows == NULL){
            printf("Inicializando arreglo de filas...\n");
            matrix->rows = (Array*)malloc(sizeof(Array));
        }
        else if(matrix->numRows == 0){
            matrix->rows[matrix->numRows] = array;
            matrix->numRows++;
        }else{
            void *temp = (Array*)realloc(matrix->rows, (1 + matrix->numRows)*sizeof(Array));
            if(temp == NULL){
                printf("Error en asignacion de memoria. No se pueden añadir mas filas.\n");
                exit(EXIT_FAILURE);
            }else{
                matrix->rows = (Array*)temp;
                matrix->rows[matrix->numRows] = array;
                matrix->numRows++;
            }
        }
    }
}

void showMatrix(Matrix matrix){
    printf("{\n");
    int i;
    for(i = 0; i < matrix.numRows; i++){
        showArray(matrix.rows[i]);
    }
    printf("}\n");
}

void freeMatrix(Matrix *matrix){
    int i;
    for(i = 0; i < matrix->numRows; i++){
        free(matrix->rows[i].data);
    }
    free(matrix->rows);
    free(matrix);
}
void setLinearSystem(Matrix* matrix, int size){
    if(matrix == NULL){
        printf("No existe la matrix.\n");
        exit(EXIT_FAILURE);
    }else{
        matrix->rows = (Array*)calloc(size,sizeof(Array));
        if(matrix->rows == NULL){
            printf("Error en asignacion de memoria para el sistema. \n");
            exit(EXIT_FAILURE);
        }else{
            Array *array = NULL;
            int i, j, temp;
            for(i = 0; i < size; i++){
                array = createArray();
                if(array == NULL){
                printf("Error en asignacion de memoria.\n");
                exit(EXIT_FAILURE);
            }
                for(j = 0; j < size + 1; j++){
                    printf("Ingrese un valor para la variable %i: ",j);
                    scanf("%i",&temp);
                    setData(array,temp);
                }
                addRow(matrix,*array);
                freeArray(array);
            }
        }
    }
}

void showLinearSystem(Matrix matrix){
    int size = matrix.numRows;
    int i;
    printf("[\n");
    for(i = 0; i < size; i++){
        showArray(matrix.rows[i]);
    }
    printf("]\n");
}
void solveMatrixAsLinearSystem(Matrix matrix){
    
}

