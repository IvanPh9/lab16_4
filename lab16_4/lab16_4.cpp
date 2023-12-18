#include <stdio.h>
#include <stdlib.h>
#include <locale>

void fillSnakeMatrix(int** matrix, int m, int n) {
    int value = 1;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = value++;
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i][j] = value++;
            }
        }
    }
}
void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); //Українізація
    int m, n;
    do {
        printf("Введiть кiлькiсть рядкiв (M): ");
        scanf_s("%d", &m);
        printf("Введiть кiлькiсть стовпцiв (N): ");
        scanf_s("%d", &n);
    } while (m <= 0 || n <= 0);
    // Динамічне виділення пам'яті для матриці
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    fillSnakeMatrix(matrix, m, n);
    printf("Матриця 'змiйка':\n");
    printMatrix(matrix, m, n);

    // Звільнення виділеної пам'яті
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}