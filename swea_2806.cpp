#include <cstdio>
#include <cstring>
using namespace std;

bool chess[10][10];
int n;
int res = 0;

bool checking(int r,int c){
    // left-side
    int r_check = r-1;
    int c_check = c-1;
    while(r_check >= 0 && c_check >= 0){
        if(chess[r_check][c_check]) return false;
        r_check -= 1; c_check -= 1;
    }
    // right-side
    r_check = r-1; c_check = c+1;
    while(r_check >= 0 && c_check < n){
        if(chess[r_check][c_check]) return false;
        r_check -= 1; c_check += 1;
    }
    // upupup
    r_check = r-1;
    while(r_check >= 0){
        if(chess[r_check][c]) return false;
        r_check -= 1;
    }

    return true;
}

void solve(int q_num){
    if(q_num == n){
        res += 1; return;
    }
    for(int i=0;i<n;i++){
        if(checking(q_num,i)){
            chess[q_num][i] = true;
            solve(q_num+1);
            chess[q_num][i] = false;
        }
    }
}


int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        scanf("%d",&n);
        solve(0);
        printf("#%d %d\n",i,res);
        memset(chess,false,sizeof(bool)*10*10);
        res = 0;
    }

    return 0;
}