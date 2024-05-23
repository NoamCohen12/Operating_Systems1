#include <stdio.h>
#include "maxSubArr.h"

int max_sub_array(int *array, int n)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += array[k];
            }
            best = (best > sum) ? best : sum;
        }
    }
    return best;
}
