/*
 * Projeto — Calculadora Interativa
 * Operações: +  -  *  /  |  Digite 'q' para sair
 * Compilar : gcc calculadora.c -o calculadora
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, resultado;
    char   operador;

    printf("╔══════════════════════════╗\n");
    printf("║    Calculadora em C      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║  Formato: num op num     ║\n");
    printf("║  Exemplo: 10 + 5         ║\n");
    printf("║  'q' para sair           ║\n");
    printf("╚══════════════════════════╝\n\n");

    while (1) {
        printf("> ");

        /* Tentar ler a expressão */
        if (scanf(" %lf %c %lf", &a, &operador, &b) != 3) {
            char c;
            scanf(" %c", &c);
            if (c == 'q' || c == 'Q') {
                printf("Encerrando calculadora. Até logo!\n");
                break;
            }
            printf("Entrada inválida. Tente: número operador número\n\n");
            while (getchar() != '\n');  /* Limpar buffer */
            continue;
        }

        switch (operador) {
            case '+':
                resultado = a + b;
                printf("  %.6g + %.6g = %.6g\n\n", a, b, resultado);
                break;

            case '-':
                resultado = a - b;
                printf("  %.6g - %.6g = %.6g\n\n", a, b, resultado);
                break;

            case '*':
            case 'x':
            case 'X':
                resultado = a * b;
                printf("  %.6g × %.6g = %.6g\n\n", a, b, resultado);
                break;

            case '/':
                if (b == 0.0) {
                    printf("  Erro: divisão por zero!\n\n");
                } else {
                    resultado = a / b;
                    printf("  %.6g ÷ %.6g = %.6g\n\n", a, b, resultado);
                }
                break;

            default:
                printf("  Operador '%c' inválido. Use: + - * /\n\n", operador);
        }
    }

    return 0;
}
