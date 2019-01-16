#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool not_prime[10000]; // true : not prime, false : prime
bool visited[10000];
vector<int> prime_vec;

bool prime_binary_search(int find){
    int start = 0, end = prime_vec.size()-1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        if(prime_vec[mid] > find) end = mid - 1;
        else if(prime_vec[mid] == find) return true;
        else start = mid + 1;
    }
    return false;
}

int bfs(string &num_begin, string &num_end){
    queue<pair<int,string>> q;
    q.push(make_pair(0,num_begin));
    visited[stoi(num_begin)] = true;

    while(!q.empty()){
        int phase = q.front().first;
        string cur_num = q.front().second;
        q.pop();

        if(!cur_num.compare(num_end)){
            return phase;
        }
        for(int i=0;i<4;i++){
            int j;
            if(i == 0) j = 1;
            else j = 0;
            string next_num = cur_num;
            
            for(;j<10;j++){
                next_num.replace(i,1,to_string(j));
                if(!visited[stoi(next_num)] && prime_binary_search(stoi(next_num))){
                    visited[stoi(next_num)] = true;
                    q.push(make_pair(phase+1,next_num));
                }
            }
        }
    }
    return -1;
}

int main(){
    int tcase;
    cin >> tcase;

    // eratos
    not_prime[0] = not_prime[1] = true;
    for(int i=4;i < 10000;i += 2){
        not_prime[i] = true;
    }
    for(int i=3;i*i<10000;i++){
        for(int j = i*2;j<10000;j += i){
            not_prime[j] = true;
        }
    }
    for(int i=1000;i<10000;i++){
        if(not_prime[i] == false){
            prime_vec.push_back(i);
        }
    }
    while(tcase > 0){
        string num_begin,num_end;
        cin >> num_begin >> num_end;

        int res = bfs(num_begin,num_end);
        if(res == -1){
            cout << "Impossible\n";
        }
        else{
            cout << res << '\n';
        }

        memset(visited,false,sizeof(bool)*10000);
        tcase -= 1;
    }

    return 0;
}