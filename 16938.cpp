#include <cstdio>
#include <vector>
using namespace std;

int n,lower,upper,diff;
int p_level[15];
int ans = 0;
vector<int> selected;

void solve(int idx){
    if(n == idx){
        int size = selected.size();
        if(size < 2) return;
        
        int all_sum,low_level,high_level;
        all_sum = low_level = high_level = selected[0];
        for(int r=1;r<size;r++){
            all_sum += selected[r];
            if(low_level > selected[r]) low_level = selected[r];
            if(high_level < selected[r]) high_level = selected[r];
        }
        if(all_sum >= lower && all_sum <= upper && (high_level-low_level) >= diff) ans += 1;
        return;
    }
    selected.push_back(p_level[idx]);
    solve(idx+1);
    selected.pop_back();
    solve(idx+1);
}

int main(){
    scanf("%d %d %d %d",&n,&lower,&upper,&diff);
    for(int r=0;r<n;r++){
        scanf("%d",&p_level[r]);
    }
    solve(0);
    printf("%d\n",ans);

    return 0;
}