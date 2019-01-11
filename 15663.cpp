#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> all_seq;

void solve(int n,int m,bool selected[8],vector<int> &all_numbers,vector<int> &v){
    int size = v.size();
    if(size == m){
        all_seq.push_back(v);
        return;
    }

    for(int i=0;i<n;i++){
        if(selected[i] == false){
            selected[i] = true;
            v.push_back(all_numbers[i]);
            solve(n,m,selected,all_numbers,v);
            selected[i] = false;
            v.pop_back();
        }
    }
}

void find_case(int m){
    int size = all_seq.size();
    
    for(int i=0;i<m;i++){
        printf("%d ",all_seq[0][i]);
    }
    printf("\n");

    for(int i=1;i<size;i++){
        int flag = 0;
        for(int j=0;j<m;j++){
            if(all_seq[i-1][j] == all_seq[i][j]){
                flag += 1;
            }
        }
        if(flag == m){
            continue;
        }
        for(int j=0;j<m;j++){
            printf("%d ",all_seq[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    bool selected[8];
    scanf("%d %d",&n,&m);
    vector<int> all_numbers(n),v;
    for(int i=0;i<n;i++){
        scanf("%d",&all_numbers[i]);
    }
    sort(all_numbers.begin(),all_numbers.end());
    memset(selected,false,sizeof(bool)*8);

    solve(n,m,selected,all_numbers,v);
    sort(all_seq.begin(),all_seq.end());
    find_case(m);

    return 0;
}