#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_pi(string p){
    int size = p.size();
    vector<int> pi_vec(size);
    pi_vec[0] = 0;
    int j = 0;
    for(int i=1;i<size;i++){
        while(j > 0 && p[i] != p[j]){
            j = pi_vec[j-1];
        }
        if(p[i] == p[j]){
            pi_vec[i] = j+1;
            j += 1;
        }
        else{
            pi_vec[i] = 0;
        }
    }

    return pi_vec;
}

vector<int> kmp(string t_str,string p_str){
    int t_size = t_str.size();
    int p_size = p_str.size();
    int j = 0;
    auto pi_vec = get_pi(p_str);
    vector<int> ans;
    for(int i=0;i<t_size;i++){
        while(j > 0 && t_str[i] != p_str[j]){
            j = pi_vec[j-1];
        }
        if(t_str[i] == p_str[j]){
            if(j == p_size - 1){
                ans.push_back(i-p_size+1);
                j = pi_vec[j];
            }
            else{
                j += 1;
            }
        }
    }

    return ans;
}

int main(){
    string t_str,p_str;
    getline(cin,t_str);
    getline(cin,p_str);
    auto ans = kmp(t_str,p_str);
    cout << ans.size() << '\n';
    for(auto a : ans){
        cout << a + 1 << ' ';
    }
    cout << '\n';

    return 0;
}