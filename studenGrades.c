#include <stdio.h>
#include <stdlib.h>

void populateGrades(float **studentGrades, int numberOfStudents, int numberOfGradesPerStudent) {
    for (int studentIndex = 0; studentIndex < numberOfStudents; studentIndex++) {
        studentGrades[studentIndex] = malloc(sizeof (float *) * numberOfGradesPerStudent);
        for (int gradeIndex = 0; gradeIndex < numberOfGradesPerStudent; gradeIndex++) {
            printf("Informe a nota %i do aluno %i: ", gradeIndex + 1, studentIndex + 1);
            scanf("%f", &studentGrades[studentIndex][gradeIndex]);
        }
    }
}

void printGrades(float **studentGrades, int numberOfStudents, int numberOfGradesPerStudent) {
    for (int studentIndex = 0; studentIndex < numberOfStudents; studentIndex++) {
        printf("---------NOTAS DO ESTUDANTE %i -------------\n", studentIndex + 1);
        for (int gradeIndex = 0; gradeIndex < numberOfGradesPerStudent; gradeIndex++) {
            printf("%.2f\n", studentGrades[studentIndex][gradeIndex]);
        }
    }
}

void freePointerToPointer(float **doublePointer, int numberOfRows) {
    for (int index = 0; index < numberOfRows; index++) {
        free(doublePointer[index]);
    }
}

void main() {
    int numberOfStudents = 5;
    float **studentGrades;
    studentGrades = (float **)malloc(sizeof(float *) * numberOfStudents);

    int numberOfGradesPerStudent;
    printf("Informe a quantidade de notas de cada estudante: ");
    scanf("%i", &numberOfGradesPerStudent);

    populateGrades(studentGrades, numberOfStudents, numberOfGradesPerStudent);
    printGrades(studentGrades, numberOfStudents, numberOfGradesPerStudent);
    freePointerToPointer(studentGrades, numberOfStudents);
}
