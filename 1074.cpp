#include <iostream>
using namespace std;

long long ans = 0;
bool flag = false;
int n;
int r_dst, c_dst;
int r_dst_start, c_dst_start;

void solve(int r,int c,int n){
    if(flag) return;
    if(n == 1){
        if(r == r_dst && c == c_dst){
            flag = true; return;
        }
        else if(r == r_dst && c == c_dst - 1){
            flag = true; ans += 1; return;
        }
        else if(r == r_dst - 1 && c == c_dst){
            flag = true; ans += 2; return;
        }
        else if(r == r_dst - 1 && c == c_dst - 1){
            flag = true; ans += 3; return;
        }
        else{
            ans += 4;
        }
        return;
    }

    int next = (1<<(n-1));
    solve(r,c,n-1);
    solve(r,c+next,n-1);
    solve(r+next,c,n-1);
    solve(r+next,c+next,n-1);
}

int main(){
    cin >> n >> r_dst >> c_dst;
    
    if(r_dst % 2 == 1) r_dst_start = r_dst - 1;
    else r_dst_start = r_dst;

    if(c_dst % 2 == 1) c_dst_start = c_dst - 1;
    else c_dst_start = c_dst;

    solve(0,0,n);
    cout << ans << '\n';

    return 0;
}