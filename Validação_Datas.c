#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int D,M,A;

    scanf("%ld %ld %ld",&D,&M,&A);

    if(A >= 1582 && A <= 2^31){
        if(M > 0 && M <= 12){
            if((D > 0 && D <= 31)&&(M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12)){
                printf("DATA VALIDA");
            }
            else if((D > 0 && D <= 30)&&(M==4 || M==6 || M==9 || M==11)){
                printf("DATA VALIDA");
            }
            else if((A%400==0 ||(A%4==0 && A%100!= 0)) && (M==2) && (D>0 && D<=29)){
                printf("DATA VALIDA");
            }
            else if(M==2 && (D>0 && D<=28)){
                printf("DATA VALIDA");
            }
            else {
                printf("DATA INVALIDA");
            }
        }
        else {
            printf("DATA INVALIDA");
        }
    }
    else {
        printf("DATA INVALIDA");
    }

    return 0;
}
