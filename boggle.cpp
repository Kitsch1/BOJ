#include <iostream>
#include <cstring>
using namespace std;

char cur_word[12];
int dp[5][5][10];
char board[5][5];
int word_len;

const int way_r[8] = {0,0,1,-1,1,1,-1,-1};
const int way_c[8] = {1,-1,0,0,1,-1,1,-1};

int solve(int r_cur,int c_cur,int idx){
    if(idx == word_len) return 1;

    int& ans = dp[r_cur][c_cur][idx];
    if(ans != -1) return ans;
    ans = 0;

    for(int i=0;i<8;i++){
        int r_next = r_cur + way_r[i];
        int c_next = c_cur + way_c[i];

        if(r_next >= 0 && r_next < 5 && c_next >= 0 && c_next < 5){
            if(board[r_next][c_next] == cur_word[idx]){
                ans += solve(r_next,c_next,idx+1);
            }
        }
    }
    return ans;
}

int main(){
    int tcase,num_word;
    char input[8];
    
    cin >> tcase;
    while(tcase > 0){
        for(int i=0;i<5;i++){
            cin >> input;
            for(int j=0;j<5;j++){
                board[i][j] = input[j];
            }
        }
        cin >> num_word;
        memset(dp,-1,sizeof(int)*5*5*10);
        for(int i=0;i<num_word;i++){
            cin >> cur_word;
            word_len = strlen(cur_word);
            int res = 0;

            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    if(cur_word[0] == board[j][k]){
                        res += solve(j,k,1);
                    }
                }
            }
            if(!res){
                cout << cur_word << ' ' << "NO\n";
            }
            else{
                cout << cur_word << ' ' << "YES\n";
            }

            memset(dp,-1,sizeof(int)*5*5*10);
        }

        tcase -= 1;
    }

    return 0;
}