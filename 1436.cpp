#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n,cnt = 1;
    cin >> n;
    if(n == 1){
        cout << "666\n";
    }
    else{
        for(int i=1666;i<10000000;i++){
            string cur_str = to_string(i);
            if(cur_str.find("666") != string::npos){
                cnt += 1;
                if(cnt == n){
                    cout << i << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}