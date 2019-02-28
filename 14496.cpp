#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n,r_num;
vector<bool> visited;
vector<vector<int>> rel;

int bfs(int st_letter,int end_letter){
    queue<pair<int,int>> q; // first : letter num, second : letter dist
    visited[st_letter] = true;
    q.push({st_letter,0});
    
    while(!q.empty()){
        int cur_letter = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(cur_letter == end_letter){
            return dist;
        }
        for(auto a : rel[cur_letter]){
            if(!visited[a]){
                visited[a] = true;
                q.push({a,dist+1});
            }
        }
    }

    return -1;
}

int main(){
    int st_letter,end_letter;
    scanf("%d %d",&st_letter,&end_letter);
    scanf("%d %d",&n,&r_num);
    rel.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<r_num;i++){
        int c1,c2;
        scanf("%d %d",&c1,&c2);
        rel[c1].push_back(c2);
        rel[c2].push_back(c1);
    }
    printf("%d\n",bfs(st_letter,end_letter));

    return 0;
}