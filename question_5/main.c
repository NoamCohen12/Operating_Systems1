#include <stdio.h>
#include <stdlib.h>
#include "maxSubArr.h"

void generateRandomNumber(int min, int max, int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        // Generate a random number within the given range
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int main(int argc, char **argv)
{
    int size;
    int random_seed;
    int min = -25;
    int max = 74;
    if (argc != 3)
    {
        printf("size or random seed invalid\n");
        return -1;
    }
    if (sscanf(argv[1], "%d", &random_seed) != 1)
    {
        printf("souhld be int\n");
        return -1;
    }

    if (sscanf(argv[2], "%d", &size) != 1)
    {
        printf("souhld be int\n");
        return -1;
    }

    srand(random_seed); // init seed number

    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        printf("Memory not allocated\n");
    }

    generateRandomNumber(min, max, arr, size);
    printf("the max sub array is:%d\n ", max_sub_array(arr, size));
    free(arr);
    return 1;
}