#include <iostream>
#include <string>
using namespace std;

bool check(string &car_num){
    bool flag = true;
    for(int i=0;i<8;i++){
        if(i == 4){
            if(car_num[i] >= 'A' && car_num[i] <= 'Z') continue;
            else{
                flag = false; break;
            }   
        }
        if(car_num[i] >= '1' && car_num[i] <= '9') continue;
        else{
            flag = false; break;
        }
    }
    if(car_num[0] != car_num[1]) flag = false;
    return flag;
}

int main(){
    int n;
    cin >> n;
    string car_num;
    for(int i=0;i<n;i++){
        cin >> car_num;
        if(check(car_num)) cout << car_num << '\n';
    }

    return 0;
}