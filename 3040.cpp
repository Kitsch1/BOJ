#include <iostream>
#include <vector>
using namespace std;

bool found = false;
vector<int> dwarf(9);
vector<int> selected;

void solve(int start,int all_sum){
    int size = selected.size();
    if(size == 7){
        if(all_sum == 100){
            for(int i=0;i<7;i++){
                cout << selected[i] << '\n';
            }
        }
        return;
    }
    for(int i=start;i<9;i++){
        selected.push_back(dwarf[i]);
        solve(i+1,all_sum+dwarf[i]);
        selected.pop_back();
    }
}

int main(){
    for(int i=0;i<9;i++){
        cin >> dwarf[i];
    }
    solve(0,0);

    return 0;
}