#include <stdio.h>
#include <stdlib.h>

int adicao(int A,int B){
    if(B == 0){
        return A;
    }
    else {
        return adicao((A+1),(B-1));
    }
}

int main(){
    int A,B,soma;
    scanf("%d %d",&A,&B);
    soma = adicao(A,B);
    printf("%d\n",soma);
}
