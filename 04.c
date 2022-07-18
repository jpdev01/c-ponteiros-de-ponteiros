#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *calculateSecondaryDiagonal( int **matriz, int order);
void populateArray(int ** array, int arrayOrder);
void printArray(int *secondaryDiagonal, int order);

void main() {
    int arrayOrder;
    int **array;
    printf("Informe o tamanho (ordem) da matriz:");
    scanf("%i", &arrayOrder);

    array = malloc(sizeof(int **) * arrayOrder);

    printf("Informe o valor da linha e coluna:\n");
    populateArray(array, arrayOrder);
    int *secondaryDiagonal = calculateSecondaryDiagonal(array, arrayOrder);

    printf("Valores da diagonal secundária: \n");
    printArray(secondaryDiagonal, arrayOrder);
}

void populateArray(int ** array, int arrayOrder) {
    for (int rowIndex = 0; rowIndex < arrayOrder; rowIndex++) {
        array[rowIndex] = malloc(sizeof(int *) * arrayOrder);
        for (int columnIndex = 0; columnIndex < arrayOrder; columnIndex++) {
            printf("%i x %i:", rowIndex, columnIndex);
            scanf("%i", &array[rowIndex][columnIndex]);
        }
    }
}

int *calculateSecondaryDiagonal(int **array, int order) {
    int *secondaryDiagonal;
    secondaryDiagonal = malloc(sizeof(int *) * order);
    for (int rowIndex = 0; rowIndex < order; rowIndex++) {
        int columnIndex = (order - 1) - rowIndex;
        secondaryDiagonal[rowIndex] = array[rowIndex][columnIndex];
    }

    return secondaryDiagonal;
}

void printArray(int *array, int order) {
    for (int index = 0; index < order; index++) {
        printf("%i", array[index]);
    }
}