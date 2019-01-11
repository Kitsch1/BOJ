#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void solve(int n,int m,vector<int> &all_numbers,vector<int> &v){
    int size = v.size();
    if(size == m){
        for(int i=0;i<size;i++){
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++){
        v.push_back(all_numbers[i]);
        solve(n,m,all_numbers,v);
        v.pop_back();
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> all_numbers(n);
    for(int i=0;i<n;i++){
        scanf("%d",&all_numbers[i]);
    }
    vector<int> v;
    sort(all_numbers.begin(),all_numbers.end());

    solve(n,m,all_numbers,v);

    return 0;
}