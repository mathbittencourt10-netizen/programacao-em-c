/*
 * 03 — Funções e Recursão
 * Demonstra: declaração, parâmetros, retorno, recursão
 * Compilar: gcc 03_funcoes.c -o 03_funcoes
 */
#include <stdio.h>

/* ── Protótipos ─────────────────────────────────────────────── */
int    somar(int a, int b);
double media(int valores[], int tam);
int    fatorial(int n);
int    fibonacci(int n);
int    eh_primo(int n);
void   listar_primos(int limite);

/* ── Main ───────────────────────────────────────────────────── */
int main() {
    /* Funções simples */
    printf("=== Funções Básicas ===\n");
    printf("somar(8, 5)   = %d\n", somar(8, 5));

    int notas[] = {8, 7, 9, 6, 10};
    printf("media(notas)  = %.2f\n\n", media(notas, 5));

    /* Fatorial — recursão */
    printf("=== Recursão — Fatorial ===\n");
    for (int i = 0; i <= 10; i++) {
        printf("%2d! = %d\n", i, fatorial(i));
    }

    /* Fibonacci — recursão */
    printf("\n=== Recursão — Fibonacci ===\n");
    printf("Sequência: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    /* Números primos */
    printf("\n=== Primos até 60 ===\n");
    listar_primos(60);

    return 0;
}

/* ── Implementações ─────────────────────────────────────────── */

int somar(int a, int b) {
    return a + b;
}

double media(int valores[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) soma += valores[i];
    return (double)soma / tam;
}

/* n! = n × (n-1)!   |   caso base: 0! = 1 */
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

/* F(n) = F(n-1) + F(n-2)   |   caso base: F(0)=0, F(1)=1 */
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int eh_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void listar_primos(int limite) {
    int count = 0;
    for (int i = 2; i <= limite; i++) {
        if (eh_primo(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal: %d primos\n", count);
}
