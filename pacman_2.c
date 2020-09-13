/*bibliotecas*/
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

/*constantes*/
#define LINHAS 40 /*tamanho maximo do labirinto*/
#define COLUNAS 80 /*tamanho maximo do labirinto*/
#define PAREDE 'H' 
#define PASTILHAS '.'
#define PASTILHA_ESP 'o'
#define FUNDO ' '
#define PACMAN 'C'

#define COR_PAREDE 1 /*PAREDES*/
#define COR_PACMAN 2 /*PACMAN*/
#define COR_PASTILHAS_ESP 3 /*PASTILHAS ESPECIAL*/
#define COR_PASTILHAS 5 /*PASTILHAS*/
#define COR_FUNDO 6 /*FUNDO*/

typedef struct coordenadas
{
   int ls,
     li,
     cs,
     ci;
}COORDENADAS;

/*funções*/
void imprimir(char **labirinto, COORDENADAS pacman, int pontos){
   
    int i,j,lp,cp;

    /*colocando o pacman no labirinto*/
    for ( lp = 0; lp < (pacman.li); lp++){
        for (cp = 0; pc < pacman.ci; cp++){
            labirinto[lp][cp] = PACMAN;
        }  
    }
    /*imprimindo o labirinto*/
    clear();
    refresh();
    bkgd(COLOR_PAIR(COR_PASTILHAS));
    printw("     pontos: %d\n", pontos);
    printw("\n");
    for (i=0; i < LINHAS; i++){
            for(j=0; j < COLUNAS; j++){
                if (labirinto[i][j] == PAREDE){
                    attron(COLOR_PAIR(COR_PAREDE));
                    printw("%c", labirinto[i][j]);
                    attroff(COLOR_PAIR(COR_PAREDE));
                }
                else if (labirinto[i][j] == PASTILHA_ESP){
                    attron(COLOR_PAIR(COR_PASTILHAS_ESP));
                    printw("%c", labirinto[i][j]);
                    attroff(COLOR_PAIR(COR_PASTILHAS_ESP));
                }
                else if (labirinto[i][j] == PACMAN){
                    attron(COLOR_PAIR(COR_PACMAN));
                    printw("%c", labirinto[i][j]);
                    attroff(COLOR_PAIR(COR_PACMAN));
                }
                else if (labirinto[i][j] == FUNDO){
                    attron(COLOR_PAIR(COR_FUNDO));
                    printw("%c", labirinto[i][j]);
                    attroff(COLOR_PAIR(COR_FUNDO);
                }
                else {
                    printw("%c", labirinto[i][j]);
                }
            }
                printw("\n");
        }
}

/*criando o labirinto*/
char** comecando_labirinto(){
    int i, j;
    char **labirinto;
    labirinto = (char**) malloc(LINHAS *sizeof(char*));       
    for(i = 0; i < LINHAS; i++){
        labirinto[i] = (char*) malloc(COLUNAS *sizeof(char));  
        for(j = 0; j < COLUNAS; j++){
            /*montando o labirinto*/
            if(i == 0 || i == (LINHAS-1) || j == 0 || j == (COLUNAS-1) )
               labirinto[i][j] = PAREDE;
            else{
               labirinto[i][j] = PASTILHAS;
            }
        }
    }
       return labirinto;
}

/*contruindo as pasredes do labirinto*/
void paredes_labirinto(char **labirinto){

    int i,j;
    /*criando o lugar aonde os fantamas ficaram*/
    for (i=35; i < 44; i++){
        labirinto[16][i] = PAREDE;
        labirinto[24][i] = PAREDE;
    }
    for (j=16; j < 25; j++){
        labirinto[j][34] = PAREDE;
        labirinto[j][44] = PAREDE;
    }
    for (i=17;i < 24; i++){
        for (j=35; j< 44; j++){
            labirinto[i][j] = FUNDO;
        }
    }
    /*colocando as pastilhas especiais*/
    for (i=1;i < 3; i++){
        for (j=2; j< 4; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=37;i < 39; i++){
        for (j=2; j< 4; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=1;i < 3; i++){
        for (j=76; j< 78; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=37;i < 39; i++){
        for (j=76; j< 78; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    /**/
    for (i=4;i < 12; i++){
        for (j=4; j< 12; j++){
            labirinto[i][j] = PAREDE;
        }
    }
    /**/
    for(i=15; i < 21; i++){
        labirinto[4][i] = PAREDE;
        labirinto[8][i] = PAREDE;
    }
    /**/
    for(j=24; j < 30; j++){
        labirinto[4][j] = PAREDE;
        labirinto[8][j] = PAREDE;
    }
    /**/
    for (i=1;i < 6; i++){
        for (j=36; j< 44; j++){
            labirinto[i][j] = PAREDE;
        }
    }
    /**/
    for(i=36; i < 44; i++){
        labirinto[9][i] = PAREDE;
    }
    /**/
    for ( i=15; i < 18; i++){
        for ( j=1; j < 8; j++){
            labirinto[i][j] = PAREDE;
        }    
    }
    /**/
    for ( i=25; i < 28; i++){
        for ( j=1; j < 8; j++){
            labirinto[i][j] = PAREDE;
        }    
    }
    /**/
    for ( i=34; i < 36; i++){
        for ( j=4; j < 10; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=18; i < 25; i++){
        for ( j=14; j < 17; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=15; i < 28; i++){
        for ( j=17; j < 20; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=12; i < 15; i++){
        for ( j=26; j < 29; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=18; i < 21 ; i++){
        for ( j=26; j < 28; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    /**/
    for ( i=28; i < 31; i++){
        for ( j=26; j < 29; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=37; i < 39; i++){
        for ( j=25; j < 31; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /**/
    for ( i=34; i < 36; i++){
        for ( j=37; j < 44; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    /*outra metade*/
    for (i=4;i < 12; i++){
        for (j=68; j < 76; j++){
            labirinto[i][j] = PAREDE;
        }
    }

    for(i=59; i < 65; i++){
        labirinto[4][i] = PAREDE;
        labirinto[8][i] = PAREDE;
    }

    for(j=50; j < 56; j++){
        labirinto[4][j] = PAREDE;
        labirinto[8][j] = PAREDE;
    }

    for ( i=15; i < 18; i++){
        for ( j=72; j < 79; j++){
            labirinto[i][j] = PAREDE;
        }    
    }

    for ( i=25; i < 28; i++){
        for ( j=72; j < 79; j++){
            labirinto[i][j] = PAREDE;
        }    
    }

    for ( i=34; i < 36; i++){
        for ( j=70; j < 76; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    for ( i=18; i < 25; i++){
        for ( j=63; j < 66; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    for ( i=15; i < 28; i++){
        for ( j=60; j < 63; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    for ( i=12; i < 15; i++){
        for ( j=51; j < 54; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    for ( i=18; i < 21 ; i++){
        for ( j=52; j < 54; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    
    for ( i=28; i < 31; i++){
        for ( j=51; j < 54; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
    
    for ( i=34; i < 36; i++){
        for ( j=70; j < 76; j++){
            labirinto[i][j] = PAREDE;
        }  
    }

    for ( i=37; i < 39 ; i++){
        for ( j=49; j < 55; j++){
            labirinto[i][j] = PAREDE;
        }  
    }
}

/*colocando as coordenadas do pacman  no labirinto*/
void colocar_pacman(COORDENADAS *p){

    (*p).ls = 28;
    (*p).cs = 38;
    (*p).li = 30;
    (*p).ci = 40;

}

/*testando o movimento para esquerda*/
int testar_movimento_esquerdo(char **labirinto, COORDENADAS pacman){

    int i = 0;
    int tem_parede = 1;
    /*testando movimento esquerda*/
    while( i < 3 || tem_parede != 0 ){
        if (labirinto[pacman.ls+i][pacman.cs-1] == PAREDE) {
            tem_parede = 0;
        }
        i++;
    }
    return tem_parede;
}

/*movimentando o pacman para a esquerda*/
void movimento_pacman_esquerdo(char **labirinto, COORDENADAS *p, int *pontos){

    int i,l,c;
    l=(*p).ls;
    c=(*p).cs-1;
    for (i=0; i < 3; i++){
        if (labirinto[l+i][c] == PASTILHAS) {
            *pontos=*pontos+10;
        }
        else if (labirinto[l+i][c] == PASTILHA_ESP){
            *pontos=*pontos+100;
        }
    }

    /*tirando as pastilhas do mapa*/
    l=(*p).li;
    for (i=0; i < 3; i++){
        l=l-i;
        labirinto[l][(*p).ci] == FUNDO;
    }
    /*movimentando os pacman*/
    (*p).cs--;
    (*p).ci--;

}

/*testando o movimento para a direita*/
int testar_movimento_direita(char **labirinto, COORDENADAS pacman){
    
    int i;
    int tem_parede = 1;
    /*testando movimento direita*/
    while( i < 3 || tem_parede != 0 ){
        if (labirinto[pacman.li-i][pacman.ci+1] == PAREDE) {
            tem_parede = 0;
        }
        i++;
    }
    return tem_parede;
}

/*movimentando o pacman para a direita*/
void movimento_pacman_direita(char **labirinto, COORDENADAS *p, int *pontos){
    
    int i,l,c;

    /*pontuação do jogo*/
    l=(*p).li;
    c=(*p).ci;
    for  (i = 0; i < 3; i++){
        l=l+1;
         if (labirinto[l-i][c+1] == PAREDE) {
            *pontos=*pontos+10;
        }
        else if (labirinto[l-i][c+1] == PASTILHA_ESP){
            *pontos=*pontos+100;
        }
    }

    /*tirando as pastilhas do mapa*/
     l=(*p).ls;
    for (i=0; i < 3; i++){
        l=l+1
        labirinto[l][(*p).cs] == FUNDO;
    }
    /*movimentando para a direita*/
    (*p).ls++;
    (*p).li++;
}

/*testando o movimento para cima*/
int testar_movimento_cima(char **labirinto, COORDENADAS pacman){

    int i;
    int tem_parede = 1;
    /*testando movimento direita*/
    while( i < 3 || tem_parede != 0 ){
        if (labirinto[pacman.ls-1][pacman.cs+i] == PAREDE) {
            tem_parede = 0;
        }
        i++;
    }
    return tem_parede;
}

/*movimentando o pacman para cima*/
void movimento_pacman_cima(char **labirinto, COORDENADAS *p){
    
    int i,c,l;

    /*contando os pontos*/
    l=(*p).ls;
    c=(*p).cs;
    for ( i = 0; i < 3; i++){
        if (labirinto[l-1][c+i] == PASTILHAS) {
            *pontos=*pontos+10;
        }
        else if (labirinto[l-1][c+i] == PASTILHA_ESP){
            *pontos=*pontos+100;
        }
    }
    
    /*tirando as pastilhas do mapa*/
    c=(*p).ci;
    for (i=0; i < 3; i++){
        c=c-i;
        labirinto[(*p).li][c] == FUNDO;
    }
    /*movimentando para a direita*/
    (*p).ls--;
    (*p).li--;
}

/*testando o movimento para baixo*/
int testar_movimento_baixo(char **labirinto, COORDENADAS pacman){

    int i;
    int tem_parede = 1;
    /*testando movimento para baixo*/
    while( i < 3 || tem_parede != 0 ){
        if (labirinto[pacman.li+1][pacman.ci-i] == PAREDE) {
            tem_parede = 0;
        }
        i++;
    }
    return tem_parede;
}

/*movimentando o pacman para a baixo*/
void movimento_pacman_baixo(char **labirinto, COORDENADAS *p){
    
    int i,c,l;

    /*pontos*/
    l=(*p).li;
    c=(*p).ci;
    for ( i = 0; i < 3; i++){
        if (labirinto[l+1][c-i] == PASTILHAS) {
            *pontos=*pontos+10;
        }
        else if (labirinto[l+1][c-i] == PASTILHA_ESP){
            *pontos=*pontos+100;
        }
    }

    /*tirando as pastilhas do mapa*/
    for (i=0; i < 3; i++){
        c=(*p).cs+i;
        labirinto[(*p).ls][c] == FUNDO;
    }
    /*movimentando para a baixo*/
    (*p).ls++;
    (*p).li++;
}

/*inicializando o jogo*/
void inicializando_jogo(char **labirinto, COORDENADAS pacman,){

    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    paredes_labirinto(labirinto);
    colcando_pacman( &pacman);

}

/*testando se o jogo ja acabou*/
void proxima_fase(char **labirinto){

    int i,j;
    int nao_acabou = 1;

    while ( i < LINHAS || nao_acabou != 0 ){
        while(j < COLUNAS || nao_acabou != 0){
            if (labirinto[i][j] == PASTILHAS || labirinto[i][j] == PASTILHA_ESP  ){
                    nao_acabou=0;
                }
        }
    }

    return nao_acabou;
}

/*comecando novamente o jogo*/
void comecar_novamente(char **labirinto, int *t){

    *t=*t-10;
    int i,j;
    for (i = 0; i < LINHAS; i++){
        for (j= 0; j < COLUNAS; j++){
            if (labirinto[i][j] == FUNDO){
                labirinto[i][j] = PASTILHAS
            }
        }
    }

    /*colocando o local dos fantasmas*/
    for (i=17;i < 24; i++){
        for (j=35; j< 44; j++){
            labirinto[i][j] = FUNDO;
        }
    }

    /*colocando as pastilhas especiais*/
    for (i=1;i < 3; i++){
        for (j=2; j< 4; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=37;i < 39; i++){
        for (j=2; j< 4; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=1;i < 3; i++){
        for (j=76; j< 78; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }

    for (i=37;i < 39; i++){
        for (j=76; j< 78; j++){
            labirinto[i][j] = PASTILHA_ESP;
        }
    }
}

int main(){

    char **labirinto;
    labirinto = comecando_labirinto();
    char tecla;
    COORDENADAS pacman;
    int pontos = 0;
    int time = 1000;

    /*começo do jogo*/
    inicializando_jogo(labirinto, pacman);
    /*cores*/
    start_color();
    init_pair(COR_PAREDE, COLOR_GREEN, COLOR_GREEN);/*PAREDES*/
    init_pair(COR_PACMAN, COLOR_YELLOW, COLOR_YELLOW);/*PACMAN*/
    init_pair(COR_PASTILHAS_ESP, COLOR_MAGENTA, COLOR_MAGENTA);/*PASTILHAS ESPECIAL*/
    init_pair(COR_PASTILHAS, COLOR_WHITE, COLOR_BLACK);/*PASTILHAS*/
    init_pair(COR_FUNDO, COLOR_BLACK, COLOR_BLACK);/*FUNDO*/

    printw("Para jogar use as setas do teclado\n");
    printw("Aperta ' s ' para começar\n");
    printw("Ou apertar ' q ' para sair ");
    tecla = getch(); /*esperando a tecla s */
    imprimir_tabuleiro(labirinto, pacman, pontos);

    while (tecla != q  || proxima_fase(labirinto) ){

        movimento = getch();
        nanosleep(time);
        /*movimento para cima*/
        if (movimento == KEY_UP){
            if (testar_movimento_cima(labirinto,pacman)){
                movimento_pacman_cima(labirinto,&pacman,&pontos);
            }
        }
        /*movimento para baixo*/
        else if (movimento == KEY_DOWN){
            if (testar_movimento_baixo(labirinto,pacman)){
                movimento_pacman_baixo(labirinto,&pacman);
            }
        }
        /*movimento para direita*/
        else if (movimento == KEY_RIGHT){
            if (testar_movimento_direita(labirinto,pacman)){
                movimento_pacman_direita(labirinto,&pacman);
            }
        }
        /*movimento para esquerda*/
        else if (movimento == KEY_LEFT){
            if (testar_movimento_esquerdo(labirinto,pacman)){
                movimento_pacman_esquerdo(labirinto,&pacman);
            }
        }

        if(proxima_fase(labirinto)){
            comecar_novamente(labirinto,&time);
            colocar_pacman(&pacman);
        } 
        imprimir_tabuleiro(labirinto, pacman, pontos);
    }

    endwin();
    return 0;
}