#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void solve(int n,int m,bool selected[8],vector<int> &all_numbers,vector<int> &v){
    int size = v.size();
    if(size == m){
        for(int i=0;i<size;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int last_idx = -1;
    for(int i=n-1;i>=0;i--){
        if(selected[i] == true){
            last_idx = i;
            break;
        }
    }

    for(int i=last_idx+1;i<n;i++){
        if(selected[i] == false){
            selected[i] = true;
            v.push_back(all_numbers[i]);
            solve(n,m,selected,all_numbers,v);
            selected[i] = false;
            v.pop_back();
        }
    }
}

int main(){
    int n,m;
    bool selected[8];
    cin >> n >> m;
    vector<int> all_numbers(n);
    for(int i=0;i<n;i++){
        cin >> all_numbers[i];
    }
    sort(all_numbers.begin(),all_numbers.end());
    memset(selected,false,sizeof(bool)*8);
    vector<int> v;
    solve(n,m,selected,all_numbers,v);

    return 0;
}