// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
*/
#include "jogo.h"
#include "utils.h"

//void initTab(char galo[N][N]) {
void initTab(char **galo) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            galo[i][j] = '_';
        }
    }
}

//void printTab(char galo[N)[N] {
void printTab(char **aux1, char **aux2, char **aux3, char **aux4, char **aux5, char **aux6, char **aux7, char **aux8,
              char **aux9) {
    printf("\n");
    printf("           |         |\n");
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux1[0][0], aux1[0][1], aux1[0][2], aux2[0][0], aux2[0][1],
           aux2[0][2], aux3[0][0], aux3[0][1], aux3[0][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux1[1][0], aux1[1][1], aux1[1][2], aux2[1][0], aux2[1][1],
           aux2[1][2], aux3[1][0], aux3[1][1], aux3[1][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux1[2][0], aux1[2][1], aux1[2][2], aux2[2][0], aux2[2][1],
           aux2[2][2], aux3[2][0], aux3[2][1], aux3[2][2]);
    printf(" __________|_________|_________ \n");
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux4[0][0], aux4[0][1], aux4[0][2], aux5[0][0], aux5[0][1],
           aux5[0][2], aux6[0][0], aux6[0][1], aux6[0][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux4[1][0], aux4[1][1], aux4[1][2], aux5[1][0], aux5[1][1],
           aux5[1][2], aux6[1][0], aux6[1][1], aux6[1][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux4[2][0], aux4[2][1], aux4[2][2], aux5[2][0], aux5[2][1],
           aux5[2][2], aux6[2][0], aux6[2][1], aux6[2][2]);
    printf(" __________|_________|_________ \n");
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux7[0][0], aux7[0][1], aux7[0][2], aux8[0][0], aux8[0][1],
           aux8[0][2], aux9[0][0], aux9[0][1], aux9[0][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux7[1][0], aux7[1][1], aux7[1][2], aux8[1][0], aux8[1][1],
           aux8[1][2], aux9[1][0], aux9[1][1], aux9[1][2]);
    printf("    %c %c %c  |  %c %c %c  | %c %c %c \n", aux7[2][0], aux7[2][1], aux7[2][2], aux8[2][0], aux8[2][1],
           aux8[2][2], aux9[2][0], aux9[2][1], aux9[2][2]);
    printf("           |         |\n");
    printf("\n");
}

void jogada(char **galo, int jogador, int *pposicao, int *tipoJogo) {
    void initRandom();
    if (jogador == 1) printf("\n--> Jogador 'X' <--\n");
    else printf("\n--> Jogador 'O' <--\n");

    if (*tipoJogo == 2) {
        printf("-->Posicao a jogar:");
        do {
            printf("\n-->");
            while (scanf("%d", pposicao) != 1) {
                printf("-->");
                while (getchar() != '\n');
            }
            if (galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] != '_' || *pposicao < 1 || *pposicao > 9) {
                printf("\n-->Posicao invalida--<");
            }
        } while (galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] != '_' || *pposicao < 1 || *pposicao > 9);

    } else if (jogador == 1) {
        printf("-->Posicao a jogar:");
        do {
            printf("\n-->");
            while (scanf("%d", pposicao) != 1) {
                printf("-->");
                while (getchar() != '\n');
            }
            if (galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] != '_' || *pposicao < 1 || *pposicao > 9) {
                printf("\n-->Posicao invalida--<");
            }
        } while (galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] != '_' || *pposicao < 1 || *pposicao > 9);
    } else if (jogador == 2) {
        do {
            *pposicao = intUniformRnd(1, 9);
        } while (galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] != '_');

    }

    if (jogador == 1)
        galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] = 'X';
    else
        galo[((*pposicao) - 1) / N][((*pposicao) - 1) % N] = 'O';

    //(*pposicao)++;
}

//int confirma(char galo[N][N]) {
int confere_galo(char **galo, char *c) {
    int empate = 0;
    for (int i = 0; i < N; i++) {
        int contl = 0, contc = 0;
        for (int j = 1; j < N; j++) {
            if (galo[i][j] == galo[i][j - 1] && galo[i][j] != '_') { //linhas
                contl++;
                *c = galo[i][j];
            }
            if (galo[j][i] == galo[j - 1][i] && galo[j][i] != '_') {//colunas
                contc++;
                *c = galo[j][i];
            }
        }
        if (galo[1][1] == galo[0][0] && galo[2][2] == galo[1][1] && galo[1][1] != '_') { //diagonal esquerda
            *c = galo[1][1];
            return 1;
        }
        if (galo[1][1] == galo[0][2] && galo[2][0] == galo[1][1] && galo[1][1] != '_') { //diagonal direita
            *c = galo[1][1];
            return 1;
        }
        if (contl == 2 || contc == 2) {
            return 1;
        }
    }
    //se todos os lugares estiverem com '_' o empate é != 0
    for (int l = 0; l < N; l++) {
        for (int x = 0; x < N; x++) {
            if (galo[l][x] == '_') {
                //o jogo nao terminou
                empate++;
            }
        }
    }
    if (empate == 0) {
        //retorna 2, logo o jogo já acabou e empatou
        *c = 'E';
        return 2;
    } else {
        //retorna 0, logo não acabou o jogo
        return 0;
    }
}


int altera_galo(int *fim, char **galo, char *c) {
    if (*fim == 1) {
        initTab(galo);
        if (*c == 'X') {
            galo[0][0] = 'X';
            galo[0][2] = 'X';
            galo[1][1] = 'X';
            galo[2][0] = 'X';
            galo[2][2] = 'X';
        } else if (*c == 'O') {
            galo[0][1] = 'O';
            galo[1][0] = 'O';
            galo[1][2] = 'O';
            galo[2][1] = 'O';
        }
        return 1;
    } else if (*fim == 2) {
        initTab(galo);
        galo[0][0] = 'E';
        galo[0][1] = 'E';
        galo[0][2] = 'E';
        galo[1][0] = 'E';
        galo[2][0] = 'E';
        galo[2][1] = 'E';
        galo[2][2] = 'E';
        return 1;
    }
    return 0;
}

void converte(char **mat1, char **mat2) {
    int l = 1;
    for (int f = 0; f < N; f++) {
        for (int g = 0; g < N; g++) {
            mat2[f][g] = mat1[0][l];
            if (mat1[0][l] == '0')
                mat2[f][g] = '_';
            l++;
        }
    }
}

int final(int tipo, char vencedor) {
    if (tipo == 1) {
        if (vencedor == 'E') {
            //está uma linha de empatados mas nao termina o jogo, já que o Empatado não ganha se estiver em linha
        } else {
            //um dos jogadores vence e termina o jogo
            printf("\n\n\n\n-->Vencedor do jogo: %c <--\n\n\n\n", vencedor);
            return 1;
        }
    } else if (tipo == 2) {
        //se nao houver vencedor do jogo
        printf("\n\n\n\n-->O jogo terminou empatado <--\n\n\n\n");
        return 1;
    }
    return 0;
}

void informacoes() {
    printf("-->Modo de funcionamento:\n");
    printf("-->Tanto o tabuleiro geral como cada mini-tabuleiro teem as suas posicoes\n");
    printf("-->  a variar entre [1,9], como pode ver na representacao seguinte:\n");

    printf("\n");
    printf("-->Tabuleiro:\n");
    printf("           |         |\n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf("    _ 1 _  |  _ 2 _  | _ 3 _ \n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf(" __________|_________|_________ \n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf("    _ 4 _  |  _ 5 _  | _ 6 _ \n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf(" __________|_________|_________ \n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf("    _ 7 _  |  _ 8 _  | _ 9 _ \n");
    printf("    _ _ _  |  _ _ _  | _ _ _ \n");
    printf("           |         |\n");
    printf("\n");
    printf("-->Posicoes em cada mini-tabuleiro:\n");
    printf("           |  \n");
    printf("    1 2 3  |  \n");
    printf("    4 5 6  |  \n");
    printf("    7 8 9  |  \n");
    printf(" __________|___ \n");
    printf("           |  \n");

}
