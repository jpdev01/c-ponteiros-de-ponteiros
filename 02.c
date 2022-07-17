#include <stdio.h>

int scanBirthMonthNumber() {
    int birthMonthNumber;
    int initialValidMonth = 1, finalValidMonth = 12;
    do {
        printf("Informe o mês que nasceu em valor numérico: ");
        scanf("%i", &birthMonthNumber);
    } while (birthMonthNumber < initialValidMonth || birthMonthNumber > finalValidMonth);

    return birthMonthNumber;
}

void main() {
    char *monthsNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December"};
    int birthMonthNumber = scanBirthMonthNumber();

    printf("You were born in %s", monthsNames[birthMonthNumber - 1]);
}