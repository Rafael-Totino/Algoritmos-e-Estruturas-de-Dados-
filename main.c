#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,*X,*X2,fig,count=0;
    scanf("%d",&N);
    scanf("%d",&M);

    X = (int*)malloc(M*sizeof(int));
    X2 = (int*)malloc(M*sizeof(int));

    for(int i=0;i<M;i++){
        scanf("%d",&X[i]);
        X2[i] = X[i];
    }
    for(int j=0;j<M;j++){
        for(int i=j+1;i<M;i++){
            if(X[j] == X2[i]){
                X2[i] = 0;
            }
        }
    }
    for(int i=0;i<M;i++){
        if(X2[i]!=0){
            count++;
        }
    }
    fig = N - count;
    printf("%d\n",fig);
}

