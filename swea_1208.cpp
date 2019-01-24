#include <cstdio>

int height[100];
int high_idx,high_val,low_idx,low_val;

void low_high(){
    for(int i=1;i<100;i++){
        if(high_val < height[i]){
            high_val = height[i];
            high_idx = i;
        }
        if(low_val > height[i]){
            low_val = height[i];
            low_idx = i;
        }
    }
}

int find(int d_num){
    int change;
    
    for(change=0;change<=d_num;change++){
        high_idx = low_idx = 0;
        high_val = low_val = height[0];
        low_high();
        if(high_val - low_val <= 1){
            return high_val - low_val;
        }
        height[high_idx] -= 1;
        height[low_idx] += 1;
    }
    low_high();
    return high_val - low_val;
}

int main(){
    int d_num;
    for(int i=1;i<=10;i++){
        scanf("%d",&d_num);
        for(int j=0;j<100;j++){
            scanf("%d",&height[j]);
        }
        printf("#%d %d\n",i,find(d_num));
    }

    return 0;
}