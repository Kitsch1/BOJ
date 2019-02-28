#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int,int>> numbers;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        numbers.push_back({num,i+1});
    }
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<m;i++){
        int idx_start,idx_end,idx_find;
        scanf("%d %d %d",&idx_start,&idx_end,&idx_find);
        int cur_idx = 1;
        for(int j=0;j<n;j++){
            if(numbers[j].second < idx_start || numbers[j].second > idx_end) continue;
            if(cur_idx == idx_find){
                printf("%d\n",numbers[j].first); break;
            }
            else{
                cur_idx += 1;
            }
        }
    }

    return 0;
}