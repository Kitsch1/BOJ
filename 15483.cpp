#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string from,dest;
int dp[1001][1001];
int from_size,dest_size;

int solve(){
    for(int r=0;r<=from_size;r++){
        dp[r][0] = r;
    }
    for(int c=0;c<=dest_size;c++){
        dp[0][c] = c;
    }
    for(int r=1;r<=from_size;r++){
        for(int c=1;c<=dest_size;c++){
            if(from[r-1] == dest[c-1]){
                dp[r][c] = dp[r-1][c-1];
            }
            else{
                dp[r][c] = min(dp[r-1][c-1],min(dp[r][c-1],dp[r-1][c])) + 1;
            }
        }
    }
    return dp[from_size][dest_size];
}

int main(){
    cin >> from;
    cin >> dest;
    from_size = from.size();
    dest_size = dest.size();
    printf("%d\n",solve());

    return 0;
}