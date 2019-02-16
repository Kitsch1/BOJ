#include <cstdio>
using namespace std;

int white_num,blue_num;
int paper[128][128];

bool check(int r,int c,int n){
    int f_color = paper[r][c];
    int r_limit = r + n;
    int c_limit = c + n;
    for(int i=r;i<r_limit;i++){
        for(int j=c;j<c_limit;j++){
            if(f_color != paper[i][j]) return false;
        }
    }
    return true;
}

void solve(int r,int c,int n){
    if(check(r,c,n)){
        if(paper[r][c]) blue_num += 1;
        else white_num += 1;
        return;
    }
    int half_n = n/2;
    solve(r,c,half_n);
    solve(r,c+half_n,half_n);
    solve(r+half_n,c,half_n);
    solve(r+half_n,c+half_n,half_n);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&paper[r][c]);
        }
    }
    solve(0,0,n);
    printf("%d\n%d\n",white_num,blue_num);

    return 0;
}