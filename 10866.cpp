#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;

int main(){
    int tcase;
    deque<int> dq;
    scanf("%d",&tcase);

    for(int i=0;i<tcase;i++){
        char order[16];
        int dq_input,dq_popped;

        scanf("%s",order);
        if(!strcmp(order,"push_front")){
            scanf("%d",&dq_input);
            dq.push_front(dq_input);
        }
        else if(!strcmp(order,"push_back")){
            scanf("%d",&dq_input);
            dq.push_back(dq_input);
        }
        else if(!strcmp(order,"pop_front")){
            if(dq.empty()){
                printf("-1\n"); continue;
            }
            dq_popped = dq.front();
            printf("%d\n",dq_popped);
            dq.pop_front();
        }
        else if(!strcmp(order,"pop_back")){
            if(dq.empty()){
                printf("-1\n"); continue;
            }
            dq_popped = dq.back();
            printf("%d\n",dq_popped);
            dq.pop_back();
        }
        else if(!strcmp(order,"size")){
            printf("%d\n",dq.size());
        }
        else if(!strcmp(order,"empty")){
            if(dq.empty()) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(order,"front")){
            if(dq.empty()) printf("-1\n");
            else printf("%d\n",dq.front());
        }
        else if(!strcmp(order,"back")){
            if(dq.empty()) printf("-1\n");
            else printf("%d\n",dq.back());
        }
    }

    return 0;
}