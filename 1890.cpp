#include <cstdio>
#include <cstring>

int n;
long long board[100][100];
long long way_to_go[100][100];

long long solve(int r_cur,int c_cur){
    if(r_cur >= n || c_cur >= n){
        return 0;
    }
    if(board[r_cur][c_cur] == 0){
        if(r_cur == n-1 && c_cur == n-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    //printf("r : %d c: %d\n",r_cur,c_cur);
    long long& ans = way_to_go[r_cur][c_cur];
    if(ans != -1) return ans;
    ans = 0;
    long long jumping = board[r_cur][c_cur];

    return ans += solve(r_cur+jumping,c_cur) + solve(r_cur,c_cur+jumping);
}

int main(){
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%lld",&board[r][c]);
        }
    }
    memset(way_to_go,-1,sizeof(long long)*100*100);
    printf("%lld\n",solve(0,0));

    return 0;

}