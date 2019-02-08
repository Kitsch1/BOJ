#include <cstdio>

bool rec[100][100];

int main(){
    int paper;
    scanf("%d",&paper);
    while(paper > 0){
        int r_start,c_start;
        scanf("%d %d",&r_start,&c_start);
        for(int r=r_start;r<r_start+10;r++){
            for(int c=c_start;c<c_start+10;c++){
                rec[r][c] = true;
            }
        }

        paper -= 1;
    }
    int res = 0;
    for(int r=0;r<100;r++){
        for(int c=0;c<100;c++){
            if(rec[r][c]) res += 1;
        }
    }
    printf("%d\n",res);

    return 0;
}