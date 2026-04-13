#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    char coordenadaX[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10]; // Tabuleiro com 10 linhas e 10 colunas, 0 representa a água e posteriormente 3 representará os navios
    
    printf("*** Tabuleiro Batalha Naval ***\n");
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c  ", coordenadaX[i]); // Coordenadas com letras de A a J para as colunas
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Demarcados com 0 indicando que é água inicialmente
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[3][i + 2] = navio1[i]; // Posiciona o navio1 horizontalmente na posição (3, C) (3, D) (3, E)
        tabuleiro[i + 5][2] = navio2[i]; // Posiciona o navio2 verticalmente na posição (5, C) (6, C) (7, C)
        tabuleiro[i + 2][i + 6] = navio3[i]; // Posiciona o navio3 diagonalmente na posição (2, G) (3, H) (4, I)
        tabuleiro[i + 5][i + 6] = navio4[i]; // Posiciona o navio4 diagonalmente na posição (5, G) (5, H) (6, I)
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%d  ", tabuleiro[i][j]); // Exibindo o tabuleiro completo com 0 para água e 3 para navios
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
