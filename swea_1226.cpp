#include <cstdio>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

char maze[16][16];
bool visited[16][16];
int r_start,c_start,r_end,c_end;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

int bfs(){
    queue<pair<int,int>> q;
    visited[r_start][c_start] = true;
    q.push(make_pair(r_start,c_start));

    while(!q.empty()){
        int r_cur = q.front().first;
        int c_cur = q.front().second;
        q.pop();
        if(r_cur == r_end && c_cur == c_end){
            return 1;
        }
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < 16 && c_next >= 0 && c_next < 16){
                if(!visited[r_next][c_next] && maze[r_next][c_next] != '1'){
                    visited[r_next][c_next] = true;
                    q.push(make_pair(r_next,c_next));
                }
            }
        }
    }
    return 0;
}

int main(){
    for(int i=1;i<=10;i++){
        int tcase;
        char input[20];
        scanf("%d",&tcase);
        for(int r=0;r<16;r++){
            scanf("%s",input);
            for(int c=0;c<16;c++){
                maze[r][c] = input[c];
                if(maze[r][c] == '2'){
                    r_start = r; c_start = c;
                }
                if(maze[r][c] == '3'){
                    r_end = r; c_end = c;
                }
            }
        }
        printf("#%d %d\n",tcase,bfs());
        memset(visited,false,sizeof(bool)*16*16);
    }

    return 0;
}