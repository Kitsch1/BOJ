#include <cstdio>
using namespace std;

int cherry[11],mult[11];
int n;

int main(){
    int ans = -1;
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        scanf("%d",&cherry[r]);
    }
    mult[0] = 1;
    mult[1] = cherry[1];
    for(int r=2;r<=n;r++){
        mult[r] = mult[r-1] * cherry[r];
    }
    /*
    for(int r=1;r<=n;r++){
        printf("%d ",mult[r]);
    }
    printf("\n");
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i+j+k >= n) continue;
                int fight = n-(i+j+k);
                int cur_ans = mult[i];
                cur_ans += mult[i+j] / mult[i];
                cur_ans += mult[i+j+k] / mult[i+j];
                cur_ans += mult[n] / mult[n-fight];
                if(ans == -1 || ans < cur_ans) ans = cur_ans;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}