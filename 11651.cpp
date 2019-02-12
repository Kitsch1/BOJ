#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> pos;
    for(int r=0;r<n;r++){
        int x,y;
        scanf("%d %d",&x,&y);
        pos.push_back(make_pair(y,x));
    }
    sort(pos.begin(),pos.end());
    for(int r=0;r<n;r++){
        printf("%d %d\n",pos[r].second,pos[r].first);
    }

    return 0;
}