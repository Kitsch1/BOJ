#include <cstdio>
#include <cstring>

int score[101];
bool all_cases[101][10001];

int solve(int n){
    int cur_max = 0, res = 0;
    all_cases[1][0] = all_cases[1][score[1]] = true;
    for(int r=2;r<=n;r++){
        cur_max += score[r-1];
        for(int c=0;c<=cur_max;c++){
            if(all_cases[r-1][c]){
                all_cases[r][c] = all_cases[r][c+score[r]] = true;
            }
        }
    }
    cur_max += score[n];
    for(int r=0;r<=cur_max;r++){
        if(all_cases[n][r]) res += 1;
    }
    return res;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int t=1;t<=tcase;t++){
        int n,score_max = 0;
        scanf("%d",&n);
        for(int r=1;r<=n;r++){
            scanf("%d",&score[r]);
            //score_max += score[r];
        }
        printf("#%d %d\n",t,solve(n));
        memset(score,0,sizeof(int)*101);
        memset(all_cases,false,sizeof(bool)*101*10001);
    }

    return 0;
}