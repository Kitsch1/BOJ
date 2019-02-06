#include <cstdio>
#include <deque>
using namespace std;

int n,m;
int extract[50];
deque<int> dq;

int solve(){
    int res = 0;
    for(int i=0;i<m;i++){
        /*
        for(auto a : dq){
            printf("%d ",a);
        }
        printf("\n");
        */
        int size = dq.size();
        int front_cnt = 0, back_cnt = 1;
        if(dq.front() == extract[i]){
            dq.pop_front();
        }
        else if(dq.back() == extract[i]){
            dq.pop_back();
            res += 1;
        }
        else{
            while(dq[front_cnt] != extract[i]){
                front_cnt += 1;
            }
            for(auto a=dq.end()-1;;a--){
                if(*a == extract[i]) break;
                back_cnt += 1;
            }
            if(front_cnt > back_cnt){
                for(int i=0;i<back_cnt;i++){
                    int cur_back = dq.back();
                    dq.pop_back();
                    dq.push_front(cur_back);
                }
                dq.pop_front();
                res += back_cnt;
            }
            else{
                for(int i=0;i<front_cnt;i++){
                    int cur_front = dq.front();
                    dq.pop_front();
                    dq.push_back(cur_front);
                }
                dq.pop_front();
                res += front_cnt;
            }
        }
    }
    return res;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&extract[i]);
    }
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    printf("%d\n",solve());

    return 0;
}