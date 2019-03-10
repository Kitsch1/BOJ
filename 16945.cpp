#include <cstdio>

int magic_first[9];
int all_magic[9];
bool chosen[10];
int ans = 987654321;

bool check(){
    int line_sum = all_magic[0] + all_magic[1] + all_magic[2];
    int cur_sum;
    for(int i=1;i<3;i++){
        cur_sum = all_magic[i*3] + all_magic[i*3+1] + all_magic[i*3+2];
        if(cur_sum != line_sum) return false;
    }
    for(int i=0;i<3;i++){
        cur_sum = all_magic[i] + all_magic[i+3] + all_magic[i+6];
        if(cur_sum != line_sum) return false;
    }
    cur_sum = all_magic[0] + all_magic[4] + all_magic[8];
    if(cur_sum != line_sum) return false;
    cur_sum = all_magic[2] + all_magic[4] + all_magic[6];
    if(cur_sum != line_sum) return false;

    return true;
}

void solve(int idx){
    if(idx == 9){
        if(check()){
            int cur_ans = 0;
            for(int i=0;i<9;i++){
                int diff = magic_first[i] - all_magic[i];
                if(diff < 0) diff = -diff;
                cur_ans += diff;
            }
            if(ans > cur_ans) ans = cur_ans; 
        }
        return;
    }
    for(int i=1;i<=9;i++){
        if(!chosen[i]){
            chosen[i] = true; all_magic[idx] = i;
            solve(idx+1);
            chosen[i] = false; all_magic[idx] = 0;
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        scanf("%d",&magic_first[i]);
    }
    solve(0);
    printf("%d\n",ans);

    return 0;
}