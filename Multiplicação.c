#include<stdio.h>
#include <stdlib.h>

long int multiplica (int A, int B){


    if (A == 0){

        return 0;

    } else {

        return B + multiplica(A-1,B);

    }

}

int main() {

     unsigned long long int A,B, resultado;

     scanf("%lld %lld", &A, &B);

     resultado = multiplica(A,B);

     printf("%lld\n", resultado);

 return 0;

}
