#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int n;
    long long res = 0;
    scanf("%d",&n);
    vector<int> audiance(n);
    stack<pair<int,int>> oasis;
    for(int r=0;r<n;r++){
        scanf("%d",&audiance[r]);
    }
    for(int r=0;r<n;r++){
        pair<int,int> cur_aud;
        cur_aud.first = audiance[r];
        cur_aud.second = 1;
        while(!oasis.empty()){
            if(oasis.top().first <= audiance[r]){
                res += oasis.top().second;
                if(oasis.top().first == audiance[r]){
                    cur_aud.second += oasis.top().second;
                } // the number of people who have same height
                oasis.pop();
            }
            else{
                break;
            }
        }
        if(!oasis.empty()) res += 1; // top audiance taller than cur_aud can see cur_aud.
        oasis.push(cur_aud);
    }
    printf("%lld\n",res);

    return 0;
}