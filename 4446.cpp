#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    string capital_vowel = "AIYEOU";
    string capital_conso = "BKXZNHDCWGPVJQTSRLMF";
    string small_vowel = "aiyeou";
    string small_conso = "bkxznhdcwgpvjqtsrlmf";
    int v_size = 6;
    int c_size = 20;
    while(getline(cin,input)){
        int size = input.size();
        for(int i=0;i<size;i++){
            int idx = -1;
            if(input[i] >= 'A' && input[i] <= 'Z'){
                for(int j=0;j<v_size;j++){
                    if(input[i] == capital_vowel[j]){
                        idx = j; break;
                    }
                }
                if(idx == -1){
                    for(int j=0;j<c_size;j++){
                        if(input[i] == capital_conso[j]){
                            idx = j; break;
                        }
                    }
                    if(idx < 10) input[i] = capital_conso[idx+10];
                    else input[i] = capital_conso[idx-10];
                }
                else{
                    if(idx < 3) input[i] = capital_vowel[idx+3];
                    else input[i] = capital_vowel[idx-3];
                }
            }
            else if(input[i] >= 'a' && input[i] <= 'z'){
                for(int j=0;j<v_size;j++){
                    if(input[i] == small_vowel[j]){
                        idx = j; break;
                    }
                }
                if(idx == -1){
                    for(int j=0;j<c_size;j++){
                        if(input[i] == small_conso[j]){
                            idx = j; break;
                        }
                    }
                    if(idx < 10) input[i] = small_conso[idx+10];
                    else input[i] = small_conso[idx-10];
                }
                else{
                    if(idx < 3) input[i] = small_vowel[idx+3];
                    else input[i] = small_vowel[idx-3];
                }
            }
        }
        cout << input << '\n';
    }

    return 0;
}