#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string cur_pwd;
vector<string> possible;
string alpha; // alphabet list
bool used[15];

void solve(int l,int c){
    int size = cur_pwd.size();
    if(size == l){
        int c_num = 0, v_num = 0;
        for(int i=0;i<size;i++){
            if(cur_pwd[i] == 'a' || cur_pwd[i] == 'e' || cur_pwd[i] == 'o' || cur_pwd[i] == 'i' || cur_pwd[i] == 'u'){
                v_num += 1;
            }
            else{
                c_num += 1;
            }
        }
        if(c_num >= 2 && v_num >= 1){
            possible.push_back(cur_pwd);
        }
        return;
    }
    int first_idx;
    if(size == 0){
        first_idx = -1;
    }
    else{
        char last_letter = cur_pwd[size - 1];
        for(int i=c-1;i>=0;i--){
            if(last_letter == alpha[i]){
                first_idx = i; break;
            }
        }
    }
    for(int i=first_idx+1;i<c;i++){
        cur_pwd.push_back(alpha[i]);
        solve(l,c);
        cur_pwd.pop_back();
    }
}

int main(){
    int l,c;
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char c1;
        cin >> c1;
        alpha.push_back(c1);
    }
    sort(alpha.begin(),alpha.end());
    solve(l,c);
    for(auto a : possible){
        cout << a << '\n';
    }

    return 0;
}