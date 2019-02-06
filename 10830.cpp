#define MOD 1000
#include <iostream>
#include <cstring>
using namespace std;

int n;
long long b;
int res_matrix[5][5], sq_matrix[5][5];

void mult_sq(int m1[5][5],int m2[5][5]){
    int tmp_res[5][5];
    memset(tmp_res,0,sizeof(tmp_res));

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            for(int k=0;k<n;k++){
                tmp_res[r][c] = (tmp_res[r][c] + ((m1[r][k] * m2[k][c]) % MOD)) % MOD; 
            }
        }
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            m1[r][c] = tmp_res[r][c];
        }
    }
}

void solve(){
    while(b > 0){
        if(b % 2 == 1){
            mult_sq(res_matrix,sq_matrix);
            b -= 1;
        }
        mult_sq(sq_matrix,sq_matrix);
        b /= 2;
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            cout << res_matrix[r][c] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    cin >> n >> b;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            cin >> sq_matrix[r][c];
        }
    }
    for(int r=0;r<n;r++){
        res_matrix[r][r] = 1;
    }
    solve();

    return 0;
}