#include <stdio.h>

int main() {

    printf("-----------Desafio Batalha Naval-----------\n\n");

    // Inicializa a matriz tabuleiro com zeros
    int tabuleiro [10][10] = {0};

    // Vetores para representar as posições dos números 3 (navios)
    int posicao_coluna_dos_navios[12] = {0, 0, 0, 4, 5, 6, 6, 5, 4, 0, 1, 2};
    int posicao_linha_dos_navios[12] = {5, 6, 7, 1, 1, 1, 6, 5, 4, 9, 8, 7 };

    // Alterar as posições especificadas para 3
    for (int i = 0; i < 12; i++) {
        tabuleiro[posicao_coluna_dos_navios[i]][posicao_linha_dos_navios[i]] = 3;
    }

    // Definição das habilidades
    int habilidade_cone [3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int habilidade_cruz [3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    int habilidade_octaedro [3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    // Ajusta as habilidades para o valor 5 onde há números ímpares
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (habilidade_cone[i][j] % 2 != 0)
            {
                habilidade_cone[i][j] = 5;
            } 
            
            if (habilidade_cruz[i][j] % 2 != 0)
            {
                habilidade_cruz[i][j] = 5;
            }

            if (habilidade_octaedro[i][j] % 2 != 0)
            {
                habilidade_octaedro[i][j] = 5;
            }
            
        
        }
        
    }

    // Vetores para representar as posições das habilidades
    int posicao_coluna_das_habilidades[45] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9};
    int posicao_linha_das_habilidades[45] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9};

     // Adiciona habilidade_cruz ao tabuleiro
    for (int i = 0; i < 15; i++) {
        int s = i / 5;
        int d = i % 5;
        tabuleiro[posicao_coluna_das_habilidades[i]][posicao_linha_das_habilidades[i]] = habilidade_cruz[s][d];
    }

    // Adiciona habilidade_octaedro ao tabuleiro
    for (int i = 15; i < 30; i++) {
        int u = (i - 15) / 5;
        int v = (i - 15) % 5;
        tabuleiro[posicao_coluna_das_habilidades[i]][posicao_linha_das_habilidades[i]] = habilidade_octaedro[u][v];
    }

    // Adiciona habilidade_cone ao tabuleiro
    for (int i = 30; i < 45; i++) {
        int w = (i - 30) / 5;
        int z = (i - 30) % 5;
        tabuleiro[posicao_coluna_das_habilidades[i]][posicao_linha_das_habilidades[i]] = habilidade_cone[w][z];
    }

    int y = 0;
    int condicao = 0;
    int ordem_vertical = 1;

    // Imprime o cabeçalho das colunas
    printf("   A B C D E F G H I J\n");

    // Imprime o tabuleiro com as colunas e linhas
    while (condicao < 10)
    {
        int x = 0;

        // Imprime a ordem vertical das linhas
        if (ordem_vertical == 10) 
        {
            printf("%d ", ordem_vertical);
        } else {
            printf(" %d ", ordem_vertical);
        }

        // Imprime os valores do tabuleiro
        for (int i = 0; i < 10; i++)
        {
        printf("%d ", tabuleiro[y][x]);
        x++;
        }

        printf("\n");
        y++;
        ordem_vertical++;
        condicao++;

    }
    
    printf("\n");

    return 0;
}
    