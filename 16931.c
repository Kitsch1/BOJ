#include <stdio.h>

int cube[102][102];
const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

int main(){
    int r_len,c_len,r,c,k,r_next,c_next;
    int ans = 0;
    scanf("%d %d",&r_len,&c_len);

    ans += 2*(r_len*c_len);
    for(r=1;r<=r_len;r++){
        for(c=1;c<=c_len;c++){
            scanf("%d",&cube[r][c]);
        }
    }
    for(r=1;r<=r_len;r++){
        for(c=1;c<=c_len;c++){
            for(k=0;k<4;k++){
                r_next = r + r_way[k];
                c_next = c + c_way[k];
                if(cube[r][c] > cube[r_next][c_next]){
                    ans += (cube[r][c] - cube[r_next][c_next]);
                }
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}