#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int res = 0;

void match_relation(vector<vector<int>> &relation,int n,bool matched[10],int pair_num){
    if(pair_num == (n/2)){
        res += 1;
        return;
    }

    int start = -1;
    for(int i=0;i<n;i++){
        if(matched[i] == false){
            start = i;
            break;
        }
    }

    int size = relation[start].size();
    for(int i=0;i<size;i++){
        if(matched[relation[start][i]] == false){
            matched[start] = matched[relation[start][i]] = true;
            pair_num += 1;
            match_relation(relation,n,matched,pair_num);
            pair_num -= 1;
            matched[start] = matched[relation[start][i]] = false;
        }
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);

    while(tcase > 0){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<vector<int>> relation(n);

        for(int i=0;i<m;i++){
            int r1,r2;
            scanf("%d %d",&r1,&r2);

            relation[r1].push_back(r2);
            relation[r2].push_back(r1);
        }
        bool matched[10];
        memset(matched,false,sizeof(bool)*10);
        //matching_friends(relation,n,matched);
        match_relation(relation,n,matched,0);
        printf("%d\n",res);
        
        res = 0;
        tcase -= 1;
    }

    return 0;
}