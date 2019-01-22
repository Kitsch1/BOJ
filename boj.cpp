#include <cstdio>
#include <deque>
#include <utility>
using namespace std;

int m,n;
char maze[100][100];
bool visited[100][100];

const int way_n[4] = {0,0,1,-1};
const int way_m[4] = {1,-1,0,0};

void bfs(){
    deque<pair<int,pair<int,int>>> dq;
    dq.push_back(make_pair(0,make_pair(0,0)));
    visited[0][0] = true;

    while(!dq.empty()){
        int broken = dq.front().first;
        int cur_n = dq.front().second.first;
        int cur_m = dq.front().second.second;
        dq.pop_front();
        
        if(cur_n == n-1 && cur_m == m-1){
            printf("%d\n",broken);
            break;
        }
        for(int i=0;i<4;i++){
            int next_n = cur_n + way_n[i];
            int next_m = cur_m + way_m[i];
            if(next_n >= 0 && next_n < n && next_m >= 0 && next_m < m){
                if(maze[next_n][next_m] == '0' && !visited[next_n][next_m]){
                    visited[next_n][next_m] = true;
                    dq.push_front(make_pair(broken,make_pair(next_n,next_m)));
                }
                else if(maze[next_n][next_m] == '1' && !visited[next_n][next_m]){
                    visited[next_n][next_m] = true;
                    dq.push_back(make_pair(broken+1,make_pair(next_n,next_m)));
                }
            }
        }
    }
}

int main(){
    char input[104];
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%s",input);
        for(int j=0;j<m;j++){
            maze[i][j] = input[j];
        }
    }
    bfs();

    return 0;
}