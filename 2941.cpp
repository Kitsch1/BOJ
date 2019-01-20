#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char words[104];
    int idx = 0,res = 0,len;
    cin >> words;

    len = strlen(words);
    while(idx < len){
        char cur_c = words[idx],next_c;
        if(idx == len - 1){
            res += 1; idx += 1;
            continue;
        }
        next_c = words[idx+1];
        if(cur_c == 'c' && (next_c == '=' || next_c == '-')){
            res += 1; idx += 2;
        }
        else if(cur_c == 'd' && next_c == '-'){
            res += 1; idx += 2;
        }
        else if(cur_c == 'd' && next_c == 'z' && idx + 2 < len && words[idx+2] == '='){
            res += 1; idx += 3;
        }
        else if((cur_c == 'l' || cur_c == 'n') && next_c == 'j'){
            res += 1; idx += 2;
        }
        else if((cur_c == 's' || cur_c == 'z') && next_c == '='){
            res += 1; idx += 2;
        }
        else{
            res += 1; idx += 1;
        }
    }
    cout << res << '\n';

    return 0;
}