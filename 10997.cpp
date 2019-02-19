#include <cstdio>
using namespace std;

char stars[404][404];

void sigong_zoa(int r_cur,int c_cur,int n_cur){
    if(n_cur == 2){
        int len = 5;
        for(int c=c_cur;c<c_cur+len;c++){
            stars[r_cur][c] = '*';
        }
        for(int r=r_cur+1;r<=r_cur+len;r++){
            stars[r][c_cur] = '*';
        }
        for(int c=c_cur;c<c_cur+len;c++){
            stars[r_cur+6][c] = '*';
        }
        for(int r=r_cur+2;r<=r_cur+len;r++){
            stars[r][c_cur+len-1] = '*';
        }
        stars[r_cur+2][c_cur+len-2] = stars[r_cur+2][c_cur+len-3] = '*';
        stars[r_cur+3][c_cur+len-3] = stars[r_cur+4][c_cur+len-3] = '*';
        return;
    }
    int len = 4 * n_cur - 3;
    int r_len = r_cur + len;
    for(int c=c_cur;c<c_cur+len;c++){
        stars[r_cur][c] = '*';
    } // right
    for(int r=r_cur+1;r<=r_len;r++){
        stars[r][c_cur] = '*';
    }
    for(int c=c_cur;c<c_cur+len;c++){
        stars[r_len+1][c] = '*';
    }
    for(int r=r_cur+2;r<=r_len;r++){
        stars[r][c_cur+len-1] = '*';
    }
    stars[r_cur+2][c_cur+len-2] = '*';
    sigong_zoa(r_cur+2,c_cur+2,n_cur-1);
}

int main(){
    int n;
    scanf("%d",&n);
    if(n == 1){
        printf("*\n");
    }
    else{
        sigong_zoa(0,0,n);
        int len = 4*n - 3;
        for(int r=0;r<=len+1;r++){
            if(r==1){
                printf("*\n");
                continue;
            }
            for(int c=0;c<len;c++){
                if(stars[r][c] == '*') printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}