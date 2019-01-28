#include <cstdio>

int res = -1;
int demand[10000];
int n,budget;

void find_limit(int start,int end){
    int mid;
    while(start <= end){
        mid = (start + end) / 2;
        int needed = 0;
        for(int r=0;r<n;r++){
            if(mid < demand[r]) needed += mid;
            else needed += demand[r];
        }
        if(needed > budget){
            end = mid - 1;
        }
        else{
            if(res == -1 || res < mid) res = mid;
            start = mid + 1;
        }
    }
}


int main(){
    int end = -1;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        scanf("%d",&demand[r]);
        if(end == -1 || end < demand[r]) end = demand[r];
    }
    scanf("%d",&budget);
    find_limit(0,end);
    printf("%d\n",res);

    return 0;
}