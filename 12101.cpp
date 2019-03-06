#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> all_sum;
vector<int> cur_sum;

void solve(int n){
    if(!n){
        all_sum.push_back(cur_sum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(n-i >= 0){
            cur_sum.push_back(i);
            solve(n-i);
            cur_sum.pop_back();
        }
    }
}

int main(){
    int n,order;
    scanf("%d %d",&n,&order);
    solve(n);
    int size = all_sum.size();
    if(order > size){
        printf("-1\n");
    }
    else{
        int o_size = all_sum[order-1].size();
        for(int i=0;i<o_size-1;i++){
            printf("%d+",all_sum[order-1][i]);
        }
        printf("%d\n",all_sum[order-1][o_size-1]);
    }

    return 0;
}