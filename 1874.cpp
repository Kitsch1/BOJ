#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int need_to_create[100000];
stack<int> st;
vector<int> created;
vector<char> op_vec;

void solve(int n){
    int idx_to_find = 0;
    int pushed = 2;
    bool flag = true;
    st.push(1);
    op_vec.push_back('+');

    while(pushed <= n){
        if(st.empty() || st.top() < need_to_create[idx_to_find]){
            st.push(pushed);
            pushed += 1;
            op_vec.push_back('+');
        }
        else if(st.top() == need_to_create[idx_to_find]){
            st.pop();
            op_vec.push_back('-');
            idx_to_find += 1;
        }
        else{
            break;
        }
    }
    while(!st.empty()){
        if(st.top() != need_to_create[idx_to_find]){
            flag = false; break;
        }
        st.pop();
        op_vec.push_back('-');
        idx_to_find += 1;
    }
    if(!flag){
        printf("NO\n");
    }
    else{
        for(auto a : op_vec){
            printf("%c\n",a);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        scanf("%d",&need_to_create[r]);
    }
    solve(n);

    return 0;
}