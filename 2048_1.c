#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define TAM 6 /* tamanho com as bordas de -1*/
#define LINHA 4
#define COLUNA 4

/*criando o tabuleiro com as bordas*/
void criando_tabuleiro(int matriz[TAM][TAM]){
    int i,j;
    for (i=0; i < TAM; i++){
        for(j=0; j< TAM; j++){
            /*colocando as bordas de -1*/
            if (i == 0 || j == 0 || i == 5 || j == 5){ 
                matriz[i][j] = -1;
            }
            /*colocando 0 no tabuleiro*/
            else {
                matriz[i][j] = 0;  
            }    
        }

    }
}

/*mostrando o tabuleiro e a pontuação*/
void imprimir_tabuleiro(int matriz[TAM][TAM], int pontos){
    int i,j;
    clear();
    refresh();
    printw("\n");
    printw("Pontos: %d\n", pontos);
    printw("\n");
    for (i=1; i<= LINHA; i++){
        for(j=1; j<= COLUNA; j++){
            printw("   %d   ", matriz[i][j]);
        }
            printw("\n");
    }
}

/* adicionando o dois e o quatro*/
void adiciona_numero(int matriz[TAM][TAM]){
    int x,y;
    int flag = 0;
    int num;
    while (flag == 0){
        x=(rand()% 4)+1; /*linha*/
        y=(rand()% 4)+1; /*coluna*/
        if (matriz[x][y] == 0){
            num =((rand() % 2)+1)*2; /*gerando dois ou quatro*/
            matriz[x][y] = num;
            flag = 1;
        }
    }
}


int movimento_para_direita(int matriz[TAM][TAM]){
    int i,j,aux;
    int soma = 0;
    /*essa parte vai movimentar as peças*/
   for(i=1; i <=4 ; i++){
        for(j=4 ; j <=1 ; j--){
            if (matriz[i][j] == 0 ){
                for (aux=j-1; aux <= 4; aux--){
                    if (matriz[i][j] != 0 && matriz[i][j] != -1 ){
                        matriz[i][j] = matriz[i][j];
                        matriz [i][j] = 0;
                        break;
                    }    
                }
            }
        }
    }
    /*essa parte vai somar as peças*/
    for(i=1; i <= 4; i++){
        for(j=4 ; j >= 1 ; j--){
            if (matriz[i][j] != 0 ){
                if (matriz[i][j] == matriz[i][j-1]){
                        matriz [i][j] = matriz[i][j] + matriz[i][j-1];
                        matriz[i][j-1] = 0;
                        soma= soma + matriz[i][j];
                        aux = j+1;
                        while (matriz[i][aux] == 0){
                            matriz[i][aux] = matriz[i][aux-1];
                            matriz [i][aux-1] = 0;
                            aux++;
                        }
                }
                /*essa parte so confere se o numero esta na posição certa mesmo não somando*/
                else{
                    aux = j+1;
                    while (matriz[i][aux] == 0){
                        matriz[i][aux] = matriz[i][aux-1];
                        matriz [i][aux-1] = 0;
                        aux++;
                    }
                } 
            }
        }
    }
    return soma;
}

int movimento_para_esquerda(int matriz[TAM][TAM]){
    int i,j,aux;
    int soma = 0;

    /*essa parte vai movimentar as peças*/
    for(i=1; i <=4 ; i++){
        for(j=1 ; j <=4 ; j++){
            if (matriz[i][j] == 0 ){
                for (aux=j+1; aux <= 4; aux++){
                    if (matriz[i][j] != 0 && matriz[i][j] != -1){
                        matriz[i][j] = matriz[i][j];
                        matriz [i][j] = 0;
                        break;
                    }    
                }
            }
        }
    }
    /*essa parte vai somar as peças*/
    for(i=1; i <= 4; i++){
        for(j=1 ; j <= 4 ; j++){
            if (matriz[i][j] != 0 ){
                if (matriz[i][j] == matriz[i][j+1] ){
                        matriz [i][j] = matriz[i][j] + matriz[i][j+1];
                        matriz[i][j+1] = 0;
                        soma= soma + matriz[i][j];
                        aux = j-1;
                        /*essa parte so confere se o numero esta na posição certa */
                        while (matriz[i][aux] == 0){
                            matriz[i][aux] = matriz[i][aux+1];
                            matriz [i][aux+1] = 0;
                            aux--;
                        }
                }
                /*essa parte so confere se o numero esta na posição certa */
                else{
                    aux = j-1;
                    while (matriz[i][aux] == 0){
                        matriz[i][aux] = matriz[i][aux+1];
                        matriz [i][aux+1] = 0;
                        aux--;
                    }
                } 
            }
        }
    }
    return soma;
}

int movimento_para_cima(int matriz[TAM][TAM]){
    int i,j,aux;
    int soma = 0;

    /*essa parte vai movimentar as peças*/
    for(i=1; i <=4 ; i++){
        for(j=1 ; j <=4 ; j++){
            if (matriz[j][i] == 0 ){
                for (aux=j+1; aux <= 4; aux++){
                    if (matriz[aux][i] != 0 && matriz[i][j] != -1){
                        matriz[j][i] = matriz[aux][i];
                        matriz [aux][i] = 0;
                        break;
                    }    
                }
            }
        }
    }
    /*essa parte soma as peças*/
    for(i=1; i <= 4; i++){
        for(j=1; j <= 4 ; j++){
            if (matriz[j][i] != 0 ){
                if (matriz[j][i] == matriz[j+1][i]){
                        matriz [j][i] = matriz[j][i] + matriz[j+1][i];
                        matriz[j+1][i] = 0;
                        soma= soma + matriz[i][j];
                        aux = j-1;
                        while (matriz[aux][i] == 0){
                            matriz[aux][i] = matriz[aux+1][i];
                            matriz [aux+1][i] = 0;
                            aux--;
                        }
                }
                else{
                    aux = j-1;
                    while (matriz[aux][i] == 0){
                        matriz[aux][i] = matriz[aux+1][i];
                        matriz [aux+1][i] = 0;
                        aux--;
                    }
                } 
            }
        }
    }
    return soma;
}


int movimento_para_baixo(int matriz[TAM][TAM]){
    int i,j,aux;
    int soma = 0;

    /*essa parte vai movimentar as peças*/
   for(i=4; i >=1 ; i--){
        for(j=4 ; j >=1 ; j--){
            if (matriz[j][i] == 0 ){
                for (aux=j-1; aux <= 4; aux--){
                    if (matriz[aux][i] != 0 && matriz[i][j] != -1){
                        matriz[j][i] = matriz[aux][i];
                        matriz [aux][i] = 0;
                        break;
                    }    
                }
            }
        }
    }
    for(i=1; i <= 4; i++){
        for(j=4; j >= 1 ; j--){
            if (matriz[j][i] != 0 ){
                if (matriz[j][i] == matriz[j-1][i]){
                        matriz [j][i] = matriz[j][i] + matriz[j-1][i];
                        matriz[j-1][i] = 0;
                        soma= soma + matriz[i][j];
                        aux = j+1;
                        while (matriz[aux][i] == 0){
                            matriz[aux][i] = matriz[aux-1][i];
                            matriz [aux-1][i] = 0;
                            aux++;
                        }
                }
                else{
                    aux = j+1;
                    while (matriz[aux][i] == 0){
                        matriz[aux][i] = matriz[aux-1][i];
                        matriz [aux-1][i] = 0;
                        aux++;
                        }
                } 
            }
        }
    }
    return soma;
}

/*testar se ainda tem zero*/
int existe_zero(int matriz[TAM][TAM] ){
    int i,j;
    int cont = 0;
    for (i=1; i <= LINHA; i++)
        for(j=i; j <= COLUNA; j++){
            if (matriz[i][j] == 0){
                    cont++;
            }
        }
    if (cont != 0)
        return 1;
    return 0;
}

/*testar se ainda da para somar*/
int possivel_somar(int matriz[TAM][TAM]){
    int i,j;
    for (i=0; i<=LINHA; i++)
        for (j=1; i<=COLUNA; j++){
            if (matriz[i][j] == matriz[i][j+1] || matriz[i][j] == matriz[i+1][j])
                return 1;
        }
    return 0;
}

int main(){

    int tabuleiro[TAM][TAM];
    criando_tabuleiro(tabuleiro); 
    adiciona_numero(tabuleiro);
    adiciona_numero(tabuleiro);
    int pontos = 0;
    int movimento;
    char tecla;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    /*começando o jogo*/
    printw("Para jogar use as setas do teclado\n");
    printw("Se não quiser mais jogar digite q para poder sair do jogo\n");
    printw("Digite c para começar\n");
    tecla = getch(); /*esperando a tecla c */

    while (existe_zero(tabuleiro) || possivel_somar(tabuleiro) || tecla != 'q')
    {
        imprimir_tabuleiro(tabuleiro,pontos);
        movimento = getch();
        if (movimento == KEY_UP) /*movimento para cima*/
            pontos= pontos + movimento_para_cima(tabuleiro);
        else if (movimento == KEY_DOWN) /*movimento para baixo*/
            pontos= pontos + movimento_para_baixo(tabuleiro);
        else if (movimento == KEY_RIGHT) /*movimento para direita*/
            pontos= pontos + movimento_para_direita(tabuleiro);
        else if (movimento == KEY_LEFT) /*movimento para esquerda*/
            pontos= pontos + movimento_para_esquerda(tabuleiro);
        
        adiciona_numero(tabuleiro);
    }
    imprimir(tabuleiro,pontos);
    /*terminando o jogo*/
    printw("\n");
    printw("voce perdeu\n");
    printw("digite q sair\n");
    tecla = getch();
    if (tecla == 'q')
        endwin();
    return 0;
}