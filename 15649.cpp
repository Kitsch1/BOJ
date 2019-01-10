#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

void solve(int n,int m,bool selected[9],vector<int> &v){
    int size = v.size();
    if(size == m){
        for(int i=0;i<size;i++){
            printf("%d ",v[i]);
        }
        printf("\n");
    }

    for(int i=1;i<=n;i++){
        if(selected[i] == false){
            selected[i] = true;
            v.push_back(i);
            solve(n,m,selected,v);
            v.pop_back();
            selected[i] = false;
        }
    }
}

int main(){
    int n,m;
    bool selected[9];
    scanf("%d %d",&n,&m);
    memset(selected,false,sizeof(bool)*9);

    for(int i=1;i<=n;i++){
        vector<int> numbers;
        selected[i] = true;
        numbers.push_back(i);

        solve(n,m,selected,numbers);

        selected[i] = false;
        numbers.pop_back();
    }

    return 0;
}