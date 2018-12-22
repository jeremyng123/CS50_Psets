#include <stdio.h>

int main (void){
    int height;
    int block = 0;
    do {
        printf("Please enter the height of pyramid you want to build: ");
        scanf("%d", &height);
    }
    while (height < 0 || height > 23);
    for (int i=1; i<=height;i++) {
        for (int j=0;j<height-i;j++) printf(" ");
        while (block < i+1) {
            printf("#");
            block ++;
        } block = 0;
        printf("\n");
    }
    return 0;
}