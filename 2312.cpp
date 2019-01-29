#include <cstdio>
#include <vector>
using namespace std;

bool eratos[100001]; // true : not prime
vector<int> prime;

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int r=4;r<=100000;r+=2){
        eratos[r] = true;
    }
    eratos[1] = true;
    for(int r=3;r*r<=100000;r++){
        for(int c=r*2;c<=100000;c+=r){
            eratos[c] = true;
        }
    }
    for(int r=2;r<=100000;r++){
        if(!eratos[r]) prime.push_back(r);
    }
    int size = prime.size();
    while(tcase > 0){
        int cur_num;
        scanf("%d",&cur_num);
        while(cur_num > 1){
            for(int i=0;i<size;i++){
                int cur_prime = prime[i];
                int cur_sq = 0;
                while(cur_num % cur_prime == 0){
                    cur_num /= cur_prime;
                    cur_sq += 1;
                }
                if(cur_sq > 0){
                    printf("%d %d\n",cur_prime,cur_sq);
                }
                if(cur_num == 1) break;
            }
        }

        tcase -= 1;
    }

    return 0;
}