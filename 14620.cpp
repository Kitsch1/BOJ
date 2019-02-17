#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int flower[10][10];
bool blossom[10][10];
vector<pair<int,int>> possible;
vector<pair<int,int>> selected;
int ans = -1;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

bool check_possible(){
    memset(blossom,false,sizeof(blossom));
    for(int i=0;i<3;i++){
        int r_cur = selected[i].first;
        int c_cur = selected[i].second;
        blossom[r_cur][c_cur] = true;
        for(int j=0;j<4;j++){
            int r_next = r_cur + r_way[j];
            int c_next = c_cur + c_way[j];
            if(blossom[r_next][c_next]) return false;
            else blossom[r_next][c_next] = true;
        }
    }
    return true;
}

void solve(int n){
    int cur_ans = 0;
    if(check_possible()){
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(blossom[r][c]) cur_ans += flower[r][c];
            }
        }
        if(ans == -1 || ans > cur_ans) ans = cur_ans;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&flower[r][c]);
        }
    }
    for(int r=1;r<n-1;r++){
        for(int c=1;c<n-1;c++){
            possible.push_back(make_pair(r,c));
        }
    }
    int p_size = (n-2)*(n-2);
    int cnt = 1;
    for(int i=0;i<p_size-2;i++){
        selected.push_back(possible[i]);
        for(int j=i+1;j<p_size-1;j++){
            selected.push_back(possible[j]);
            for(int k=j+1;k<p_size;k++){
                selected.push_back(possible[k]);
                solve(n);
                selected.pop_back();
            }
            selected.pop_back();
        }
        selected.pop_back();
    }
    printf("%d\n",ans);

    return 0;
}