#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int numbers[20];
int n,k;
int res = 0;

void make_all_sums(vector<int> &all_sums){
    int bound = (1<<n);
    for(int i=1;i<bound;i++){
        int cur_sum = 0;
        for(int j=0;j<n;j++){
            int find = (1<<j);
            if((i & find) != 0){
                cur_sum += numbers[j];
            }
            if(cur_sum > k) break; 
        }
        if(cur_sum == k){
            res += 1;
        }
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        scanf("%d %d",&n,&k);
        for(int j=0;j<n;j++){
            scanf("%d",&numbers[j]);
        }
        vector<int> all_sums;
        make_all_sums(all_sums);
        printf("#%d %d\n",i,res);
        memset(numbers,0,sizeof(int)*20);
        res = 0;
    }

    return 0;
}