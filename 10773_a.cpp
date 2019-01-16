#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    long long res = 0;
    vector<long long> v;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        long long cur;
        scanf("%lld",&cur);
        if(!cur) v.pop_back();
        else v.push_back(cur);
    }
    int size = v.size();
    for(int i=0;i<size;i++){
        res += v[i];
    }
    printf("%lld\n",res);

    return 0;
}