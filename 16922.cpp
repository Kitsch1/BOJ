#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n;
    set<int> rome;
    scanf("%d",&n);

    for(int i=0;i<=n;i++){ // i : I (1)
        for(int j=0;j<=n;j++){ // j : V (5)
            for(int k=0;k<=n;k++){ // k : X (10)
                int cur_num;
                if(i+j+k > n) continue;
                cur_num = i * 1 + j * 5 + k * 10 + (n-i-j-k) * 50;
                if(rome.find(cur_num) == rome.end()){
                    rome.insert(cur_num);
                }
            }
        }
    }
    int ans = rome.size();
    printf("%d\n",ans);

    return 0;
}