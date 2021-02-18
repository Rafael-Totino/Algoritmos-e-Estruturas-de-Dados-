#include <stdio.h>
#include <stdlib.h>

int subtracao(int A,int B){
    if(B == 0){
        return A;
    }
    else {
        return subtracao((A-1),(B-1));
    }
}

int main(){
    int A,B,sub;
    scanf("%d %d",&A,&B);
    sub = subtracao(A,B);
    printf("%d\n",sub);
}
