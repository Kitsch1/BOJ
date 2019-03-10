#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int fried,spice,both,f_num,s_num;
    int ans_both = 0, ans_comb = 0, ans_indie = 0;
    scanf("%d %d %d %d %d",&fried,&spice,&both,&f_num,&s_num);
    
    int both_one = both * 2;
    int bigger = (f_num > s_num) ? f_num : s_num;
    ans_both += both_one * bigger;
    ans_indie += (f_num * fried) + (s_num * spice);
    if(f_num > s_num){
        ans_comb += (both_one * s_num);
        ans_comb += fried * (f_num - s_num);
    }
    else{
        ans_comb += (both_one * f_num);
        ans_comb += spice * (s_num - f_num);
    }
    printf("%d\n",min(ans_both,min(ans_indie,ans_comb)));

    return 0;
}