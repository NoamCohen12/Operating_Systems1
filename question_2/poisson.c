#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Error\nUsage: %s <lamda> <k>\n", argv[0]);
        return 1;
    }
    double lamda = atof(argv[1]);
    int k = atoi(argv[2]);
    long double p_x = (pow(lamda, k) / factorial(k)) * exp(-lamda);
    printf("poisson for lamda: %.2f , k: %d is: %.10Lf\n", lamda, k, p_x);
    return 0;
}
