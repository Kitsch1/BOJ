#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int clock_connected[10][5] = { {0,1,2,-1,-1},{3,7,9,11,-1},
                               {4,10,14,15,-1},{0,4,5,6,7},
                               {6,7,8,10,12},{0,2,14,15,-1},
                               {3,14,15,-1,-1},{4,5,7,14,15},
                               {1,2,3,4,5},{3,4,5,9,13} };
                            
int clock_state[16];
vector<int> pushed_num;
int res = -1;

void check_state(){
    int cur_res = 0;
    int cur_state[16];
    for(int i=0;i<16;i++){
        cur_state[i] = clock_state[i];
    }
    for(int i=0;i<10;i++){
        int push_switch = pushed_num[i];
        cur_res += push_switch;
        for(int j=0;j<5;j++){
            int connected = clock_connected[i][j];
            if(connected == -1){
                break;
            }
            cur_state[connected] += (push_switch * 3);
            if(cur_state[connected] > 12){
                cur_state[connected] -= 12;
            }
        }
    }
    bool flag = true;
    for(int i=0;i<16;i++){
        if(cur_state[i] != 12){
            flag = false; break;
        }
    }
    if(flag){
        if(res == -1 || res > cur_res){
            res = cur_res;
        }
    }
}

void all_push_case(){
    int size = pushed_num.size();
    if(size == 10){
        check_state();
        return;
    }
    for(int i=0;i<4;i++){
        pushed_num.push_back(i);
        all_push_case();
        pushed_num.pop_back();
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);

    while(tcase > 0){
        for(int i=0;i<16;i++){
            scanf("%d",&clock_state[i]);
        }
        all_push_case();
        printf("%d\n",res);
        //memset(clock_state,0,sizeof(int)*16);
        res = -1;
        tcase -= 1;
    }

    return 0;
}