#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

bool printed[100];

int solve(int check_num,deque<int> &doc_q,vector<int> &doc_ranking){
    int order = 1;
    int size = doc_ranking.size();
    
    while(!doc_q.empty()){
        int front_rank = doc_ranking[doc_q.front()];
        
        bool flag = true;
        for(int i=0;i<size;i++){
            if(printed[i] == false){
                if(doc_ranking[doc_q.front()] < doc_ranking[i]){
                    flag = false; break;
                }
            }
        }
        if(flag == true){
            if(doc_q.front() == check_num){
                return order;
            }
            order += 1;
            printed[doc_q.front()] = true;
            doc_q.pop_front();
        } // print
        else{
            int back_to = doc_q.front();
            doc_q.push_back(back_to);
            doc_q.pop_front();
        }
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);

    while(tcase > 0){
        int doc_num, check_num;
        scanf("%d %d",&doc_num,&check_num);

        deque<int> doc_q;
        vector<int> doc_ranking(doc_num);
        for(int i=0;i<doc_num;i++){
            doc_q.push_back(i);
        }
        for(int i=0;i<doc_num;i++){
            scanf("%d",&doc_ranking[i]);
        }
        printf("%d\n",solve(check_num,doc_q,doc_ranking));

        memset(printed,false,sizeof(bool)*100);
        tcase -= 1;
    }

    return 0;
}