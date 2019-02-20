#include <cstdio>

int main(){
    int a,b,v;
    scanf("%d %d %d",&a,&b,&v);
    int before = v-a;
    int before_day;
    if(before%(a-b) == 0) before_day = before / (a-b);
    else before_day = (before / (a-b)) + 1;
    printf("%d\n",before_day+1);

    return 0;
}