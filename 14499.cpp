#include <cstdio>
using namespace std;

int n_len,m_len,x_start,y_start,order;
int dice[7];
int board[20][20];

const int r_way[5] = {0,0,0,-1,1};
const int c_way[5] = {0,1,-1,0,0};

int main(){
    scanf("%d %d %d %d %d",&n_len,&m_len,&x_start,&y_start,&order);
    for(int r=0;r<n_len;r++){
        for(int c=0;c<m_len;c++){
            scanf("%d",&board[r][c]);
        }
    }
    int r_cur = x_start;
    int c_cur = y_start;
    for(int i=0;i<order;i++){
        int o_num;
        scanf("%d",&o_num);
        int r_next = r_cur + r_way[o_num];
        int c_next = c_cur + c_way[o_num];
        if(r_next < 0 || r_next >= n_len || c_next < 0 || c_next >= m_len){
            continue;
        }
        int next_dice[7] = {0,};
        if(o_num == 1){
            next_dice[1] = dice[4]; next_dice[2] = dice[2];
            next_dice[3] = dice[1]; next_dice[4] = dice[6];
            next_dice[5] = dice[5]; next_dice[6] = dice[3];
        }
        else if(o_num == 2){
            next_dice[1] = dice[3]; next_dice[2] = dice[2];
            next_dice[3] = dice[6]; next_dice[4] = dice[1];
            next_dice[5] = dice[5]; next_dice[6] = dice[4];
        }
        else if(o_num == 3){
            next_dice[1] = dice[5]; next_dice[2] = dice[1];
            next_dice[3] = dice[3]; next_dice[4] = dice[4];
            next_dice[5] = dice[6]; next_dice[6] = dice[2];
        }
        else if(o_num == 4){
            next_dice[1] = dice[2]; next_dice[2] = dice[6];
            next_dice[3] = dice[3]; next_dice[4] = dice[4];
            next_dice[5] = dice[1]; next_dice[6] = dice[5];
        }
        if(board[r_next][c_next]){
            next_dice[6] = board[r_next][c_next];
            board[r_next][c_next] = 0;
        }
        else{
            board[r_next][c_next] = next_dice[6];
        }
        printf("%d\n",next_dice[1]);
        for(int r=0;r<7;r++){
            dice[r] = next_dice[r];
        }
        r_cur = r_next; c_cur = c_next;
    }

    return 0;
}