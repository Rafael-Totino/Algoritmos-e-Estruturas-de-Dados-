#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dificuldade() {
  int dificuldade;

  printf("BATALHA NAVAL\nBem-vindo, marujo!\nVoce foi selecionado para defender o pais de uma invasao naval!\n");
  printf("Dois navios de pequeno porte e dois navios de grande porte compoem a frota inimiga.\nUm navio pequeno ocupa um espaco na tabela, para afunda-lo basta que voce acerte um tiro.\nNavios grandes ocupam dois espacos, para afunda-los voce precisa acertar dois tiros em duas ou mais tentativas.\n\n");
  printf("Escolha a dificuldade na qual deseja jogar:\n\n");
  printf("Para 'Facil' digite 1:\n\tNesta dificuldade voce tera um total de 28 tiros\n\n");
  printf("Para 'Medio' digite 2:\n\tNesta dificuldade voce tera um total de 20 tiros\n\n");
  printf("Para 'Dificil' digite 3:\n\tNesta dificuldade voce tera um total de 12 tiros\n\n");

  scanf("%d", &dificuldade);

  do{
    if(dificuldade == 1)
    {
      printf("Boa sorte!");
      return 30;
    }
    else if(dificuldade == 2)
    {
      printf("Boa sorte!");
      return 20;
    }
    else if(dificuldade == 3)
    {
      return 12;
      printf("Boa sorte! Voce vai precisar...\n\n");
    }
    else
    {
      printf("Por favor, digite apenas numeros de 1 a 3!\n");
      scanf("%d", &dificuldade);
    }
  }while(dificuldade > 3 || dificuldade < 1);
  return 0;
}


void inicializaCampoDeBatalha(int battlefield[6][6]){
  for(int y = 0; y < 6; y++)
  {
    for(int x = 0; x < 6; x++)
    {
      battlefield[y][x] = 0;
    }
  }
}

void visualizaCampoDeBatalha(int battlefield[6][6]){

  printf("\t1 \t2 \t3 \t4 \t5 \t6\n");

  for(int y = 0; y < 6; y++)
  {
    printf("%d", y+1);
    for(int x = 0; x < 6; x++)
    {
      if(battlefield[y][x] == 0)
      {
      printf("\t~");
      }
      else if(battlefield[y][x] == -1)
      {
      printf("\t*");
      }
      else if(battlefield[y][x] == 1)
      {
      printf("\tX");
      }
    }
    printf("\n\n\n");
  }
}


int TiroCerto(int disparo[2], int corveta[2][2], int fragata[2][4]) {
  int count=0;
  for(int i=0;i<2;i++) {
      if(disparo[0]==corveta[i][0] && disparo[1]==corveta[i][1]) {
        printf("\nEm cheio! Posicao: (%d,%d)\n\n", disparo[0]+1, disparo[1]+1);
        count++;
        return 1;
      }
      else if (disparo[0]==fragata[i][0] && disparo[1]==fragata[i][1]) {
        printf("\nVoce atingiu uma metade. Cuidado! Pode ser que ainda haja outra por ai!\n Posicao: (%d,%d) \n\n", disparo[0]+1, disparo[1]+1);
        count++;
        return 1;
      }
      else if (disparo[0]==fragata[i][2] && disparo[1]==fragata[i][3]) {
        printf("\nVoce atingiu uma metade. Cuidado! Pode ser que ainda tenha outra por ai!\n Posicao: (%d,%d) \n\n",disparo[0]+1, disparo[1]+1);
        count++;
        return 1;
      }
  }
  return 0;
}

void Atirar(int disparo[2],int battlefield[6][6]) {
  printf("Escolha a linha e a coluna para dar o tiro!\n");
  printf("Linha: ");
  scanf("%d", &disparo[0]);

  printf("Coluna: ");
  scanf("%d", &disparo[1]);

  if(disparo[0]<0 || disparo[0]>6 || disparo[1]<0 || disparo[1]>6){
    printf("Posicao invalida! insira coordenadas entre 0 e 6\n");
    Atirar(disparo,battlefield);
  }
  disparo[1]--;
  disparo[0]--;
}

void alteraCampoDeBatalha(int disparo[2], int fragata[2][4], int corveta[2][2], int battlefield[6][6],int R)
{
  if(R==1)
  {
    battlefield[disparo[0]][disparo[1]] = 1; //se as coordenadas do tiro forem a msms que a de um navio ou barco então a posição no tabuleiro mudará para o valor de 1 (tiro certeiro).
  }
  else
  {
    battlefield[disparo[0]][disparo[1]] = -1; //caso contrário, a posição receberá o valor "-1"
  }

}


void posicionaBarco(int corveta[2][2]) {
  srand(time(NULL));
  int navio, anterior;

  for(navio=0 ; navio < 2 ; navio++) {
    corveta[navio][0]= rand()%5;
    corveta[navio][1]= rand()%5;
    for(anterior=0 ; anterior < navio ; anterior++) {
      if( (corveta[navio][0] == corveta[anterior][0])&&(corveta[navio][1] == corveta[anterior][1]) ){
        do{
          corveta[navio][0]= rand()%5;
          corveta[navio][1]= rand()%5;
        } while( (corveta[navio][0] == corveta[anterior][0])&&(corveta[navio][1] == corveta[anterior][1]) );
      }
    }
  }
}

void posicionaNavio(int fragata[2][4], int corveta[2][2]) {
  srand(time(NULL));
  int navio, anterior, a, b, c, d;

  for(navio=0;navio<2;navio++) {
    do{
      a = rand()%5;
      fragata[navio][0]= a;
      b = rand()%5;
      fragata[navio][1]= b;

      for(anterior=0;anterior<navio;anterior++) {
        if( ((fragata[navio][0] == fragata[anterior][0])&&(fragata[navio][1] == fragata[anterior][1])) || ((fragata[navio][0] == fragata[anterior][2])&&(fragata[navio][1] == fragata[anterior][3]))) {

          do{
            a = rand()%5;
            fragata[navio][0]= a;
            b = rand()%5;
            fragata[navio][1]= b;
          } while( ((fragata[navio][0] == fragata[anterior][0])&&(fragata[navio][1] == fragata[anterior][1])) || ((fragata[navio][0] == fragata[anterior][2])&&(fragata[navio][1] == fragata[anterior][3])) );
        }
      }
    }
    while (((a==corveta[0][0])&&(b==corveta[0][1])) || ((a==corveta[1][0])&&(b==corveta[1][1])));

    do{
      c = rand()%5;
      fragata[navio][2]= c;
      d = rand()%5;
      fragata[navio][3]= d;
        for(anterior=0 ; anterior < navio ; anterior++) {
          if( ((fragata[navio][2] == fragata[anterior][2])&&(fragata[navio][3] == fragata[anterior][3])) || ((fragata[navio][2] == fragata[anterior][0])&&(fragata[navio][3] == fragata[anterior][1])) ) {
            do{
              c = rand()%5;
              fragata[navio][2]= c;
              d = rand()%5;
              fragata[navio][3]= d;
            } while( ((fragata[navio][2] == fragata[anterior][2])&&(fragata[navio][3] == fragata[anterior][3])) || ((fragata[navio][2] == fragata[anterior][0])&&(fragata[navio][3] == fragata[anterior][1])) );
          }
        }
    } while (c>(a+1) || c<(a-1) || d>(b+1) || d<(b-1) || (a==c && b==d) || ((c==corveta[0][0])&&(d==corveta[0][1])) || ((c==corveta[1][0])&&(d==corveta[1][1])));
  }
}

void dicaErro(int disparo[2], int battlefield[6][6], int iteracoes, int corveta[2][2], int fragata[2][4]){
  int dica_corveta_x=0, dica_corveta_y=0, i, j, x, y, dica_fragata_x=0, dica_fragata_y=0;
  x = disparo[0];
  y = disparo[1];

  for(i=0;i<2;i++){
      if(corveta[i][0]==x){
        dica_corveta_x++;
      }
      else if(corveta[i][1]==y){
        dica_corveta_y++;
      }
  }
  printf("\nDica %d: Disparo na agua! \nLinha %d -> Ha %d corvetas nesta linha\nColuna %d -> Ha %d corvetas nesta coluna\n\n",iteracoes,disparo[0]+1,dica_corveta_x,disparo[1]+1,dica_corveta_y);

  for (int j=0; j<2; j++){
    for(i=0;i<4;i++){
      if (j%2==0){
        if(fragata[j][i]==x){
          dica_fragata_x++;
        }
      }
      else{
        if(fragata[j][i]==y){
          dica_fragata_y++;
        }
      }
    }
  }
  printf("\nLinha %d -> Ha %d fragatas nesta linha\nColuna %d -> Ha %d fragatas nesta coluna\n\n",disparo[0]+1,dica_fragata_x,disparo[1]+1,dica_fragata_y);
}

int main() {
  int battlefield[6][6], fragata[2][4], corveta[2][2], disparo[2], iteracoes=0, navios_afundados=0, municao,R;

  municao = dificuldade();
  inicializaCampoDeBatalha(battlefield);
  posicionaBarco(corveta);
  posicionaNavio(fragata, corveta);
  printf("\n");

  do{
    visualizaCampoDeBatalha(battlefield);
    Atirar(disparo,battlefield);
    iteracoes++;
    R = TiroCerto(disparo,corveta,fragata);

    if(R==0) {
      dicaErro(disparo,battlefield,iteracoes, corveta, fragata);
    }
    else{
      navios_afundados++;
    }
    printf("Voce ainda tem %d tiros\n", (municao - iteracoes));
    alteraCampoDeBatalha(disparo, fragata, corveta, battlefield,R);
  } while(navios_afundados!=6 && iteracoes < municao);

  if((municao-iteracoes)==0 && navios_afundados!=6)
  {
    visualizaCampoDeBatalha(battlefield);
    printf("\n\nFim de jogo! Voce perdeu...\n\nAlguns navios conseguiram passar pelas suas defesas e seu pais foi invadido...\nBoa sorte na proxima!\n\n");
  }
  else if(municao-iteracoes>=0  && navios_afundados==6)
  {
    visualizaCampoDeBatalha(battlefield);
    printf("\n\nFim de jogo! Voce ganhou!!\n\nVoce afundou todos os navios inimigos e conseguiu conter a invasao inimiga.\n Parabens marujo!!\n\n");
  }
}
