
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, res = 0;
    cin >> n;

    for(int i=1;i<=n;i++){
        string cur = to_string(i);
        int size = cur.size();

        if(size == 1) res += 1;
        else{
            int seq = cur.at(1) - cur.at(0);
            bool flag = true;
            for(int j=1;j<size-1;j++){
                int cur_seq = cur.at(j+1) - cur.at(j);
                if(cur_seq != seq){
                    flag = false; break;
                }
            }
            if(flag){
                res += 1;
            }
        }
    }
    cout << res <<'\n';

    return 0;
}