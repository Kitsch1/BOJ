#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

bool chess[6][6];
vector<string> tour(36);

const int r_way[8] = {1,2,1,2,-1,-2,-1,-2};
const int c_way[8] = {2,1,-2,-1,2,1,-2,-1};

int main(){
    int r_cur,c_cur,r_next,c_next;
    string k_pos;
    bool flag = true;
    for(int i=0;i<36;i++){
        cin >> k_pos;
        tour[i] = k_pos;
    }
    for(int i=0;i<35;i++){
        r_cur = tour[i][1] - '0' - 1;
        c_cur = tour[i][0] - 'A';
        r_next = tour[i+1][1] - '0' - 1;
        c_next = tour[i+1][0] - 'A';
        bool cur_flag = false;
        if(chess[r_next][c_next]){
            flag = cur_flag; break;
        }
        for(int j=0;j<8;j++){
            if(r_cur + r_way[j] == r_next && c_cur + c_way[j] == c_next){
                chess[r_next][c_next] = true;
                cur_flag = true;
                break;
            }
        }
        if(!cur_flag){
            flag = cur_flag; break;
        }
    }
    if(!flag){
        cout << "Invalid\n"; return 0;
    }
    r_cur = tour[35][1] - '0' - 1;
    c_cur = tour[35][0] - 'A';
    r_next = tour[0][1] - '0' - 1;
    c_next = tour[0][0] - 'A';
    bool final_flag = false;
    for(int j=0;j<8;j++){
        if(r_cur + r_way[j] == r_next && c_cur + c_way[j] == c_next){
            if(!chess[r_next][c_next]){
                chess[r_next][c_next] = true;
                final_flag = true;
                break;
            }
        }
    }
    flag = final_flag;
    if(flag) cout << "Valid\n";
    else cout << "Invalid\n";

    return 0;
}