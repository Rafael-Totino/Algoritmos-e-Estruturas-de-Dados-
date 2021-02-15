#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int A;
    scanf("ld",&A);
    if((A%400==0)||((A%4==0)&&(A%100!= 0))){
        printf("ANO BISSEXTO\n");
    }
    else{
        printf("ANO NAO BISSEXTO\n");
    }
    return 0;
}
