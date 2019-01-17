#include <iostream>
using namespace std;

bool chess[12][12];
int n;
int res;

bool possible(int cur_r,int cur_c){
    int next_r,next_c;

    for(int i=0;i<cur_r;i++){
        if(chess[i][cur_c]) return false;
    } // if same column

    next_r = cur_r-1; next_c = cur_c-1;
    while(next_r >= 0 && next_c >= 0){
        if(chess[next_r][next_c]) return false;
        next_r -= 1; next_c -= 1;
    }

    next_r = cur_r-1; next_c = cur_c+1;
    while(next_r >= 0 && next_c < n){
        if(chess[next_r][next_c]) return false;
        next_r -= 1; next_c += 1;
    }

    return true;
}

void solve(int cur_line){
    if(cur_line == n){
        res += 1;
        return;
    }
    for(int i=0;i<n;i++){
        if(possible(cur_line,i)){
            chess[cur_line][i] = true;
            solve(cur_line+1);
            chess[cur_line][i] = false;
        }
    }
}

int main(){
    int tcase;
    cin >> tcase;
    while(tcase > 0){
        cin >> n;
        solve(0);
        cout << res << '\n';
        res = 0;
        tcase -= 1;
    }

    return 0;
}