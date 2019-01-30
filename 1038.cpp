#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dec_num;

void create_dec(string &cur_dec,int need_size){
    int size = cur_dec.size();
    if(size == need_size){
        dec_num.push_back(stoll(cur_dec));
        return;
    }
    int last_num = cur_dec[size-1] - '0';
    for(int i=0;i<last_num;i++){
        cur_dec.push_back(i+'0');
        create_dec(cur_dec,need_size);
        cur_dec.pop_back();
    }
}

int main(){
    int n,size;
    cin >> n;
    dec_num.push_back(0);
    for(int i=1;i<10;i++){
        for(int j=1;j<=9;j++){
            string start = to_string(j);
            create_dec(start,i);
        }
    }
    sort(dec_num.begin(),dec_num.end());
    dec_num.push_back(9876543210);
    size = dec_num.size();
    if(n >= size){
        cout << "-1\n";
    }
    else{
        cout << dec_num[n] << '\n';
    }

    return 0;
}