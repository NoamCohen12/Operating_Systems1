#include <stdio.h>
#include "maxSubArr.h"

int max_sub_array(int* array, int n)//o(n^2)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        int sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += array[b];
            best = (best > sum) ? best : sum;

        }
    }
    return best;
}
