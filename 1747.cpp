#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool eratos[1100001];
vector<int> palin_prime;

int main(){
    for(int i=4;i<=1100000;i+=2){
        eratos[i] = true;
    }
    for(int i=3;i*i<=1100000;i+=2){
        for(int j=i*2;j<=1100000;j+=i){
            eratos[j] = true;
        }
    }
    for(int i=2;i<=1100000;i++){
        if(!eratos[i]){
            string num = to_string(i);
            int size = num.size();
            int half = size/2;
            bool flag = true;
            for(int j=0;j<half;j++){
                if(num[j] != num[size-j-1]){
                    flag = false; break;
                }
            }
            if(flag) palin_prime.push_back(i);
        }
    }
    int n;
    cin >> n;
    auto it = lower_bound(palin_prime.begin(),palin_prime.end(),n);
    cout << *it << '\n';

    return 0;
}