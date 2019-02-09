#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<string> created_num;
int board[5][5];
const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void solve(string &cur_num,int r,int c){
    if(r < 0 || r >= 5 || c < 0 || c >= 5) return;
    int size = cur_num.size();
    if(size == 6){
        created_num.push_back(cur_num);
        return;
    }
    for(int i=0;i<4;i++){
        int r_next = r + r_way[i];
        int c_next = c + c_way[i];
        cur_num.push_back(board[r_next][c_next]+'0');
        solve(cur_num,r_next,c_next);
        cur_num.pop_back();
    }
}

int main(){
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            scanf("%d",&board[r][c]);
        }
    }
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            string cur_num;
            cur_num.push_back(board[r][c] + '0');
            solve(cur_num,r,c);
        }
    }
    sort(created_num.begin(),created_num.end());
    int size = created_num.size();
    int res = 1;
    for(int i=1;i<size;i++){
        if(created_num[i-1].compare(created_num[i]) != 0){
            res += 1;
        }
    }
    printf("%d\n",res);

    return 0;
}