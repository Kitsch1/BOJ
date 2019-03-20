#include <cstdio>
#include <vector>
using namespace std;

int abil[21][21];
int n;
int ans = 987654321;
vector<int> team_start,team_link;

void solve(int m_idx){
    // if all members are distributed
    if(m_idx > n){
        int start_size = team_start.size();
        int link_size = team_link.size();
        if(start_size == 0 || link_size == 0) return;
        
        int start_abil = 0, link_abil = 0;
        for(int r=0;r<start_size;r++){
            int member = team_start[r];
            for(int c=0;c<start_size;c++){
                start_abil += abil[member][team_start[c]];
            }
        }
        for(int r=0;r<link_size;r++){
            int member = team_link[r];
            for(int c=0;c<link_size;c++){
                link_abil += abil[member][team_link[c]];
            }
        }
        int diff = start_abil - link_abil;
        if(diff < 0) diff = -diff;
        if(ans > diff) ans = diff;
        return;
    }
    // go to team start
    team_start.push_back(m_idx);
    solve(m_idx+1);
    team_start.pop_back();
    // go to team link
    team_link.push_back(m_idx);
    solve(m_idx+1);
    team_link.pop_back();
}

int main(){
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            scanf("%d",&abil[r][c]);
        }
    }
    solve(1);
    printf("%d\n",ans);

    return 0;
}