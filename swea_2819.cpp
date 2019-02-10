#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num_board[4][4];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void solve(vector<string> &all_num,string &cur_num,int r,int c){
    int size = cur_num.size();
    if(size == 7){
        all_num.push_back(cur_num);
        return;
    }
    for(int i=0;i<4;i++){
        int r_next = r + r_way[i];
        int c_next = c + c_way[i];
        if(r_next >= 0 && r_next < 4 && c_next >= 0 && c_next < 4){
            cur_num.push_back(num_board[r_next][c_next]+'0');
            solve(all_num,cur_num,r_next,c_next);
            cur_num.pop_back();
        }
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        vector<string> all_num;
        for(int r=0;r<4;r++){
            for(int c=0;c<4;c++){
                scanf("%d",&num_board[r][c]);
            }
        }
        for(int r=0;r<4;r++){
            for(int c=0;c<4;c++){
                string cur_num;
                cur_num.push_back(num_board[r][c] + '0');
                solve(all_num,cur_num,r,c);
            }
        }
        sort(all_num.begin(),all_num.end());
        int res = 1;
        int size = all_num.size();
        for(int i=1;i<size;i++){
            if(all_num[i].compare(all_num[i-1])){
                res += 1;
            }
        }
        printf("#%d %d\n",i,res);
    }

    return 0;
}