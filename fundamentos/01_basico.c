/*
 * 01 — Conceitos Básicos em C
 * Demonstra: tipos de dados, variáveis, entrada/saída, operadores
 * Compilar: gcc 01_basico.c -o 01_basico
 */
#include <stdio.h>

int main() {
    /* ── Tipos de dados ─────────────────────────────────────── */
    int    inteiro   = 42;
    float  decimal   = 3.14f;
    double precisao  = 3.14159265;
    char   caractere = 'A';
    char   texto[50] = "Olá, Mundo!";

    printf("=== Tipos de Dados ===\n");
    printf("int    : %d  (%zu bytes)\n", inteiro,   sizeof(int));
    printf("float  : %.2f  (%zu bytes)\n", decimal, sizeof(float));
    printf("double : %.8f  (%zu bytes)\n", precisao, sizeof(double));
    printf("char   : %c  (%zu byte)\n",  caractere, sizeof(char));
    printf("string : %s\n\n", texto);

    /* ── Operadores aritméticos ──────────────────────────────── */
    int a = 10, b = 3;
    printf("=== Operadores Aritméticos ===\n");
    printf("%d + %d = %d\n",   a, b, a + b);
    printf("%d - %d = %d\n",   a, b, a - b);
    printf("%d * %d = %d\n",   a, b, a * b);
    printf("%d / %d = %d  (divisão inteira)\n", a, b, a / b);
    printf("%d %% %d = %d  (resto)\n",           a, b, a % b);
    printf("%.1f / %.1f = %.4f  (divisão real)\n\n",
           (float)a, (float)b, (float)a / b);

    /* ── Operadores relacionais e lógicos ───────────────────── */
    printf("=== Operadores Relacionais ===\n");
    printf("%d > %d  : %d\n",  a, b, a > b);
    printf("%d == %d : %d\n",  a, b, a == b);
    printf("%d != %d : %d\n",  a, b, a != b);
    printf("(%d>0) && (%d>0) : %d\n", a, b, (a > 0) && (b > 0));
    printf("(%d<0) || (%d>0) : %d\n\n", a, b, (a < 0) || (b > 0));

    /* ── Entrada do usuário ──────────────────────────────────── */
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("Dobro    : %d\n", num * 2);
    printf("Quadrado : %d\n", num * num);

    return 0;
}
