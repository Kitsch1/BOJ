#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(char a,char b){
    if(a > b){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char input[12];
    int len;
    scanf("%s",input);
    len = strlen(input);
    sort(input,input+len,cmp);
    printf("%s",input);

    return 0;
}