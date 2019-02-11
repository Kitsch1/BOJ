#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_pi(string advert){
    int size = advert.size();
    vector<int> pi(size);
    int j=0;
    pi[0] = 0;
    for(int i=1;i<size;i++){
        while(j>0 && advert[i] != advert[j]){
            j = pi[j-1];
        }
        if(advert[i] == advert[j]){
            pi[i] = j + 1;
            j += 1; 
        }
        else{
            pi[i] = 0;
        }
    }

    return pi;
} // prefix and suffix len

int main(){
    int len;
    string advert;
    cin >> len;
    getchar();
    getline(cin,advert);
    auto ad_pi = get_pi(advert);
    cout << len - ad_pi[len-1] << '\n';

    return 0;
}