#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int res = -1;

void make_alpha_set(int n,int k,int cur_k,int start,vector<int> &word_mask,int cur_mask){
    if(cur_k == k){
        int cur_res = 0;
        for(int i=0;i<n;i++){
            if((word_mask[i] & cur_mask) == word_mask[i]){
                cur_res += 1;
            }
        }
        if(res == -1 || res < cur_res){
            res = cur_res;
        }
        return;
    }
    for(int i=start;i<26;i++){
        if(i=='a'-'a' || i=='n'-'a' || i=='t'-'a' || i=='i'-'a' || i=='c'-'a'){
            continue;
        }
        cur_mask |= (1<<i);
        make_alpha_set(n,k,cur_k+1,i+1,word_mask,cur_mask);
        cur_mask = cur_mask & (~(1<<i));
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> word_mask(n);
    for(int i=0;i<n;i++){
        char cur_word[16];
        scanf("%s",cur_word);
        int len = strlen(cur_word);
        for(int j=0;j<len;j++){
            word_mask[i] |= (1<<(cur_word[j]-'a'));
        }
    }
    int cur_mask = 0;
    cur_mask |= (1<<('a'-'a')); cur_mask |= (1<<('n'-'a'));
    cur_mask |= (1<<('t'-'a')); cur_mask |= (1<<('i'-'a'));
    cur_mask |= (1<<('c'-'a'));
    if(k < 5){
        res = 0;
    }
    else if(k == 26){
        res = n;
    }
    else{
        make_alpha_set(n,k,5,1,word_mask,cur_mask);
    }
    printf("%d\n",res);

    return 0;
}