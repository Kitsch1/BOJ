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

int main(){
    int n,m;
    bool selected[8];
    cin >> n >> m;
    
    vector<int> all_numbers(n);
    for(int i=0;i<n;i++){
        cin >> all_numbers[i];
    }
    memset(selected,false,sizeof(bool)*8);
    sort(all_numbers.begin(),all_numbers.end());

    vector<int> v;
    solve(n,m,selected,all_numbers,v);

    return 0;
}