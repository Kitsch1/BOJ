#include <cstdio>
#include <cstring>
using namespace std;

int jari[9];

int main(){
    char num[8];
    int len;
    scanf("%s",num);
    len = strlen(num);
    for(int i=0;i<len;i++){
        if(num[i] == '6' || num[i] == '9'){
            jari[6] += 1;
        }
        else{
            jari[num[i] - '0'] += 1;
        }
    }
    if(jari[6] % 2 == 0){
        jari[6] /= 2;
    }
    else{
        jari[6] = (jari[6]/2) + 1;
    }

    int res = jari[0];
    for(int i=1;i<9;i++){
        if(res < jari[i]){
            res = jari[i];
        }
    }
    printf("%d\n",res);

    return 0;
}