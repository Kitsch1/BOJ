#include <cstdio>
using namespace std;
typedef long long lld;

lld line_len[81];

int main(){
    int n;
    scanf("%d",&n);
    line_len[0] = line_len[1] = 1;
    for(int i=2;i<=n;i++){
        line_len[i] = line_len[i-1] + line_len[i-2];
    }
    printf("%lld\n",line_len[n]*2+line_len[n-1]*2);

    return 0;
}