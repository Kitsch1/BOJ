#include <stdio.h>

int main(){
    int n,m,k,i,j; // n : girl, m : boy
    int boy_contest,girl_contest;
    int cur_team,res = -1;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<=k;i++){
        if(m-i > 0 && n-(k-i) > 0){
            boy_contest = m-i;
            girl_contest = n-(k-i);
            cur_team = -1;
            for(j=boy_contest;j>=0;j--){
                if(j*2<=girl_contest && cur_team < j){
                    cur_team = j;
                }
            }
            if(res < cur_team) res = cur_team;
        }
    } // i : the number of boy intern
    printf("%d\n",res);

    return 0;
}