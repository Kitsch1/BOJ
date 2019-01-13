#include <cstdio>
#include <cstring>
using namespace std;

int freq[101];

int main(){
    int tcase,t_num;
    scanf("%d",&tcase);
    
    while(tcase > 0){
        scanf("%d",&t_num);
        for(int i=0;i<1000;i++){
            int score;
            scanf("%d",&score);
            freq[score] += 1;
        }
        int highest_freq = freq[0];
        for(int i=1;i<=100;i++){
            if(highest_freq < freq[i]){
                highest_freq = freq[i];
            }
        }
        for(int i=100;i>=0;i--){
            if(highest_freq == freq[i]){
                printf("#%d %d\n",t_num,i);
                break;
            }
        }

        memset(freq,0,sizeof(int)*101);
        tcase -= 1;
    }

    return 0;
}