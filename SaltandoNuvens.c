#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,K,i,*X,E=100;
    scanf("%d %d",&N,&K);

     X = (int*)malloc(N*sizeof(int));

     for(i=0;i<N;i++){
        scanf("%d",&X[i]);
     }
     for(i=0;i<N;i+=K){
        if(X[i]==1){
            E = E-3;
        }
        else{
            E = E-1;
        }
     }
     printf("%d\n",E);
}
