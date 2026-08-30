/*
 * Projeto — Jogo da Forca
 * Adivinhe a palavra antes de acabar as tentativas!
 * Compilar: gcc jogo_forca.c -o jogo_forca
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define TOTAL_PALAVRAS 10

const char *palavras[TOTAL_PALAVRAS] = {
    "python", "computador", "programacao", "algoritmo",
    "funcao", "variavel", "compilador", "recursao",
    "ponteiro", "estrutura"
};

/* Protótipos */
void  exibir_forca(int erros);
void  exibir_palavra(const char *palavra, const char *mascara);
int   tentar_letra(const char *palavra, char *mascara, char letra);
int   letra_usada(char letra, const char *usadas, int total);

int main() {
    srand(time(NULL));
    char repetir;

    do {
        /* Selecionar palavra aleatória */
        const char *palavra = palavras[rand() % TOTAL_PALAVRAS];
        int  tam    = strlen(palavra);
        char mascara[tam + 1];
        char erradas[MAX_TENTATIVAS + 1];
        int  erros  = 0;
        int  n_erradas = 0;

        memset(mascara, '_', tam);
        mascara[tam] = '\0';
        memset(erradas, 0, sizeof(erradas));

        printf("\n╔══════════════════════╗\n");
        printf("║    JOGO DA FORCA     ║\n");
        printf("╚══════════════════════╝\n");

        /* Loop principal do jogo */
        while (erros < MAX_TENTATIVAS && strcmp(mascara, palavra) != 0) {
            exibir_forca(erros);
            exibir_palavra(palavra, mascara);

            if (n_erradas > 0) {
                printf("Letras erradas (%d/%d): ", erros, MAX_TENTATIVAS);
                for (int i = 0; i < n_erradas; i++) printf("%c ", erradas[i]);
                printf("\n");
            }

            char letra;
            printf("Digite uma letra: ");
            scanf(" %c", &letra);
            letra = tolower(letra);

            /* Verificar se a letra já foi usada */
            if (letra_usada(letra, erradas, n_erradas) ||
                letra_usada(letra, mascara, tam)) {
                printf("Letra '%c' já foi usada!\n", letra);
                continue;
            }

            if (tentar_letra(palavra, mascara, letra)) {
                printf("✔ Acertou! '%c' está na palavra.\n", letra);
            } else {
                erradas[n_erradas++] = letra;
                erros++;
                printf("✗ Errou! '%c' não está na palavra.\n", letra);
            }
        }

        /* Resultado final */
        exibir_forca(erros);
        exibir_palavra(palavra, mascara);

        if (strcmp(mascara, palavra) == 0) {
            printf("\n🎉 PARABÉNS! Você venceu!\n");
            printf("   A palavra era: %s\n", palavra);
        } else {
            printf("\n💀 GAME OVER!\n");
            printf("   A palavra era: %s\n", palavra);
        }

        printf("\nJogar novamente? (s/n): ");
        scanf(" %c", &repetir);

    } while (tolower(repetir) == 's');

    printf("\nObrigado por jogar! Até logo.\n");
    return 0;
}

/* Tenta a letra na palavra; atualiza mascara e retorna 1 se acertou */
int tentar_letra(const char *palavra, char *mascara, char letra) {
    int acertou = 0;
    for (int i = 0; palavra[i]; i++) {
        if (palavra[i] == letra) {
            mascara[i] = letra;
            acertou    = 1;
        }
    }
    return acertou;
}

int letra_usada(char letra, const char *lista, int total) {
    for (int i = 0; i < total; i++) {
        if (lista[i] == letra) return 1;
    }
    return 0;
}

void exibir_palavra(const char *palavra, const char *mascara) {
    printf("\nPalavra (%d letras): ", (int)strlen(palavra));
    for (int i = 0; mascara[i]; i++) {
        printf("%c ", mascara[i] == '_' ? '_' : palavra[i]);
    }
    printf("\n\n");
}

void exibir_forca(int erros) {
    const char *estados[] = {
        "\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n",
    };
    printf("%s", estados[erros]);
}
