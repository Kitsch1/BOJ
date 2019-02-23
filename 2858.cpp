#include <iostream>
using namespace std;

int main(){
    int red_num,brown_num;
    cin >> red_num >> brown_num;
    int all_tile = red_num + brown_num;
    for(int r=1;;r++){
        if(all_tile % r) continue;
        int c = all_tile / r;
        if(c < r) break;
        if((r-2) * (c-2) == brown_num){
            printf("%d %d\n",c,r); break;
        }   
    }

    return 0;
}