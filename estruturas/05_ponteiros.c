/*
 * 05 — Ponteiros
 * Demonstra: declaração, endereços, aritmética de ponteiros,
 *            passagem por referência e alocação dinâmica
 * Compilar: gcc 05_ponteiros.c -o 05_ponteiros
 */
#include <stdio.h>
#include <stdlib.h>

/* Protótipos */
void trocar(int *a, int *b);
void dobrar(int *n);

int main() {
    /* ── Conceito básico ────────────────────────────────────── */
    printf("=== Ponteiros Básicos ===\n");
    int x = 42;
    int *p = &x;

    printf("Valor de x      : %d\n",  x);
    printf("Endereço de x   : %p\n",  (void *)&x);
    printf("p aponta para   : %p\n",  (void *)p);
    printf("Valor via *p    : %d\n\n", *p);

    /* Modificar via ponteiro */
    *p = 100;
    printf("Após *p = 100, x = %d\n\n", x);

    /* ── Passagem por referência ────────────────────────────── */
    printf("=== Passagem por Referência ===\n");
    int a = 5, b = 8;
    printf("Antes  — a: %d, b: %d\n", a, b);
    trocar(&a, &b);
    printf("Depois — a: %d, b: %d\n\n", a, b);

    int num = 7;
    printf("Antes de dobrar : %d\n", num);
    dobrar(&num);
    printf("Depois de dobrar: %d\n\n", num);

    /* ── Aritmética de ponteiros com arrays ─────────────────── */
    printf("=== Ponteiro e Array ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d  (endereço: %p)\n", i, *(ptr + i), (void *)(ptr + i));
    }

    /* ── Alocação dinâmica ──────────────────────────────────── */
    printf("\n=== Alocação Dinâmica ===\n");
    int n;
    printf("Quantos números deseja armazenar? ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro: memória insuficiente!\n");
        return 1;
    }

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int soma = 0;
    for (int i = 0; i < n; i++) soma += vetor[i];
    printf("Soma   : %d\n", soma);
    printf("Média  : %.2f\n", (double)soma / n);

    free(vetor);   /* Liberar memória alocada */
    printf("Memória liberada com sucesso.\n");

    return 0;
}

void trocar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dobrar(int *n) {
    *n *= 2;
}
