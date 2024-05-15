#include <stdio.h>
void rec();

int main(){
 rec();
}

void rec(){
    int x = 1;
    while (x)
    {
        rec();
    }
}