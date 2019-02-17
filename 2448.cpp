#include <cstdio>
using namespace std;

char stars[3072][6148];

void solve(int r,int c,int three_sq){
    if(three_sq == 3){
        stars[r][c] = '*'; 
        stars[r+1][c-1] = stars[r+1][c+1] = '*';
        stars[r+2][c-2] = stars[r+2][c-1] = stars[r+2][c] = stars[r+2][c+1] = stars[r+2][c+2] = '*';

        return;
    }
    three_sq /= 2;
    solve(r,c,three_sq);
    solve(r+three_sq,c-three_sq,three_sq);
    solve(r+three_sq,c+three_sq,three_sq);
}

int main(){
    int n;
    int c_end;
    scanf("%d",&n);
    c_end = (n*2) - 1;
    solve(0,n-1,n);
    for(int r=0;r<n;r++){
        for(int c=0;c<c_end;c++){
            if(stars[r][c] == '*') printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}