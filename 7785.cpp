#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> emp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string e_name,e_state;
        cin >> e_name >> e_state;
        if(!e_state.compare("enter")){
            emp.insert(e_name);
        }
        else{
            emp.erase(e_name);
        }
    }
    for(auto it=emp.rbegin();it!=emp.rend();it++){
        cout << *it << '\n';
    }

    return 0;
}