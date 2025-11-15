#include <stdio.h>

int main() {
    // Criar o tabuleiro 10x10 e colocar tudo como água (0)
    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Criar os navios (tamanho 3)
    int navio1[3] = {3, 3, 3}; // horizontal
    int navio2[3] = {3, 3, 3}; // vertical

    // Posição inicial do navio1 (horizontal)
    int linha1 = 2;
    int coluna1 = 4;

    // Posição inicial do navio2 (vertical)
    int linha2 = 5;
    int coluna2 = 1;

    // Verificar se os navios cabem
    if (coluna1 + 3 > 10) {
        printf("navio1 nao cabe na horizontal\n");
        return 1;
    }

    if (linha2 + 3 > 10) {
        printf("navio2 nao cabe na vertical\n");
        return 1;
    }

    // Verificar se já tem navio nas posições
    int temErro = 0;

    for (i = 0; i < 3; i++) {
        if (tabuleiro[linha1][coluna1 + i] != 0) {
            temErro = 1;
        }
        if (tabuleiro[linha2 + i][coluna2] != 0) {
            temErro = 1;
        }
    }

    if (temErro == 1) {
        printf("Erro: navios batendo um no outro\n");
        return 1;
    }

    // Colocar navio1 na horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;
    }

    // Colocar navio2 na vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }

    // Mostrar o tabuleiro
    printf("Tabuleiro:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
