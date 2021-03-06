#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> all_seq;

void solve(int n,int m,vector<int> &all_numbers,vector<int> &v){
    int size = v.size();
    if(size == m){
        all_seq.push_back(v);
        return;
    }
    int start;
    if(size == 0){
        start = 0;
    }
    else{
        int last_num = v[size-1];
        for(int i=0;i<n;i++){
            if(last_num == all_numbers[i]){
                start = i;
                break;
            }
        }
    }
    for(int i=start;i<n;i++){
        v.push_back(all_numbers[i]);
        solve(n,m,all_numbers,v);
        v.pop_back();
    }
}

void check_seq(int m){
    int size = all_seq.size();
    for(int j=0;j<m;j++){
        printf("%d ",all_seq[0][j]);
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
    
    scanf("%d %d",&n,&m);
    vector<int> all_numbers(n),v;
    for(int i=0;i<n;i++){
        scanf("%d",&all_numbers[i]);
    }
    sort(all_numbers.begin(),all_numbers.end());
    solve(n,m,all_numbers,v);
    sort(all_seq.begin(),all_seq.end());
    check_seq(m);

    return 0;
}