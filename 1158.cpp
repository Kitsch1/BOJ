#include <cstdio>
#include <queue>
using namespace std;

int m,n;
queue<int> jose;

void solve(){
    printf("<");
    while(jose.size() > 1){
        int cur_top;
        for(int i=1;i<n;i++){
            cur_top = jose.front();
            jose.pop();
            jose.push(cur_top);
        }
        cur_top = jose.front();
        printf("%d, ",cur_top);
        jose.pop();
    }
    printf("%d>\n",jose.front());
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        jose.push(i);
    }
    solve();

    return 0;
}