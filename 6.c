#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **scanValues(int quantd) {
    int **pValues = malloc(sizeof(int **) * quantd);
    for (int rowIndex = 0; rowIndex < quantd; rowIndex++) {
        pValues[rowIndex] = malloc(sizeof(int *) * 1);
        printf("Informe o valor %i: ", rowIndex);
        scanf("%i", &pValues[rowIndex][0]);
    }

    return pValues;
}

int **fillWithDividers(int **array, int qtde) {
    for (int indexRow = 0; indexRow < qtde; indexRow++) {
        int value = array[indexRow][0];

        int divider = 1;
        int columnIndex = 1;
        do {
            if (value % divider == 0) {
                array[indexRow] = realloc(array[indexRow], sizeof(int *) * columnIndex);
                array[indexRow][columnIndex] = divider;
                columnIndex++;
            }
            divider++;
        } while (divider <= value);

        array[columnIndex + 1] = 0; // marcador de fim
    }
}

void printAll(int **array, int qtde) {
    for (int rowIndex = 0; rowIndex < qtde; rowIndex++) {
        int *row = array[rowIndex];
        int value, columnIndex = 0;
        do {
            value = row[columnIndex];
            printf("%i ", value);
            columnIndex++;
        } while (value != 0);
        printf("\n");
    }
}

void main() {
    int quantd;
    printf("Informe a quantidade de valores a serem informados: ");
    scanf("%i", &quantd);

    int **pValues = scanValues(quantd);
    fillWithDividers(pValues, quantd);
    printf("----- RESULTAD0 -----");
    printAll(pValues, quantd);
}