#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,ans=0;
    set<string> passport;
    cin >> n;
    for(int i=0;i<n;i++){
        string p_num;
        cin >> p_num;
        passport.insert(p_num);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        string find_num;
        cin >> find_num;
        if(passport.find(find_num) != passport.end()){
            ans += 1;
        }
    }
    cout << ans << '\n';

    return 0;
}