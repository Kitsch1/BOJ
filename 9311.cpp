#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<vector<char>> maze;
vector<vector<bool>> visited;
int r_len, c_len;
int r_start,c_start;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

int bfs(){
    queue<pair<int,pair<int,int>>> q;
    visited[r_start][c_start] = true;
    q.push({0,{r_start,c_start}});
    while(!q.empty()){
        int cur_time = q.front().first;
        int r_cur = q.front().second.first;
        int c_cur = q.front().second.second;
        q.pop();
        if(maze[r_cur][c_cur] == 'G'){
            return cur_time;
        }
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(!visited[r_next][c_next] && maze[r_next][c_next] != 'X'){
                    visited[r_next][c_next] = true;
                    q.push({cur_time+1,{r_next,c_next}});
                }
            }
        }
    }

    return -1;
}

int main(){
    int tcase;
    cin >> tcase;
    while(tcase > 0){
        cin >> r_len >> c_len;
        maze.resize(r_len);
        string input_str;
        for(int r=0;r<r_len;r++){
            cin >> input_str;
            for(int c=0;c<c_len;c++){
                maze[r].push_back(input_str[c]);
                if(maze[r][c] == 'S'){
                    r_start = r; c_start = c;
                }
            }
        }
        visited.resize(r_len);
        for(int r=0;r<r_len;r++){
            visited[r].resize(c_len);
        }
        int ans = bfs();
        if(ans == -1) cout << "No Exit\n";
        else cout << "Shortest Path: " << ans << '\n';
        maze.clear();
        visited.clear();
        tcase -= 1;
    }

    return 0;
}