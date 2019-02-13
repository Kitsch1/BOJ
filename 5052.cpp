#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int tcase,n;
    cin >> tcase;
    while(tcase > 0){
        bool flag = true;
        cin >> n;
        vector<string> pnum;
        for(int i=0;i<n;i++){
            string cur;
            cin >> cur;
            pnum.push_back(cur);
        }
        sort(pnum.begin(),pnum.end());
        for(int r=1;r<n;r++){
            string front_str = pnum[r].substr(0,pnum[r-1].size());
            if(!pnum[r-1].compare(front_str)){
                flag = false; break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";

        tcase -= 1;
    }

    return 0;
}