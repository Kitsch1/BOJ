#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int visited[1000001];
int from[1000001];

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    from[n] = -1;
    while(!q.empty()){
        int n_cur = q.front();
        q.pop();
        if(n_cur == 1){
            printf("%d\n",visited[1]);
            break;
        }
        if(n_cur % 3 == 0 && visited[n_cur/3] == 0){
            visited[n_cur/3] = visited[n_cur] + 1;
            from[n_cur/3] = n_cur;
            q.push(n_cur/3);
        }
        if(n_cur % 2 == 0 && visited[n_cur/2] == 0){
            visited[n_cur/2] = visited[n_cur] + 1;
            from[n_cur/2] = n_cur;
            q.push(n_cur/2);
        }
        if(visited[n_cur-1] == 0){
            visited[n_cur-1] = visited[n_cur] + 1;
            from[n_cur-1] = n_cur;
            q.push(n_cur-1);
        }
    }
    int start = 1;
    stack<int> st;
    while(from[start] != -1){
        st.push(start);
        start = from[start];
    }
    st.push(n);
    while(!st.empty()){
        printf("%d ",st.top());
        st.pop();
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    bfs(n);

    return 0;
}