#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int house_num,way_num;
int h_start,h_end;
vector<vector<pair<int,int>>> cebu;
bool visited[100001];

bool bfs(int pepero){
    queue<int> q;
    q.push(h_start);
    visited[h_start] = true;
    while(!q.empty()){
        int h_cur = q.front();
        q.pop();
        if(h_cur == h_end) return true;
        for(auto v : cebu[h_cur]){
            int h_next = v.first;
            int h_next_limit = v.second;
            if(!visited[h_next] && h_next_limit >= pepero){
                visited[h_next] = true;
                q.push(h_next);
            }
        }
    }
    return false;
}

int main(){
    int w_low,w_high;
    w_low = 987654321;
    w_high = -1;
    scanf("%d %d",&house_num,&way_num);
    scanf("%d %d",&h_start,&h_end);
    cebu.resize(house_num+1);
    for(int i=0;i<way_num;i++){
        int h1,h2,weight;
        scanf("%d %d %d",&h1,&h2,&weight);
        cebu[h1].push_back({h2,weight});
        cebu[h2].push_back({h1,weight});
        if(w_low > weight) w_low = weight;
        if(w_high < weight) w_high = weight;
    }
    while(w_low <= w_high){
        int w_pepero = (w_low + w_high) / 2;
        if(bfs(w_pepero)){
            w_low = w_pepero + 1;
        }
        else{
            w_high = w_pepero - 1;
        }
        memset(visited,false,sizeof(visited));
    }
    printf("%d\n",w_high);

    return 0;
}