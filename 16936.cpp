#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lld;

bool cmp(pair<int,lld> &a,pair<int,lld> &b){
    if(a.first > b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    lld elem;
    scanf("%d",&n);
    vector<pair<int,lld>> v;
    for(int i=0;i<n;i++){
        scanf("%lld",&elem);
        int three_num = 0;
        pair<int,lld> p;
        p.second = elem;
        while(!(elem%3)){
            three_num += 1;
            elem /= 3;
        }
        p.first = three_num;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        printf("%lld ",v[i].second);
    }
    printf("\n");

    return 0;
}