#include <cstdio>
using namespace std;

char stars[2187][2187];

void lost_stars_dnc(int r_cur,int c_cur,int three_sq){
    if(three_sq == 3){
        for(int r=r_cur;r<r_cur+3;r++){
            for(int c=c_cur;c<c_cur+3;c++){
                stars[r][c] = '*';
            }
        }
        stars[r_cur+1][c_cur+1] = ' ';
        return;
    }

    int next_sq = three_sq/3;
    lost_stars_dnc(r_cur,c_cur,next_sq);
    lost_stars_dnc(r_cur,c_cur+next_sq,next_sq);
    lost_stars_dnc(r_cur,c_cur+next_sq*2,next_sq);
    lost_stars_dnc(r_cur+next_sq,c_cur,next_sq);
    lost_stars_dnc(r_cur+next_sq,c_cur+next_sq*2,next_sq);
    lost_stars_dnc(r_cur+next_sq*2,c_cur,next_sq);
    lost_stars_dnc(r_cur+next_sq*2,c_cur+next_sq,next_sq);
    lost_stars_dnc(r_cur+next_sq*2,c_cur+next_sq*2,next_sq);
}

int main(){
    int n;
    scanf("%d",&n);
    if(n == 1){
        printf("*\n");
    }
    else{
        lost_stars_dnc(0,0,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stars[i][j] == '*') printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}