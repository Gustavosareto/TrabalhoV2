#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHEQUES 50

// Função para verificar se o número já existe no vetor
int existe(int cheques[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (cheques[i] == num) {
            return 1; // O número existe
        }
    }
    return 0; // O número não existe
}

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor para ordenar
int particiona(int cheques[], int inicio, int fim) {
    int pivo = cheques[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (cheques[j] <= pivo) {
            i++;
            troca(&cheques[i], &cheques[j]);
        }
    }
    troca(&cheques[i + 1], &cheques[fim]);
    return i + 1;
}

// Função para ordenar
void ordenar(int cheques[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particiona(cheques, inicio, fim);
        ordenar(cheques, inicio, p - 1);
        ordenar(cheques, p + 1, fim);
    }
}

int main() {
    int cheques[MAX_CHEQUES];
    int i = 0;
    int num;

    srand(time(NULL));

    // Preenche o vetor com números aleatórios únicos entre 1 e 100
    while (i < MAX_CHEQUES) {
        num = rand() % 100 + 1;
        if (existe(cheques, i, num) == 0) { // Verifica se o número não existe
            cheques[i] = num;
            i++;
        }
    }

    printf("Cheques emitidos (ordem aleatoria, sem repetidos):\n");
    for (i = 0; i < MAX_CHEQUES; i++) {
        printf("%d ", cheques[i]);
    }
    printf("\n");

    ordenar(cheques, 0, MAX_CHEQUES - 1);

    printf("Cheques ordenados (ordem crescente):\n");
    for (i = 0; i < MAX_CHEQUES; i++) {
        printf("%d ", cheques[i]);
    }
    printf("\n");

    return 0;
}
