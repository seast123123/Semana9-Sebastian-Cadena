#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;

    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &columnas);

    // Asignar memoria para la matriz
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Generar números aleatorios y llenar la matriz
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 101;
        }
    }

    printf("\nMatriz original:\n");
    imprimirMatriz(matriz, filas, columnas);

    printf("\nMatriz transpuesta:\n");
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria de la matriz
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

