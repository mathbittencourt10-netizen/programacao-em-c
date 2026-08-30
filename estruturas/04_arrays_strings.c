/*
 * 04 — Arrays e Strings
 * Demonstra: vetores, matrizes, bubble sort, manipulação de strings
 * Compilar: gcc 04_arrays_strings.c -o 04_arrays_strings
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Protótipos */
void bubble_sort(int arr[], int n);
void exibir_array(int arr[], int n);

int main() {
    /* ── Array unidimensional ────────────────────────────────── */
    printf("=== Arrays — Bubble Sort ===\n");
    int nums[] = {64, 34, 25, 12, 22, 11, 90};
    int tam = sizeof(nums) / sizeof(nums[0]);

    printf("Antes  : ");
    exibir_array(nums, tam);
    bubble_sort(nums, tam);
    printf("Depois : ");
    exibir_array(nums, tam);

    /* Busca linear */
    int alvo = 25;
    printf("Buscando %d... ", alvo);
    int encontrado = 0;
    for (int i = 0; i < tam; i++) {
        if (nums[i] == alvo) {
            printf("encontrado na posição %d\n\n", i);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("não encontrado\n\n");

    /* ── Matriz 3×3 ─────────────────────────────────────────── */
    printf("=== Matriz 3x3 ===\n");
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int soma_diagonal = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d ", mat[i][j]);
        }
        soma_diagonal += mat[i][i];
        printf("\n");
    }
    printf("Soma da diagonal principal: %d\n\n", soma_diagonal);

    /* ── Strings ────────────────────────────────────────────── */
    printf("=== Strings ===\n");
    char nome[50];
    printf("Digite seu nome: ");
    scanf("%49s", nome);

    printf("Original   : %s\n",  nome);
    printf("Tamanho    : %zu\n", strlen(nome));

    /* Converter para maiúsculas */
    printf("Maiúsculas : ");
    for (int i = 0; nome[i]; i++) putchar(toupper(nome[i]));
    printf("\n");

    /* Inverter string */
    printf("Invertido  : ");
    for (int i = strlen(nome) - 1; i >= 0; i--) putchar(nome[i]);
    printf("\n");

    /* Concatenação */
    char saudacao[100] = "Olá, ";
    strcat(saudacao, nome);
    strcat(saudacao, "!");
    printf("Saudação   : %s\n", saudacao);

    return 0;
}

/* Ordena em ordem crescente usando Bubble Sort */
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp    = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void exibir_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
