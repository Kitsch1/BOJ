#include <cstdio>
#include <vector>
using namespace std;

void solve(int n,int m,vector<int> &v){
    int size = v.size();
    if(size == m){
        for(int i=0;i<size;i++){
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++){
        v.push_back(i);
        solve(n,m,v);
        v.pop_back();
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v;

    solve(n,m,v);

    return 0;
}