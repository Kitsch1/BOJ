#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int tcase;
    cin >> tcase;
    while(tcase > 0){
        bool flag = true;
        stack<char> par;
        string par_bundle;
        cin >> par_bundle;
        
        int size = par_bundle.size();
        for(int r=0;r<size;r++){
            if(par_bundle[r] == '(' || par_bundle[r] == '[' || par_bundle[r] == '{'){
                par.push(par_bundle[r]);
            }
            else if(par.empty()){
                flag = false; break;
            }
            else if(par.top() == '(' && par_bundle[r] == ')'){
                par.pop();
            }
            else if(par.top() == '[' && par_bundle[r] == ']'){
                par.pop();
            }
            else if(par.top() == '{' && par_bundle[r] == '}'){
                par.pop();
            }
            else{
                flag = false; break;
            }
        }
        if(!flag || !par.empty()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }

        tcase -= 1;
    }

    return 0;
}