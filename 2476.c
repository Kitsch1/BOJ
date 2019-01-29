#include <stdio.h>
#include <string.h>

int dice_res[7];

int main(){
    int n,i,dice;
    int res = -1, cur_res;
    scanf("%d",&n);
    while(n > 0){
        cur_res = -1;
        for(i=0;i<3;i++){
            scanf("%d",&dice);
            dice_res[dice] += 1;
        }
        for(i=1;i<=6;i++){
            if(dice_res[i] == 3){
                cur_res = 10000 + (i*1000);
                break;
            }
            else if(dice_res[i] == 2){
                cur_res = 1000 + (i*100);
                break;
            }
        }
        if(cur_res == -1){
            for(i=6;i>=1;i--){
                if(dice_res[i]){
                    cur_res = i*100; break;
                }
            }
        }
        if(res < cur_res) res = cur_res;

        memset(dice_res,0,sizeof(int)*7);
        n -= 1;
    }
    printf("%d\n",res);

    return 0;
}