#include <stdio.h>
#include <stdlib.h>

float catalan(int n){
    if(n < 2){
        return 1;
    }
    return (((4*n) - 2)*(catalan(n-1)))/(n+1);
}

int main(){
    int n,X;
    scanf("%d",&n);
    while(n >= 0){
        float c = catalan(n);
        round(c);
        X = c;
        printf("%d\n",X);
        scanf("%d",&n);
    }
}
