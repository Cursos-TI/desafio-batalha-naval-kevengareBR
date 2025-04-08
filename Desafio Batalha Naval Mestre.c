#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 10 // Define o tamanho do tabuleiro (10x10)

// Função para exibir o tabuleiro
void exibirTabuleiro(int matriz[TAMANHO][TAMANHO], const char *titulo) {
    printf("\n=== %s ===\n\n", titulo); // Exibe o título do tabuleiro
    for (int y = 0; y < TAMANHO; y++) { // Percorre as linhas do tabuleiro
        for (int x = 0; x < TAMANHO; x++) { // Percorre as colunas do tabuleiro
            printf("%d ", matriz[y][x]); // Exibe o valor da célula (0 ou 1)
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }
}

// Habilidade: Cruz
// Preenche uma cruz no tabuleiro com base no centro (cx, cy) e no alcance
void habilidadeCruz(int matriz[TAMANHO][TAMANHO], int cx, int cy, int alcance) {
    for (int i = 0; i < TAMANHO; i++) { // Percorre todas as linhas e colunas
        if (abs(i - cy) <= alcance) matriz[i][cx] = 1; // Preenche a parte vertical da cruz
        if (abs(i - cx) <= alcance) matriz[cy][i] = 1; // Preenche a parte horizontal da cruz
    }
}

// Habilidade: Cone 
// Cria um cone com a ponta no centro (cx, cy) e uma base proporcional à altura
void habilidadeCone(int matriz[TAMANHO][TAMANHO], int cx, int cy, int altura) {
    for (int i = 0; i < altura; i++) { // Para cada linha do cone
        int largura = 2 * i + 1; // Calcula a largura da linha atual do cone
        int inicio = cx - i;    // Determina o início da linha
        int fim = cx + i;       // Determina o fim da linha

        // Ajusta os limites para não ultrapassar os limites do tabuleiro
        if (inicio < 0) inicio = 0;
        if (fim >= TAMANHO) fim = TAMANHO - 1;

        for (int x = inicio; x <= fim; x++) { // Preenche a linha do cone
            int y = cy - i; // Decrementa y para que o cone cresça para cima
            if (y >= 0 && y < TAMANHO) { // Verifica se y está dentro dos limites
                matriz[y][x] = 1; // Marca a célula como parte do cone
            }
        }
    }
}

// Habilidade: Octaedro
// Preenche uma área em forma de octaedro com base no centro (cx, cy) e no raio
void habilidadeOctaedro(int matriz[TAMANHO][TAMANHO], int cx, int cy, int raio) {
    for (int y = 0; y < TAMANHO; y++) { // Percorre todas as linhas do tabuleiro
        for (int x = 0; x < TAMANHO; x++) { // Percorre todas as colunas do tabuleiro
            // Verifica se a célula está dentro do raio usando a distância de Manhattan
            if (abs(x - cx) + abs(y - cy) <= raio) {
                matriz[y][x] = 1; // Marca a célula como parte do octaedro
            }
        }
    }
}

int main() {
    // Matrizes para cada habilidade
    int cruz[TAMANHO][TAMANHO] = {0};     // Tabuleiro para a habilidade Cruz
    int cone[TAMANHO][TAMANHO] = {0};     // Tabuleiro para a habilidade Cone
    int octaedro[TAMANHO][TAMANHO] = {0}; // Tabuleiro para a habilidade Octaedro

    // Aplicando as habilidades
    habilidadeCruz(cruz, TAMANHO / 2, TAMANHO / 2, 2); // Cruz centralizada no tabuleiro com alcance 2
    habilidadeCone(cone, 4, 6, 3);                     // Cone com altura 3, começando na posição (4, 6)
    habilidadeOctaedro(octaedro, 5, 5, 2);             // Octaedro com raio 2, centralizado na posição (5, 5)

    // Exibir as matrizes
    exibirTabuleiro(cruz, "Habilidade CRUZ");          // Exibe o tabuleiro da Cruz
    exibirTabuleiro(cone, "Habilidade CONE");          // Exibe o tabuleiro do Cone
    exibirTabuleiro(octaedro, "Habilidade OCTAEDRO");  // Exibe o tabuleiro do Octaedro

    return 0; // Finaliza o programa
}
