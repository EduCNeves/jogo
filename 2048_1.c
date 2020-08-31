#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define TAM 6
#define LINHA 4
#define COLUNA 4

void incializando_tabuleiro(int matriz[TAM][TAM]){
    int i,j;
    for (i=0; i < TAM; i++){
        for(j=0; j< TAM; j++){
            if (i == 0 || j == 0 || i == 5 || j == 5){
                matriz[i][j] = -1;
            }
            else {
                matriz[i][j] = 0;  
            }    
        }

    }
}

void imprimir(int matriz[TAM][TAM]){
    int i,j;
    for (i=1; i< LINHA; i++){
        for(j=1; j< COLUNA; j++){
            printf("%d ", matriz[i][j]);
        }
            printf("\n");
    }
}

void adiciona_numero(int matriz[TAM][TAM]){
    int x,y;
    int flag = 0;
    int num;
    while (flag == 0){
        x=(rand()% 4)+1; //regando o numero para as coordenadas linha
        y=(rand()% 4)+1; //regando o numero para as coordenadas coluna
        if (matriz[x][y] == 0){
            num = (rand()% 9) ? 2 : 4; // verr como funciona 
            matriz[x][y] = num;
            flag = 1;
        }
    }
}

int movimento_para_direita(int matriz[TAM][TAM]){
    int i,j,aux;
    int soma = 0;
    for(i=1; i <= 4; i++){
        for(j=4 ; j >= 1 ; j--){
            if (matriz[i][j] != 0 ){
                if ( (matriz[i][j] == matriz[i][j-1]) && (matriz[i][j] =! 2048) ){
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
    for(i=1; i <= 4; i++){
        for(j=1 ; j <= 4 ; j++){
            if (matriz[i][j] != 0 ){
                if ((matriz[i][j] == matriz[i][j+1]) && (matriz[i][j]=! 2048) ){
                        matriz [i][j] = matriz[i][j] + matriz[i][j+1];
                        matriz[i][j+1] = 0;
                        soma= soma + matriz[i][j];
                        aux = j-1;
                        while (matriz[i][aux] == 0){
                            matriz[i][aux] = matriz[i][aux+1];
                            matriz [i][aux+1] = 0;
                            aux--;
                        }
                }
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
    for(i=1; i <= 4; i++){
        for(j=1; j <= 4 ; j++){
            if (matriz[j][i] != 0 ){
                if ((matriz[j][i] == matriz[j+1][i]) && (matriz[i][j]=! 2048)){
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
    for(i=1; i <= 4; i++){
        for(j=4; j >= 1 ; j--){
            if (matriz[j][i] != 0 ){
                if ((matriz[j][i] == matriz[j-1][i]) && (matriz[i][j] =! 2048) ){
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
    incializando_tabuleiro(tabuleiro);
    adiciona_numero(tabuleiro);
    adiciona_numero(tabuleiro);
    int pontos = 0;
    int movimento;

    initscr(); //inicializa o ncurses
    keypad(stdscr, TRUE);
    noecho();
    imprimir(tabuleiro);   

    while (existe_zero(tabuleiro) || possivel_somar(tabuleiro))
    {
        movimento = getch();
        if (movimento == KEY_UP) //movimento para cima
            pontos= pontos + movimento_para_cima(tabuleiro);
        else if (movimento == KEY_DOWN) //movimento para baixo
            pontos= pontos + movimento_para_baixo(tabuleiro);
        else if (movimento == KEY_RIGHT) // //movimento para direita
            pontos= pontos + movimento_para_direita(tabuleiro);
        else if (movimento == KEY_LEFT) //movimento para esquerda
            pontos= pontos + movimento_para_esquerda(tabuleiro);
        
        refresh();
        adiciona_numero(tabuleiro);
        imprimir(tabuleiro);
    }
    endwin();//termina o progrma
    return 0;
}