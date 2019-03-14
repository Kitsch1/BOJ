#include <iostream>
#include <string>
using namespace std;

int main(){
    string car_num;
    int ans,c_len;
    cin >> car_num;
    
    c_len = car_num.size();
    if(car_num[0] == 'c') ans = 26;
    else ans = 10;

    for(int i=1;i<c_len;i++){
        if(car_num[i] == 'c'){
            if(car_num[i-1] == 'c') ans *= 25;
            else ans *= 26;
        }
        else{
            if(car_num[i-1] == 'd') ans *= 9;
            else ans *= 10;
        }
    }
    cout << ans << '\n';

    return 0;
}