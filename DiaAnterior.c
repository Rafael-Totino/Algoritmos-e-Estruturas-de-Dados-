#include <stdio.h>
#include <stdlib.h>

int main()
{
    int D,M,A,DiaAux,MesAux,AnoAux;

    scanf("%d %d %d\n",&D,&M,&A);

    if((D-1==0)&&(M==5 || M==7 || M==10 || M==12)){
        MesAux = M-1;
        DiaAux = 30;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
    else if((D-1==0)&&(M==2 || M==4 || M==6 || M==8 || M==9 || M==11)){
        MesAux = M-1;
        DiaAux = 31;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
    else if(D-1==0 && M==1){
        MesAux = 12;
        DiaAux = 31;
        AnoAux = A-1;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
    else if(D-1==0 && M==3){
        if((A%400==0)||((A%4==0)&&(A%100!= 0))){
            MesAux = M-1;
            DiaAux = 29;
            AnoAux = A;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
        else {
            MesAux = M-1;
            DiaAux = 28;
            AnoAux = A;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
    }
    else {
        MesAux = M;
        DiaAux = D-1;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
}
