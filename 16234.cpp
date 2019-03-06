#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int n,lower,higher;
int nations[50][50];
bool visited[50][50];
vector<pair<int,int>> changed;
int popul = 0;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

int dfs(int r_cur,int c_cur){
    // check the number of opened nations
    int v_num = 1;
    visited[r_cur][c_cur] = true;
    changed.push_back({r_cur,c_cur});
    popul += nations[r_cur][c_cur];
    for(int i=0;i<4;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next < 0 || r_next >= n || c_next < 0 || c_next >= n) continue;
        int diff = nations[r_cur][c_cur] - nations[r_next][c_next];
        if(diff < 0) diff = -diff;
        if(!visited[r_next][c_next] && diff >= lower && diff <= higher){
            v_num += dfs(r_next,c_next);
        } // if not opened yet and difference of population is in the range
    }
    return v_num;
}

int solve(){
    int ans = 0;
    while(1){
        bool move_flag = false;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(visited[r][c]) continue;
                int v_num = dfs(r,c);
                if(v_num == 1){
                    visited[r][c] = false;
                } // it means no border is opened.
                else{
                    if(!move_flag){
                        move_flag = true; ans += 1;
                    } // count must increased only one time in one loop
                    int size = changed.size();
                    int p_avg = popul / size; // calculate the average of the populations of opened nations
                    for(int i=0;i<size;i++){
                        nations[changed[i].first][changed[i].second] = p_avg;
                    } // initialize
                }
                changed.clear(); // clear the position of nation vector
                popul = 0;
            }
        }
        if(!move_flag) break;
        memset(visited,false,sizeof(visited));
    }
    return ans;
}

int main(){
    scanf("%d %d %d",&n,&lower,&higher);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&nations[r][c]);
        }
    }
    printf("%d\n",solve());

    return 0;
}