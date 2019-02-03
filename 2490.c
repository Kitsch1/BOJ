#include <stdio.h>

int up_down[2];

int main(){
    int i,j;
    int yoot[4];
    for(i=1;i<=3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&yoot[j]);
            up_down[yoot[j]] += 1;
        }
        switch(up_down[1]-up_down[0]){
            case 4 : printf("E\n"); break;
            case 2 : printf("A\n"); break;
            case 0 : printf("B\n"); break;
            case -2 : printf("C\n"); break;
            case -4 : printf("D\n"); break;
        }
        up_down[0] = up_down[1] = 0;
    }

    return 0;
}