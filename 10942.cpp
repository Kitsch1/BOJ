#include <cstdio>
#include <cstring>

int numbers[2001];
int dp[2001][2001];

int solve(int start,int end){
    if(start == end){
        return 1;
    }
    if(end-start == 1){
        if(numbers[start] == numbers[end]) return 1;
        else return 0;
    }
    int& ans = dp[start][end];
    if(ans != -1) return ans;

    if(numbers[start] != numbers[end]) return ans = 0;
    else return ans = solve(start+1,end-1);
}

int main(){
    int n,question;
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        scanf("%d",&numbers[r]);
    }
    memset(dp,-1,sizeof(int)*2001*2001);
    scanf("%d",&question);
    for(int i=1;i<=question;i++){
        int start,end;
        scanf("%d %d",&start,&end);
        printf("%d\n",solve(start,end));
    }

    return 0;
}