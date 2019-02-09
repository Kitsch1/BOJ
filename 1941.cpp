#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

char classroom[5][5];
bool st_selected[25];
vector<pair<int,int>> students;
vector<pair<int,int>> seven_girls;
int res = 0;
int solve_cnt = 0;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void dfs(int st_map[5][5],bool visited[5][5],int r,int c){
    visited[r][c] = true;
    for(int i=0;i<4;i++){
        int r_next = r + r_way[i];
        int c_next = c + c_way[i];
        if(r_next >= 0 && r_next < 5 && c_next >= 0 && c_next < 5){
            if(!visited[r_next][c_next] && st_map[r_next][c_next] == 1){
                dfs(st_map,visited,r_next,c_next);
            }
        }
    }
}

bool check_girls(){
    int size = seven_girls.size();
    int dasom = 0, doyeon = 0;
    for(int i=0;i<size;i++){
        int r = seven_girls[i].first;
        int c = seven_girls[i].second;
        if(classroom[r][c] == 'S'){
            dasom += 1;
        }
        else{
            doyeon += 1;
        }
    }
    if(dasom >= 4){
        int st_map[5][5];
        bool visited[5][5];
        memset(st_map,0,sizeof(st_map));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<size;i++){
            int r = seven_girls[i].first;
            int c = seven_girls[i].second;
            st_map[r][c] = 1;
        }
        dfs(st_map,visited,seven_girls[0].first,seven_girls[0].second);
        int v_num = 0;
        for(int r=0;r<5;r++){
            for(int c=0;c<5;c++){
                if(visited[r][c]){
                    v_num += 1;
                }
            }
        }
        if(v_num == 7) return true;
        else return false;
    }
    else{
        return false;
    }
}

void solve(){
    int size = seven_girls.size();
    if(size == 7){
        solve_cnt += 1;
        if(check_girls()) res += 1;
        return;
    }
    int first_idx = -1;
    for(int r=24;r>=0;r--){
        if(st_selected[r]){
            first_idx = r + 1; break;
        }
    }
    if(first_idx == -1) first_idx = 0;
    for(int r=first_idx;r<25;r++){
        st_selected[r] = true;
        seven_girls.push_back(students[r]);
        solve();
        st_selected[r] = false;
        seven_girls.pop_back();
    }
}

int main(){
    char input[8];
    for(int r=0;r<5;r++){
        scanf("%s",input);
        for(int c=0;c<5;c++){
            classroom[r][c] = input[c];
            students.push_back(make_pair(r,c));
        }
    }
    solve();
    printf("%d\n",res);

    return 0;
}