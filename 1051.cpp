#include <cstdio>
#include <algorithm>
using namespace std;

int rec[50][50];

int solve(int n,int m,int start){
    if(start == 1){
        return 1;
    }
    int res = -1;

    for(int i=start-1;i>=1;i--){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if((j+i < n) && (k+i < m)){
                    if(rec[j][k] == rec[j+i][k] && rec[j][k] == rec[j][k+i] && rec[j][k] == rec[j+i][k+i]){
                        if(res == -1 || res < ((i+1) * (i+1))){
                            res = (i+1) * (i+1);
                        }
                    }
                }
            }
        }
    }
    if(res == -1){
        return 1;
    }
    else{
        return res;
    }
}

int main(){
    int n,m,start;
    char input[52];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",input);
        for(int j=0;j<m;j++){
            rec[i][j] = input[j] - '0';
        }
    }
    start = min(n,m);
    printf("%d\n",solve(n,m,start));

    return 0;
}