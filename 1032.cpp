#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n,len;
    cin >> n;
    vector<string> f_title;
    for(int r=0;r<n;r++){
        string n_file;
        cin >> n_file;
        f_title.push_back(n_file);
    }
    len = f_title[0].size();
    string pattern;
    for(int r=0;r<len;r++){
        bool flag = true;
        for(int c=1;c<n;c++){
            if(f_title[c-1][r] != f_title[c][r]){
                flag = false; break;
            }
        }
        if(flag) pattern.push_back(f_title[0][r]);
        else pattern.push_back('?');
    }
    cout << pattern << '\n';

    return 0;
}