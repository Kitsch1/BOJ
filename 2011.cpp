#include <cstdio>
#include <cstring>
using namespace std;

int dp[5004];
int len;

int main(){
    char pwd_code[5004];
    scanf("%s",pwd_code);
    len = strlen(pwd_code);
    
    if(pwd_code[0] == '0'){
        printf("0\n");
    }
    else{
        dp[0] = dp[1] = 1;
        for(int i=2;i<=len;i++){
            if((pwd_code[i-1] - '0') > 0){
                dp[i] = dp[i-1] % 1000000;
            }
            int two_num = (pwd_code[i-2] - '0') * 10 + (pwd_code[i-1] - '0');
            if(two_num >= 10 && two_num <= 26){
                dp[i] = (dp[i] + dp[i-2]) % 1000000;
            }
        }
        printf("%d\n",dp[len]);
    }

    return 0;
}