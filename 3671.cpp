#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

bool selected[7];
int jari;

void make_number(int cur_jari,string &num_list,string &cur_num,set<int> &made_num){
    int size = cur_num.size();
    if(size == cur_jari){
        int converted = stoi(cur_num);
        if(converted == 0 || converted == 1) return;
        if(made_num.find(converted) == made_num.end()){
            bool flag = true;
            for(int i=2;i*i<=converted;i++){
                if(converted % i == 0){
                    flag = false; break;
                }
            }
            if(flag) made_num.insert(converted);
        }
        return;
    }
    for(int i=0;i<jari;i++){
        if(!selected[i]){
            selected[i] = true; cur_num.push_back(num_list[i]);
            make_number(cur_jari,num_list,cur_num,made_num);
            selected[i] = false; cur_num.pop_back();
        }
    }
}

int main(){
    int tcase;
    cin >> tcase;
    while(tcase > 0){
        string num_list,cur_num;
        set<int> made_num;
        cin >> num_list;
        jari = num_list.size();
        for(int i=1;i<=jari;i++){
            make_number(i,num_list,cur_num,made_num);
        }
        cout << made_num.size() << '\n';
        memset(selected,false,sizeof(selected));
        tcase -= 1;
    }

    return 0;
}