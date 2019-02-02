#include <stdio.h>

int people[15][15];

int main(){
    int tcase,r,c;
    int cur_floor,room;
    for(c=1;c<15;c++){
        people[0][c] = c;
    }
    for(r=1;r<15;r++){
        people[r][1] = 1;
        people[r][2] = people[r-1][1] + people[r-1][2];
        for(c=3;c<15;c++){
            people[r][c] = people[r-1][c] + people[r][c-1];
        }
    }
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&cur_floor);
        scanf("%d",&room);
        printf("%d\n",people[cur_floor][room]);
        tcase -= 1;
    }

    return 0;
}