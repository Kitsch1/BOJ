#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int namu,long long start, long long end,long long wood_need,vector<long long> &all_woods){
    long long sol = -1;
    long long mid;

    while(start <= end){
        mid = (start + end) / 2;
        long long cur_res = 0;
        for(int i=0;i<namu;i++){
            if(all_woods[i] > mid){
                cur_res += all_woods[i] - mid;
            }
        }
        if(cur_res >= wood_need){
            if(sol == -1 || sol < mid){
                sol = mid;
            }
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    printf("%lld\n",sol);
}

int main(){
    int namu;
    long long wood;
    long long start = 0;
    long long end = -1;

    scanf("%d %lld",&namu,&wood);
    vector<long long> all_woods;

    for(int i=0;i<namu;i++){
        long long cur;
        scanf("%lld",&cur);
        all_woods.push_back(cur);
        if(cur > end){
            end = cur;
        }
    }
    solve(namu,start,end,wood,all_woods);

    return 0;
}