#include <iostream>
#include <string>
using namespace std;

int main(){
    int tcase;
    cin >> tcase;

    while(tcase > 0){
        int r;
        string again_str;
        cin >> r >> again_str;
        int size = again_str.size();

        for(int i=0;i<size;i++){
            for(int j=0;j<r;j++){
                cout << again_str.at(i);
            }
        }
        cout << '\n';

        tcase -= 1;
    }

    return 0;
}