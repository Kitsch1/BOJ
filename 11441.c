#include <stdio.h>

int all_num[100001];
int sum_all[100001];

int main(){
    int n,i,q,begin,end;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&all_num[i]);
    }
    sum_all[1] = all_num[1];
    for(i=2;i<=n;i++){
        sum_all[i] = sum_all[i-1] + all_num[i];
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d",&begin,&end);
        printf("%d\n",sum_all[end]-sum_all[begin-1]);
    }

    return 0;
}