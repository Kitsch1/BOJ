#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> q;
    cin >> n;
    for(int r=1;r<=n;r++){
        q.push(r);
    }
    while(q.size() > 1){
        cout << q.front() << ' ';
        q.pop();
        int cur_front = q.front();
        q.pop();
        q.push(cur_front);
    }
    cout << q.front() << '\n';

    return 0;
}