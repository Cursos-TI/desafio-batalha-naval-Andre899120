#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    // Habilidades especiais representadas por matrizes, 3x5 para cone, cruz e octaedro
    int habilidadeCone[3][5];
    int habilidadeCruz[3][5];
    int habilidadeOctaedro[3][5];
    int offsetLinhaOct = 6, offsetColunaOct = 0; // Ajusta o posicionamento da habilidade no tabuleiro
    int offsetLinhaCruz = 4, offsetColunaCruz = 4; // Ajusta o posicionamento da habilidade no tabuleiro
    int offsetLinhaCone = 0, offsetColunaCone = 2; // Ajusta o posicionamento da habilidade no tabuleiro
    // Coordenadas do tabuleiro, utilizando letras para as colunas e números para as linhas
    char coordenadaX[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10]; // Tabuleiro com 10 linhas e 10 colunas, 0 representa a água e posteriormente 3 representará os navios
    
    printf("*** Tabuleiro Batalha Naval ***\n");
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c  ", coordenadaX[i]); // Coordenadas com letras de A a J para as colunas
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0; // Demarcados com 0 indicando que é água inicialmente
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[3][i + 2] = navio1[i]; // Posiciona o navio1 horizontalmente na posição (3, C) (3, D) (3, E)
        tabuleiro[i + 5][2] = navio2[i]; // Posiciona o navio2 verticalmente na posição (5, C) (6, C) (7, C)
        tabuleiro[i + 2][i + 6] = navio3[i]; // Posiciona o navio3 diagonalmente na posição (2, G) (3, H) (4, I)
        tabuleiro[i + 5][6 - i] = navio4[i]; // Posiciona o navio4 diagonalmente na posição (5, G) (6, F) (7, E)
    }

    // Habilidades especiais, representadas por matrizes, preenchendo as áreas dinamicamente
    // Habilidade em cone
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 || (i == 1 && j >= 1 && j <= 3) || (i == 0 && j == 2))
            {
                habilidadeCone[i][j] = 1;
            }
            else
            {
                habilidadeCone[i][j] = 0;
            }
        }
    }

    // Habilidade em cruz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 1 || j == 2)
            {
                habilidadeCruz[i][j] = 1;
            }
            else
            {
                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // Habilidade em octaedro
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2 && j == 2))
            {
                habilidadeOctaedro[i][j] = 1;
            }
            else
            {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3 && i + offsetLinhaOct < LINHAS; i++)
    {
        for(int j = 0; j < 5 && j + offsetColunaOct < COLUNAS; j++)
        {
            tabuleiro[i + offsetLinhaOct][j + offsetColunaOct] = habilidadeOctaedro[i][j]; // Posiciona a habilidade em octaedro apenas nas posições válidas
        }
    }

    for (int i = 0; i < 3 && i + offsetColunaCruz < LINHAS; i++)
    {
        for (int j = 0; j < 5 && j + offsetColunaCruz < COLUNAS; j++)
        {
            tabuleiro[i + offsetLinhaCruz][j + offsetColunaCruz] = habilidadeCruz[i][j]; // Posiciona a habilidade em cruz apenas nas posições válidas
        }
    }

    for (int i = 0; i < 3 && i + offsetLinhaCone < LINHAS; i++)
    {
        for (int j = 0; j < 5 && j + offsetColunaCone < COLUNAS; j++)
        {
            tabuleiro[i + offsetLinhaCone][j + offsetColunaCone] = habilidadeCone[i][j]; // Posiciona a habilidade em cone apenas nas posições válidas
        }
    }

    for (int i = 0; i < LINHAS; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d  ", tabuleiro[i][j]); // Exibindo o tabuleiro completo com 0 para água e 3 para navios
        }
        printf("\n");
    }

    return 0;
}
