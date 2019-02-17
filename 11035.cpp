#include <cstdio>
#include <cstring>

bool eratos[1001];

int main(){
    int n1,n2;
    while(~(scanf("%d %d",&n1,&n2))){
        eratos[1] = true;
        int cnt = 0;
        bool flag = false;
        for(int i=2;i<=n1;i++){
            if(eratos[i]) continue;
            for(int j=i;j<=n1;j+=i){
                if(!eratos[j]){
                    eratos[j] = true;
                    cnt += 1;
                    if(cnt == n2){
                        flag = true;
                        printf("%d\n",j);
                        break;
                    }
                }
            }
            if(flag) break;
        }
        memset(eratos,false,sizeof(eratos));
    }

    return 0;
}