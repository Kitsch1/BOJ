#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string,int> part;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string part_name;
        cin >> part_name;
        auto it = part.find(part_name);
        if(it != part.end()){
            it->second += 1;
        }
        else{
            part.insert(make_pair(part_name,1));
        }
    }
    for(int i=1;i<n;i++){
        string in_name;
        cin >> in_name;
        auto it = part.find(in_name);
        if(it->second == 1){
            part.erase(it);
        }
        else{
            it->second -= 1;
        }
    }
    auto idle_dude = part.begin();
    cout << idle_dude->first << '\n';

    return 0;
}