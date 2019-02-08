#include <cstdio>
using namespace std;

char candy[50][50];
int n;

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int check_candy(){
    int res = 1;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            int r_next = r + 1;
            int c_next = c + 1;
            
            int cur_res = 1;
            while(r_next < n){
                if(candy[r_next][c] != candy[r][c]){
                    break;
                }
                cur_res += 1;
                r_next += 1;
            }
            if(res < cur_res) res = cur_res;

            cur_res = 1;
            while(c_next < n){
                if(candy[r][c_next] != candy[r][c]){
                    break;
                }
                cur_res += 1;
                c_next += 1;
            }
            if(res < cur_res) res = cur_res;
        }
    }
    return res;
}

int solve(){
    int res = 1;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            int cur_res;
            if(r+1 < n && candy[r][c] != candy[r+1][c]){
                swap(&candy[r][c],&candy[r+1][c]);
                cur_res = check_candy();
                swap(&candy[r][c],&candy[r+1][c]);
                if(res < cur_res) res = cur_res;
            }
            if(c+1 < n && candy[r][c] != candy[r][c+1]){
                swap(&candy[r][c],&candy[r][c+1]);
                cur_res = check_candy();
                swap(&candy[r][c],&candy[r][c+1]);
                if(res < cur_res) res = cur_res;
            }
        }
    }
    return res;
}

int main(){
    char input[52];
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        scanf("%s",input);
        for(int c=0;c<n;c++){
            candy[r][c] = input[c];
        }
    }
    printf("%d\n",solve());

    return 0;
}