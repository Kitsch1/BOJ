#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool cmp(int a,int b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(a > b) return true;
    else return false;
}

int main(){
    int n;
    vector<int> medic_vec;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        int medic;
        scanf("%d",&medic);
        medic_vec.push_back(medic);
    }
    sort(medic_vec.begin(),medic_vec.end(),cmp);

    int diff_res;
    int first = medic_vec[0];
    int second = medic_vec[1];
    diff_res = first + second;
    if(diff_res < 0) diff_res = -diff_res;

    for(int r=2;r<n;r++){
        int cur_diff;
        cur_diff = medic_vec[r-1] + medic_vec[r];
        if(cur_diff < 0) cur_diff = -cur_diff;
        if(diff_res > cur_diff){
            diff_res = cur_diff;
            first = medic_vec[r-1];
            second = medic_vec[r];
        }
    }
    if(first > second) printf("%d %d\n",second,first);
    else printf("%d %d\n",first,second);

    return 0;
}