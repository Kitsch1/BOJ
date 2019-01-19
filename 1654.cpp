#include <iostream>
using namespace std;

long long res = -1;
long long lan_line[10000];

void finding_len(long long start,long long end,long long k,long long n){
    long long mid;
    while(start <= end){
        mid = (start + end) / 2;
        long long lan_amount = 0;
        for(int i=0;i<k;i++){
            long long cur_lan = lan_line[i];
            lan_amount += (cur_lan / mid);
        }
        if(lan_amount >= n){
            if(res == -1 || res < mid) res = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
}

int main(){
    long long k,n,end = -1;
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> lan_line[i];
        if(end < lan_line[i]){
            end = lan_line[i];
        }
    }
    finding_len(1,end,k,n);
    cout << res << '\n';

    return 0;
}