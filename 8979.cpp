#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct country{
    int c_num;
    int gold;
    int silver;
    int bronze;
}country;

bool cmp(country a,country b){
    if(a.gold > b.gold){
        return true;
    }
    else if(a.gold == b.gold && a.silver > b.silver){
        return true;
    }
    else if(a.gold == b.gold && a.silver == b.silver && a.bronze > b.bronze){
        return true;
    }
    return false;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<country> c_vec(n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&c_vec[i].c_num,&c_vec[i].gold,&c_vec[i].silver,&c_vec[i].bronze);
    }
    sort(c_vec.begin(),c_vec.end(),cmp);
    int ranking = 1, samesame = 1;
    if(c_vec[0].c_num == k) printf("1\n");
    else{
        for(int r=1;r<n;r++){
            if(c_vec[r-1].gold == c_vec[r].gold && c_vec[r-1].silver == c_vec[r].silver && 
            c_vec[r-1].bronze == c_vec[r].bronze){
                samesame += 1;
            }
            else{
                if(samesame > 0){
                    ranking += samesame;
                    samesame = 1;
                }
                else{
                    ranking += 1;
                }
            }
            if(c_vec[r].c_num == k){
                printf("%d\n",ranking); break;
            } 
        }
    }

    return 0;
}