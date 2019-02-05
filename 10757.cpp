#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    string n1,n2;
    deque<char> res;
    cin >> n1 >> n2;

    int s1 = n1.size() - 1;
    int s2 = n2.size() - 1;
    bool carry = false;
    while(s1 >= 0 && s2 >= 0){
        int cur = (n1[s1] - '0') + (n2[s2] - '0');
        if(carry) cur += 1;
        if(cur >= 10){
            cur -= 10; carry = true;
        }
        else{
            carry = false;
        }
        res.push_front(cur+'0');
        s1 -= 1;
        s2 -= 1;
    }
    while(s1 >= 0){
        int cur = n1[s1] - '0';
        if(carry) cur += 1;
        if(cur >= 10){
            cur -= 10; carry = true;
        }
        else{
            carry = false;
        }
        res.push_front(cur + '0');
        s1 -= 1;
    }
    while(s2 >= 0){
        int cur = n2[s2] - '0';
        if(carry) cur += 1;
        if(cur >= 10){
            cur -= 10; carry = true;
        }
        else{
            carry = false;
        }
        res.push_front(cur + '0');
        s2 -= 1;
    }
    if(carry) res.push_front('1');
    int size = res.size();
    for(int i=0;i<size;i++){
        cout << res[i];
    }
    cout << '\n';

    return 0;
}