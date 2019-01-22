#include <iostream>
#include <string>
#include <vector>
using namespace std;

string good_p;
int n;

void solve(int cur_len){
    if(cur_len == n){
        cout << good_p << '\n';
        return;
    }
    for(int i=1;i<10;i+=2){
        string cur_str = good_p + to_string(i);
        int cur_num = stoi(cur_str);
        bool flag = true;
        for(int j=3;j*j<=cur_num;j += 2){
            if(cur_num % j == 0){
                flag = false; break;
            }
        }
        if(flag){
            good_p += to_string(i);
            solve(cur_len+1);
            good_p.pop_back();
        }
    }
}

int main(){
    cin >> n;
    good_p = "2"; solve(1);
    good_p = "3"; solve(1);
    good_p = "5"; solve(1);
    good_p = "7"; solve(1);

    return 0;
}