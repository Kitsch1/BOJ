#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student{
    string name;
    int ko,en,ma;
}student;

bool cmp(student a,student b){
    if(a.ko == b.ko){
        if(a.en == b.en){
            if(a.ma == b.ma){
                return a.name < b.name;
            }
            return a.ma > b.ma;
        }
        return a.en < b.en;
    }
    return a.ko > b.ko;
}

int main(){
    int n;
    cin >> n;
    vector<student> st_vec(n);
    for(int i=0;i<n;i++){
        cin >> st_vec[i].name >> st_vec[i].ko >> st_vec[i].en >> st_vec[i].ma;
    }
    sort(st_vec.begin(),st_vec.end(),cmp);
    for(int i=0;i<n;i++){
        cout << st_vec[i].name << '\n';
    }

    return 0;
}