#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convertCharToInt(char number) {
    return atoi(number);
}

void main(int argc, char * argv[]) {
    int *value, sum = 0;

    value = malloc(sizeof(int *) * argc);

    for (int index = 0; index < argc -1; index++) {
        value[index] = convertCharToInt(argv[index]);
        printf("\nValor: %i", value[index]);
        sum += value[index];
    }

    printf("\nSoma: %d",sum);
}