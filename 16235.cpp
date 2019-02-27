#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <list>
using namespace std;

// index starts from 1 to N
int yangboon[11][11];
int added_boon[11][11];
list<pair<int,pair<int,int>>> namu;
int n,m,k;

const int r_way[8] = {0,0,1,-1,1,1,-1,-1};
const int c_way[8] = {1,-1,0,0,1,-1,1,-1};

void spring(){
    for(auto it=namu.begin();it!=namu.end();it++){
        int cur_age = it->first;
        int r_cur = it->second.first;
        int c_cur = it->second.second;
        if(yangboon[r_cur][c_cur] >= cur_age){
            yangboon[r_cur][c_cur] -= cur_age;
            it->first += 1;
        }
        else{
            it->first = -cur_age;
        }
    }
}

void summer(){
    for(auto it=namu.begin();it!=namu.end();){
        int cur_age = it->first;
        int r_cur = it->second.first;
        int c_cur = it->second.second;
        if(cur_age > 0){
            it++;
        }
        else{
            yangboon[r_cur][c_cur] += (cur_age * -1) / 2;
            it = namu.erase(it);
        }
    }
}

void autumn(){
    for(auto it=namu.begin();it!=namu.end();++it){
        int cur_age = it->first;
        int r_cur = it->second.first;
        int c_cur = it->second.second;
        if(cur_age % 5) continue;
        for(int j=0;j<8;j++){
            int r_next = r_cur + r_way[j];
            int c_next = c_cur + c_way[j];
            if(r_next >= 1 && r_next <= n && c_next >= 1 && c_next <= n){
                namu.push_front({1,{r_next,c_next}});
            }
        }
    }
}

void winter(){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            yangboon[r][c] += added_boon[r][c];
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            scanf("%d",&added_boon[r][c]);
        }
    }
    for(int i=0;i<m;i++){
        int p_r,p_c,age;
        scanf("%d %d %d",&p_r,&p_c,&age);
        namu.push_back({age,{p_r,p_c}});
    }
    //sort(namu.begin(),namu.end());
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            yangboon[r][c] = 5;
        }
    }
    for(int i=0;i<k;i++){
        spring();
        summer();
        autumn();
        winter();
    }
    printf("%d\n",namu.size());

    return 0;
}