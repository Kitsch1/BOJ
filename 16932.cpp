#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int r_len,c_len;
int field[1000][1000], all_group[1000][1000];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

int dfs_group(int r,int c,int g_num){
    int g_size = 1;
    all_group[r][c] = g_num;
    for(int i=0;i<4;i++){
        int r_next = r + r_way[i];
        int c_next = c + c_way[i];
        if(r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
        if(field[r_next][c_next] && all_group[r_next][c_next] == -1){
            g_size += dfs_group(r_next,c_next,g_num);
        }
    }
    return g_size;
}

int solve(){
    vector<int> group_vec;
    int g_idx = 0, g_size;
    
    // step 1 : make group
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(field[r][c] && all_group[r][c] == -1){
                g_size = dfs_group(r,c,g_idx);
                group_vec.push_back(g_size);
                g_idx += 1;
            }
        }
    }
    int ans = -1;
    // step 2 : check the increasing group
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(!field[r][c]){
                vector<int> near_idx;
                int near_size = 0;
                for(int i=0;i<4;i++){
                    int r_next = r + r_way[i];
                    int c_next = c + c_way[i];
                    if(r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
                    if(all_group[r_next][c_next] != -1){
                        near_idx.push_back(all_group[r_next][c_next]);
                    }
                }
                if(near_idx.empty()) continue;
                sort(near_idx.begin(),near_idx.end());
                near_idx.erase(unique(near_idx.begin(),near_idx.end()),near_idx.end());
                for(auto a : near_idx){
                    near_size += group_vec[a];
                }
                near_size += 1;
                if(ans < near_size) ans = near_size;
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            scanf("%d",&field[r][c]);
        }
    }
    memset(all_group,-1,sizeof(all_group));
    printf("%d\n",solve());

    return 0;
}