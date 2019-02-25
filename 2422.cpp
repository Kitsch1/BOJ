#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> not_good;
vector<int> ice_comb;
int res = 0;

bool check(int cur_ice){
    int size = ice_comb.size();
    for(auto a : not_good[cur_ice]){
        for(int i=0;i<size;i++){
            if(a == ice_comb[i]) return false;
        }
    }
    return true;
}

void solve(int n){
    int size = ice_comb.size();
    if(size == 3){
        res += 1;
        return;
    }
    int start_ice = ice_comb[size-1];
    for(int i=start_ice+1;i<=n;i++){
        if(check(i)){
            ice_comb.push_back(i);
            solve(n);
            ice_comb.pop_back();
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    not_good.resize(n+1);
    for(int i=0;i<m;i++){
        int ice_1,ice_2;
        scanf("%d %d",&ice_1,&ice_2);
        not_good[ice_1].push_back(ice_2);
        not_good[ice_2].push_back(ice_1);
    }
    int possible = n-2;
    for(int i=1;i<=possible;i++){
        ice_comb.push_back(i);
        solve(n);
        ice_comb.pop_back();
    }
    printf("%d\n",res);

    return 0;
}