#include <iostream>
#include <string>
using namespace std;

int main(){
    while(1){
        string cur_str;
        getline(cin,cur_str);
        if(cur_str.compare("END") == 0){
            break;
        }
        
        int size = cur_str.size();
        for(int i=size-1;i>=0;i--){
            cout << cur_str.at(i);
        }
        cout << '\n';
    }

    return 0;
}