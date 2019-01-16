#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

bool lotto[12];
vector<int> selected;

void solve(int k,vector<int> &all_numbers){
    int size = selected.size();
    if(size == 6){
        for(int i=0;i<6;i++){
            printf("%d ",selected[i]);
        }
        printf("\n");
        return;
    }
    int cur_start = -1;
    for(int i=k-1;i>=0;i--){
        if(lotto[i] == true){
            cur_start = i + 1;
            break;
        }
    }
    if(cur_start == -1) cur_start = 0;
    for(int i=cur_start;i<k;i++){
        lotto[i] = true; selected.push_back(all_numbers[i]);
        solve(k,all_numbers);
        lotto[i] = false; selected.pop_back();
    }
}

int main(){
    while(1){
        int k;
        scanf("%d",&k);
        if(k==0) break;
        vector<int> all_numbers(k);
        for(int i=0;i<k;i++){
            scanf("%d",&all_numbers[i]);
        }
        solve(k,all_numbers);
        printf("\n");
    }

    return 0;
}