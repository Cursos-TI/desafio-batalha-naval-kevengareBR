#include <stdio.h>

#define TAMANHO_TABULEIRO 10          // Define o tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO_VERTICAL 4      // Define o tamanho do navio vertical (4 células)
#define TAMANHO_NAVIO_HORIZONTAL 3    // Define o tamanho do navio horizontal (3 células)

int main() {
    // Tabuleiro vazio
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com zeros (0 = vazio)

    // Posição inicial do navio vertical
    int x_vert = 2; // Coordenada X inicial do navio vertical
    int y_vert = 3; // Coordenada Y inicial do navio vertical

    // Posição inicial do navio horizontal
    int x_horiz = 6; // Coordenada X inicial do navio horizontal
    int y_horiz = 1; // Coordenada Y inicial do navio horizontal

    // Posicionando navio vertical
    for (int i = 0; i < TAMANHO_NAVIO_VERTICAL; i++) { // Itera sobre o tamanho do navio vertical
        tabuleiro[y_vert + i][x_vert] = 1;  // Marca as células do navio vertical no tabuleiro (valor = 1)
    }

    // Posicionando navio horizontal
    for (int j = 0; j < TAMANHO_NAVIO_HORIZONTAL; j++) { // Itera sobre o tamanho do navio horizontal
        tabuleiro[y_horiz][x_horiz + j] = 2;  // Marca as células do navio horizontal no tabuleiro (valor = 2)
    }

    // Exibindo coordenadas dos navios
    printf("Coordenadas do NAVIO VERTICAL (valor = 1):\n");
    for (int i = 0; i < TAMANHO_NAVIO_VERTICAL; i++) { // Itera sobre o tamanho do navio vertical
        printf("(%d, %d)\n", x_vert, y_vert + i); // Exibe as coordenadas de cada célula do navio vertical
    }

    printf("\nCoordenadas do NAVIO HORIZONTAL (valor = 2):\n");
    for (int j = 0; j < TAMANHO_NAVIO_HORIZONTAL; j++) { // Itera sobre o tamanho do navio horizontal
        printf("(%d, %d)\n", x_horiz + j, y_horiz); // Exibe as coordenadas de cada célula do navio horizontal
    }

    return 0; // Finaliza o programa
}
