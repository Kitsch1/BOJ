#include <cstdio>
using namespace std;

char stars[404][404];

void sigong(int r_cur,int c_cur,int n_cur){
    if(n_cur == 1){
        stars[r_cur][c_cur] = '*';
        return;
    }
    int len = 4 * n_cur - 3;
    for(int c=c_cur;c<c_cur+len;c++){
        stars[r_cur][c] = '*';
    }
    for(int r=r_cur+1;r<r_cur+len;r++){
        stars[r][c_cur] = '*';
    }
    for(int c=c_cur;c<c_cur+len;c++){
        stars[r_cur+len-1][c] = '*';
    }
    for(int r=r_cur+1;r<r_cur+len;r++){
        stars[r][c_cur+len-1] = '*';
    }
    sigong(r_cur+2,c_cur+2,n_cur-1);
}

int main(){
    int n;
    scanf("%d",&n);
    if(n == 1) printf("*\n");
    else{
        sigong(0,0,n);
        int len = 4*n-3;
        for(int r=0;r<len;r++){
            for(int c=0;c<len;c++){
                if(stars[r][c] == '*') printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}