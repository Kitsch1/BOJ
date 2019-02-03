#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n,m;
    queue<int> jose;
    scanf("%d %d",&n,&m);

    for(int r=1;r<=n;r++){
        jose.push(r);
    }
    printf("<");
    while(jose.size() > 1){
        int cur_front;
        for(int r=1;r<m;r++){
            cur_front = jose.front();
            jose.pop();
            jose.push(cur_front);
        }
        printf("%d, ",jose.front());
        jose.pop();
    }
    printf("%d>\n",jose.front()); 

    return 0;
}