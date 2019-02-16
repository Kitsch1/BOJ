#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool alpha[26];

int main(){
    int n,ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        string cur_str;
        cin >> cur_str;

        bool flag = true;
        int size = cur_str.size();
        char letter = cur_str[0];
        alpha[letter-'a'] = true;
        for(int j=1;j<size;j++){
            if(letter != cur_str[j]){
                if(alpha[cur_str[j]-'a']){
                    flag = false; break;
                }
                else{
                    letter = cur_str[j];
                    alpha[letter-'a'] = true;   
                }
            }
        }
        if(flag) ans += 1;
        memset(alpha,false,sizeof(alpha));
    }
    cout << ans << '\n';

    return 0;
}