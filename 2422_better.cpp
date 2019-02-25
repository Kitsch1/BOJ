#include <cstdio>
using namespace std;

bool not_good[201][201];

int main(){
    int n,m;
    int res = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        not_good[n1][n2] = not_good[n2][n1] = true;
    }
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(not_good[i][j] || not_good[j][k] || not_good[i][k]){
                    continue;
                }
                res += 1;
            }
        }
    }
    printf("%d\n",res);

    return 0;
}