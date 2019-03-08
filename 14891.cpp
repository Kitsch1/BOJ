#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

bool turn_checked[4]; // check if chain is turned
vector<deque<char>> chain(4); // the status of chain

void solve(int idx,int turn_way){
    char cur;
    turn_checked[idx] = true; // checking flag
    if(idx >= 1){
        if(!turn_checked[idx-1] && (chain[idx][6] != chain[idx-1][2])){
            solve(idx-1,turn_way*-1);
        } // if current chain's right-sided chain has different side
    }
    if(idx <= 2){
        if(!turn_checked[idx+1] && (chain[idx][2] != chain[idx+1][6])){
            solve(idx+1,turn_way*-1);
        } // if current chain's left-sided chain has different side
    }
    if(turn_way == 1){
        cur = chain[idx][7];
        chain[idx].pop_back();
        chain[idx].push_front(cur);
    } // clockwise
    else{
        cur = chain[idx][0];
        chain[idx].pop_front();
        chain[idx].push_back(cur);
    } // counterclockwise
}


int main(){
    char input[12];
    int k;
    for(int i=0;i<4;i++){
        scanf("%s",input);
        for(int j=0;j<8;j++){
            chain[i].push_back(input[j]);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int idx,turn_way;
        scanf("%d %d",&idx,&turn_way);
        memset(turn_checked,false,sizeof(turn_checked));
        solve(idx-1,turn_way);
    }
    int ans = 0;
    for(int i=0;i<4;i++){
        if(chain[i][0] == '1'){
            ans += (1<<i); // 'S' score
        }
    }
    printf("%d\n",ans);

    return 0;
}