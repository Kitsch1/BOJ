#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int blocks[4][3][2] = {
     {{0,0},{0,1},{1,0}}, {{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,-1}},{{0,0},{1,0},{1,1}} };

int res = 0;

void cover_board(int h,int w,vector<vector<char>> &board,int need_to_cover){
    if(need_to_cover == 0){
        res += 1;
        return;
    }
    int cur_h = -1, cur_w = -1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j] == '.'){
                cur_h = i; cur_w = j;
                break;
            }
        }
        if(cur_h != -1){
            break;
        }
    }
    for(int i=0;i<4;i++){
        bool flag = true;
        for(int j=0;j<3;j++){
            int next_h = cur_h + blocks[i][j][0];
            int next_w = cur_w + blocks[i][j][1];
            if(next_h >= 0 && next_h < h && next_w >= 0 && next_w < w){
                if(board[next_h][next_w] == '#'){
                    flag = false; break;
                }
            }
            else{
                flag = false; break;
            }
        }
        if(flag){
            board[cur_h + blocks[i][0][0]][cur_w + blocks[i][0][1]] = '#';
            board[cur_h + blocks[i][1][0]][cur_w + blocks[i][1][1]] = '#';
            board[cur_h + blocks[i][2][0]][cur_w + blocks[i][2][1]] = '#';
            need_to_cover -= 3;

            cover_board(h,w,board,need_to_cover);

            board[cur_h + blocks[i][0][0]][cur_w + blocks[i][0][1]] = '.';
            board[cur_h + blocks[i][1][0]][cur_w + blocks[i][1][1]] = '.';
            board[cur_h + blocks[i][2][0]][cur_w + blocks[i][2][1]] = '.';
            need_to_cover += 3;
        }
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int h,w;
        char input[24];
        int need_to_cover = 0;

        scanf("%d %d",&h,&w);
        vector<vector<char>> board(h);
        for(int i=0;i<h;i++){
            scanf("%s",input);
            for(int j=0;j<w;j++){
                if(input[j] == '.'){
                    need_to_cover += 1;
                }
                board[i].push_back(input[j]);
            }
        }
        if(need_to_cover > 0 && need_to_cover % 3 == 0){
            cover_board(h,w,board,need_to_cover);
        }
        printf("%d\n",res);
        res = 0;
        tcase -= 1;
    }

    return 0;
}