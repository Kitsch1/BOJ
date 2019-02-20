#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int n;
int dp[500][500];
vector<pair<int,int>> matrices;

int solve(int m_start,int m_end){
    if(m_start == m_end) return 0;
    if(m_end - m_start == 1){
        return matrices[m_start].first * matrices[m_start].second * matrices[m_end].second;
    }
    
    int& ans = dp[m_start][m_end];
    if(ans != -1) return ans;
    for(int i=m_start;i<=m_end;i++){
        int mat_front = solve(m_start,i);
        int mat_back = solve(i+1,m_end);
        int cur_ans = mat_front + mat_back + (matrices[m_start].first * matrices[i].second * matrices[m_end].second);
        if(ans == - 1 || ans > cur_ans) ans = cur_ans;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int row,col;
        scanf("%d %d",&row,&col);
        matrices.push_back(make_pair(row,col));
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,n-1));

    return 0;
}