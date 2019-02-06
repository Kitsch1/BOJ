#include <stdio.h>

int main(){
    int tcase,i,series,res,len;
    char input[84];
    scanf("%d",&tcase);
    while(tcase > 0){
        res = 0;
        scanf("%s",input);
        series = 1;
        for(i=0;;i++){
            if(input[i] == '\0') break;
            if(input[i] == 'O'){
                res += series;
                series += 1;
            }
            else{
                series = 1;
            }
        }
        printf("%d\n",res);
        tcase -= 1;
    }

    return 0;
}