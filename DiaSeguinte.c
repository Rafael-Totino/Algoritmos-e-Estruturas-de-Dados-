#include <stdio.h>
#include <stdlib.h>

int main(){
    int D,M,A,DiaAux,MesAux,AnoAux;
    scanf("%d %d %d",&D,&M,&A);

    if((D==31) && (M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12)){
        if(M==12){
            MesAux = 1;
            DiaAux = 1;
            AnoAux = A+1;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
        else {
            MesAux = M+1;
            DiaAux = 1;
            AnoAux = A;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
    }
    else if((D==30) && (M==4 || M==6 || M==9 || M==11)){
        MesAux = M+1;
        DiaAux = 1;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
    else if(M==2 && D==28){
        if((A%400==0)||((A%4==0)&&(A%100!= 0))){
            MesAux = M;
            DiaAux = D+1;
            AnoAux = A;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
        else {
            MesAux = M+1;
            DiaAux = 1;
            AnoAux = A;
            printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
    }
    else if(M==2 && D==29){
        MesAux = M+1;
        DiaAux = 1;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
        }
    else {
        MesAux = M;
        DiaAux = D+1;
        AnoAux = A;
        printf("%d %d %d\n",DiaAux,MesAux,AnoAux);
    }
}
