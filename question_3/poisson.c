#include "poisson.h"
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1; // 0! and 1! is 1
    }
    else
    {
        return n * factorial(n - 1);
    }
}
void poisson (int lamda,int k){
 long double p_x = (pow(lamda, k) / factorial(k)) * exp(-lamda);
 printf("poisson for lamda: %d , k: %d is: %.10Lf\n", lamda, k, p_x);
}


