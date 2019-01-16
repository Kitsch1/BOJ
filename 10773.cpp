#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int n;
    long long res = 0;
    stack<long long> st;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        long long cur;
        scanf("%lld",&cur);
        if(!cur) st.pop();
        else st.push(cur);
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    printf("%lld\n",res);

    return 0;
}