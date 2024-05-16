#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    if (argc != 3)
    {
        printf("size or random seed invalid");
        return -1;
    }
    int random_seed = argv[2];
    int size = argv[1];
}