#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        queue<int> jose;
        int n,k;
        scanf("%d %d",&n,&k);
        for(int r=2;r<=n;r++){
            jose.push(r);
        }
        while(jose.size() > 2){
            int cur_top;
            for(int r=1;r<k;r++){
                cur_top = jose.front();
                jose.pop();
                jose.push(cur_top);
            }
            jose.pop();
        }
        int p1 = jose.front();
        jose.pop();
        int p2 = jose.front();
        if(p1 > p2){
            printf("%d %d\n",p2,p1);
        }
        else{
            printf("%d %d\n",p1,p2);
        }

        tcase -= 1;
    }

    return 0;
}