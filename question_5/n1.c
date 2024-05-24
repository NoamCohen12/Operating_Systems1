#include <stdio.h>
#include "maxSubArr.h"
int max_sub_array(int *array, int n)//o(n)
{
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum = (array[k] > sum + array[k]) ? array[k] : sum + array[k];
        best = (best > sum) ? best : sum;
    }
    return best;
}