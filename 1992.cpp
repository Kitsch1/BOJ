#include <cstdio>

char quad[64][64];

bool check(int r,int c,int n){
    char c_num = quad[r][c];
    for(int i=r;i<r+n;i++){
        for(int j=c;j<c+n;j++){
            if(c_num != quad[i][j]) return false;
        }
    }
    return true;
}

void solve(int r,int c,int n){
    if(check(r,c,n)){
        printf("%c",quad[r][c]);
        return;
    }
    else{
        int half_n = n/2;
        printf("(");
        solve(r,c,half_n);
        solve(r,c+half_n,half_n);
        solve(r+half_n,c,half_n);
        solve(r+half_n,c+half_n,half_n);
        printf(")");
    }
}

int main(){
    int n;
    char input[68];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",input);
        for(int j=0;j<n;j++){
            quad[i][j] = input[j];
        }
    }
    solve(0,0,n);
    printf("\n");

    return 0;
}