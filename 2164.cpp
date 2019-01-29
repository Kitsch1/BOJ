#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> all_cards;
    cin >> n;
    for(int i=1;i<=n;i++){
        all_cards.push(i);
    }
    while(all_cards.size() > 1){
        all_cards.pop();
        if(all_cards.size() <= 1) break;
        int cur_front = all_cards.front();
        all_cards.pop();
        all_cards.push(cur_front);
    }
    printf("%d\n",all_cards.front());

    return 0;
}