#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> all_seq;

void solve(int n,int m,vector<int> &all_numbers,vector<int> &v,bool selected[8]){
    int size = v.size();
    if(size == m){
        all_seq.push_back(v);
        return;
    }

    int cur_start = -1;
    for(int i=n-1;i>=0;i--){
        if(selected[i] == true){
            cur_start = i + 1;
            break;
        }
    }
    if(cur_start == -1){
        cur_start = 0;
    }

    for(int i=cur_start;i<n;i++){
        if(selected[i] == false){
            selected[i] = true; v.push_back(all_numbers[i]);
            solve(n,m,all_numbers,v,selected);
            selected[i] = false; v.pop_back();
        }
    }
}

void check_seq(int m){
    int size = all_seq.size();
    for(int i=0;i<m;i++){
        cout << all_seq[0][i] << ' ';
    }
    cout << '\n';
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
            cout << all_seq[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    int n,m;
    bool selected[8];
    cin >> n >> m;
    vector<int> all_numbers(n),v;
    for(int i=0;i<n;i++){
        cin >> all_numbers[i];
    }
    
    memset(selected,false,sizeof(bool)*8);
    sort(all_numbers.begin(),all_numbers.end());
    solve(n,m,all_numbers,v,selected);
    sort(all_seq.begin(),all_seq.end());
    check_seq(m);

    return 0;
}