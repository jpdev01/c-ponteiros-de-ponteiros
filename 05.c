#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *getArrayColumn(int **pInt, int arrayB, int index);

int inputNumberOfRows(char *arrayName) {
    int numberOfRows;
    printf("Informe o número de linhas da matriz %s: ", arrayName);
    scanf("%i", &numberOfRows);

    return numberOfRows;
}

int inputNumberOfColumns(char *arrayName) {
    int numberOfColumns;
    printf("Informe o número de colunas da matriz %s: ", arrayName);
    scanf("%i", &numberOfColumns);

    return numberOfColumns;
}

int **inputArrayPointerToPointer(int numberOfRows, int numberOfColumns) {
    int **array;
    array = malloc(sizeof(int **) * numberOfRows);
    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
        array[rowIndex] = malloc(sizeof(int *) * numberOfColumns);
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
            printf("%i x %i: ", rowIndex, columnIndex);
            scanf("%i", &array[rowIndex][columnIndex]);
        }
    }

    return array;
}

int **multiplyArray(int **arrayA, int numberOfRowsArrayA, int numberOfColumnsArrayA, int **arrayB, int numberOfRowsArrayB, int numberOfColumnsArrayB) {
    int **resultArray;
    int numberOfRows = numberOfRowsArrayA, numberOfColumns = numberOfColumnsArrayB;
    resultArray = malloc(sizeof(int **) * numberOfRows);

    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
        resultArray[rowIndex] = malloc(sizeof(int *) * numberOfColumns);
        int *arrayARow = arrayA[rowIndex];

        for (int arrayBColumnIndex = 0; arrayBColumnIndex < numberOfRowsArrayB; arrayBColumnIndex++) {
            int *arrayBCols = getArrayColumn(arrayB, numberOfRowsArrayB, arrayBColumnIndex);
            int multValue = 0;
            for (int columnIndex = 0; columnIndex < numberOfRowsArrayB; columnIndex++) {
                int columnAValue = arrayARow[columnIndex];
                int columnArrayB = arrayBCols[columnIndex];

                multValue += columnAValue * columnArrayB;
            }
            resultArray[rowIndex][arrayBColumnIndex] = multValue;
        }
    }

    return resultArray;
}

int *getArrayColumn(int **originalArray, int numberOfRows, int columnIndex) {
    int *arrayResult;
    arrayResult = malloc(sizeof(int *) * numberOfRows);
    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
        arrayResult[rowIndex] = originalArray[rowIndex][columnIndex];
    }

    return arrayResult;
}

void printArray(int **array, int numberOfRows, int numberOfColumns) {
    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
            printf("%i ", array[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

void main() {
    int numberOfRows = inputNumberOfRows("A");
    int numberOfColumns = inputNumberOfColumns("A");
    int **arrayA = inputArrayPointerToPointer(numberOfRows, numberOfColumns);

    int numberOfRowsB = inputNumberOfRows("B");
    int numberOfColumnsB = inputNumberOfColumns("B");

    if (numberOfColumns != numberOfRowsB) {
        printf("O número de colunas da Matriz A deve ser igual ao número de linhas da matriz B");
        return;
    }
    int **arrayB = inputArrayPointerToPointer(numberOfRowsB, numberOfColumnsB);

    int **resultMultiply = multiplyArray(arrayA, numberOfRows, numberOfColumns, arrayB, numberOfRowsB, numberOfColumnsB);

    printf("Multiplicação da matriz %s x %s: \n", "A", "B");
    printArray(resultMultiply, numberOfRows, numberOfColumnsB);
}