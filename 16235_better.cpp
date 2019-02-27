#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int boon[11][11];
int added[11][11];
int dead_plant[11][11];
vector<int> namu[11][11];
int n,m,k;

const int r_way[8] = {0,0,1,-1,1,1,-1,-1};
const int c_way[8] = {1,-1,0,0,1,-1,1,-1};

void spring(){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            int size = namu[r][c].size();
            if(!size) continue;
            sort(namu[r][c].begin(),namu[r][c].end());
            for(int j=0;j<namu[r][c].size();j++){
                if(boon[r][c] >= namu[r][c][j]){
                    boon[r][c] -= namu[r][c][j];
                    namu[r][c][j] += 1;
                }
                else{
                    dead_plant[r][c] += (namu[r][c][j] / 2);
                    namu[r][c].erase(namu[r][c].begin()+j);
                    j -= 1;
                }
            }
        }
    }
}

void summer(){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            boon[r][c] += dead_plant[r][c];
        }
    }
    memset(dead_plant,0,sizeof(dead_plant));
}

void autumn(){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            int size = namu[r][c].size();
            if(!size) continue;
            for(int j=0;j<size;j++){
                if(namu[r][c][j] % 5) continue;
                for(int l=0;l<8;l++){
                    int r_next = r + r_way[l];
                    int c_next = c + c_way[l];
                    if(r_next >= 1 && r_next <= n && c_next >= 1 && c_next <= n){
                        namu[r_next][c_next].push_back(1);
                    }
                }
            }
        }
    }
}

void winter(){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            boon[r][c] += added[r][c];
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&added[i][j]);
        }
    }
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            boon[r][c] = 5;
        }
    }
    for(int i=0;i<m;i++){
        int r,c,age;
        scanf("%d %d %d",&r,&c,&age);
        namu[r][c].push_back(age);
    }
    for(int i=0;i<k;i++){
        spring();
        summer();
        autumn();
        winter();
    }
    int ans = 0;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            ans += namu[r][c].size();
        }
    }
    printf("%d\n",ans);

    return 0;
}