#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int listen,look;
    string p_name;
    set<string> dude;
    vector<string> mumyung;

    cin >> listen >> look;
    for(int i=0;i<listen;i++){
        cin >> p_name;
        dude.insert(p_name);
    }
    for(int i=0;i<look;i++){
        cin >> p_name;
        if(dude.find(p_name) == dude.end()) continue;
        dude.erase(p_name);
        mumyung.push_back(p_name);
    }
    sort(mumyung.begin(),mumyung.end());
    cout << mumyung.size() << '\n';
    for(auto a : mumyung){
        cout << a << '\n';
    }

    return 0;
}