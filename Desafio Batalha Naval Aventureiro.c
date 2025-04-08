#include <stdio.h>

#define TAMANHO_TABULEIRO 10 // Define o tamanho do tabuleiro (10x10)
#define VALOR_NAVIO 3        // Define o valor que representa um navio no tabuleiro

int main() {
    // Inicializa o tabuleiro 10x10 com zeros (0 = vazio)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // ------ POSICIONAMENTO DOS 4 NAVIOS ------

    // 1. Navio vertical (tamanho 4)
    // Posiciona um navio vertical começando na posição (2, 1)
    int x_vert = 2, y_vert = 1; // Coordenadas iniciais do navio vertical
    for (int i = 0; i < 4; i++) { // Itera sobre o tamanho do navio vertical
        tabuleiro[y_vert + i][x_vert] = VALOR_NAVIO; // Marca as células do navio no tabuleiro
    }

    // 2. Navio horizontal (tamanho 3)
    // Posiciona um navio horizontal começando na posição (5, 0)
    int x_horiz = 5, y_horiz = 0; // Coordenadas iniciais do navio horizontal
    for (int i = 0; i < 3; i++) { // Itera sobre o tamanho do navio horizontal
        tabuleiro[y_horiz][x_horiz + i] = VALOR_NAVIO; // Marca as células do navio no tabuleiro
    }

    // 3. Navio diagonal descendente (↘) - tamanho 3
    // Posiciona um navio diagonal descendente começando na posição (0, 0)
    int x_diag1 = 0, y_diag1 = 0; // Coordenadas iniciais do navio diagonal descendente
    for (int i = 0; i < 3; i++) { // Itera sobre o tamanho do navio diagonal
        tabuleiro[y_diag1 + i][x_diag1 + i] = VALOR_NAVIO; // Marca as células do navio no tabuleiro
    }

    // 4. Navio diagonal ascendente (↗) - tamanho 3
    // Posiciona um navio diagonal ascendente começando na posição (7, 9)
    int x_diag2 = 7, y_diag2 = 9; // Coordenadas iniciais do navio diagonal ascendente
    for (int i = 0; i < 3; i++) { // Itera sobre o tamanho do navio diagonal
        tabuleiro[y_diag2 - i][x_diag2 + i] = VALOR_NAVIO; // Marca as células do navio no tabuleiro
    }

    // ------ EXIBIÇÃO DO TABULEIRO COMPLETO ------
    printf("=== Tabuleiro Batalha Naval (10x10) ===\n\n");

    // Exibe o tabuleiro completo no console
    for (int y = 0; y < TAMANHO_TABULEIRO; y++) { // Itera sobre as linhas do tabuleiro
        for (int x = 0; x < TAMANHO_TABULEIRO; x++) { // Itera sobre as colunas do tabuleiro
            printf("%d ", tabuleiro[y][x]); // Exibe o valor da célula (0 = vazio, 3 = navio)
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    return 0; // Finaliza o programa
}
