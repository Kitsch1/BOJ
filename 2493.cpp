#include <cstdio>
#include <stack>
#include <utility>
using namespace std;

int t_len[500001];
int t_idx[500001];

int main(){
    int n;
    stack<pair<int,int>> t_stack;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t_len[i]);
    }
    t_stack.push(make_pair(t_len[n],n));
    for(int i=n-1;i>=1;i--){
        int cur_height = t_len[i];
        int cur_idx = i;
        while(!t_stack.empty() && cur_height >= t_stack.top().first){
            t_idx[t_stack.top().second] = cur_idx;
            t_stack.pop();
        }
        t_stack.push(make_pair(cur_height,cur_idx));
    }
    for(int i=1;i<=n;i++){
        printf("%d ",t_idx[i]);
    }
    printf("\n");

    return 0;
}