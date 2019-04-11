#include <iostream>
#include <string>
using namespace std;

int ans = -1;
bool selected[10];
string mixed; // mixed a
string a_num; int b_num;

void solve(int cur,int all_len){
    if(cur == all_len){
        int new_num = stol(mixed);
        if(new_num > b_num) return;
        if(ans == -1 || ans < new_num) ans = new_num;
        return;
    }
    for(int i=0;i<all_len;i++){
        if(!selected[i]){
            selected[i] = true; mixed.push_back(a_num[i]);
            solve(cur+1,all_len);
            selected[i] = false; mixed.pop_back();
        }
    }
}

int main(){
    cin >> a_num >> b_num;
    int len = a_num.size();
    for(int i=0;i<len;i++){
        if(a_num[i] != '0'){
            selected[i] = true; mixed.push_back(a_num[i]);
            solve(1,len);
            selected[i] = false; mixed.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}