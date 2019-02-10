#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_pi(string p){
    int size = p.size();
    vector<int> pi_vec(size);
    int j=0;
    pi_vec[0] = 0;
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

vector<int> kmp(string s,string p){
    int s_size = s.size();
    int p_size = p.size();
    int j = 0;
    auto pi_vec = get_pi(p);
    vector<int> ans;
    for(int i=0;i<s_size;i++){
        while(j > 0 && s[i] != p[j]){
            j = pi_vec[j-1];
        }
        if(s[i] == p[j]){
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
    string s,p;
    getline(cin,s);
    getline(cin,p);
    auto ans = kmp(s,p);
    if(ans.size() == 0){
        cout << "0\n";
    }
    else{
        cout << "1\n";
    }

    return 0;
}