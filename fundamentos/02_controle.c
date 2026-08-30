/*
 * 02 — Estruturas de Controle
 * Demonstra: if/else, switch/case, for, while, do-while
 * Compilar: gcc 02_controle.c -o 02_controle
 */
#include <stdio.h>

int main() {
    /* ── If / Else If / Else ────────────────────────────────── */
    printf("=== Condicional — Situação do Aluno ===\n");
    float nota;
    printf("Digite uma nota (0 a 10): ");
    scanf("%f", &nota);

    if (nota >= 7.0f) {
        printf("Situação: APROVADO ✔\n\n");
    } else if (nota >= 5.0f) {
        printf("Situação: EM RECUPERAÇÃO ⚠\n\n");
    } else {
        printf("Situação: REPROVADO ✗\n\n");
    }

    /* ── Switch / Case ──────────────────────────────────────── */
    printf("=== Switch — Dia da Semana ===\n");
    int dia;
    printf("Digite um número de 1 a 7: ");
    scanf("%d", &dia);
    switch (dia) {
        case 1: printf("Segunda-feira\n\n"); break;
        case 2: printf("Terça-feira\n\n");   break;
        case 3: printf("Quarta-feira\n\n");  break;
        case 4: printf("Quinta-feira\n\n");  break;
        case 5: printf("Sexta-feira\n\n");   break;
        case 6: printf("Sábado\n\n");        break;
        case 7: printf("Domingo\n\n");       break;
        default: printf("Número inválido!\n\n");
    }

    /* ── For — Tabuada ──────────────────────────────────────── */
    printf("=== For — Tabuada ===\n");
    int n;
    printf("Digite o número para a tabuada: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %2d = %d\n", n, i, n * i);
    }

    /* ── While — Contagem regressiva ────────────────────────── */
    printf("\n=== While — Contagem Regressiva ===\n");
    int cont = 5;
    while (cont > 0) {
        printf("%d ", cont--);
    }
    printf("🚀 Lançamento!\n");

    /* ── Do-While — Soma acumulada ──────────────────────────── */
    printf("\n=== Do-While — Soma (0 para encerrar) ===\n");
    int valor, soma = 0;
    do {
        printf("Valor: ");
        scanf("%d", &valor);
        soma += valor;
    } while (valor != 0);
    printf("Soma total: %d\n", soma);

    return 0;
}
