#include <cstdio>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

void ac_function(string &cur_func,deque<int> &dq){
    bool f_r = true; // true : front, false : back
    bool error_flag = false; // true : error
    int func_size = cur_func.size();
    int dq_size = dq.size();

    for(int i=0;i<func_size;i++){
        if(cur_func[i] == 'R'){
            f_r = (!f_r);
        }
        else{
            if(dq_size == 0){
                error_flag = true;
                break;
            }
            if(f_r) dq.pop_front();
            else dq.pop_back();
            dq_size -= 1;
        }
    }

    if(error_flag){
        printf("error\n");
    }
    else{
        printf("[");
        if(f_r){
            for(int i=0;i<dq_size-1;i++){
                printf("%d,",dq[i]);
            }
            if(dq_size > 0){
                printf("%d",dq[dq_size-1]);
            }
        }
        else{
            for(int i=dq_size-1;i>0;i--){
                printf("%d,",dq[i]);
            }
            if(dq_size > 0){
                printf("%d",dq[0]);
            }
        }
        printf("]\n");
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        string cur_func,num_list;
        int elem_num,size;
        deque<int> dq;

        cin >> cur_func;
        scanf("%d",&elem_num);
        cin >> num_list;

        size = num_list.size();
        for(int i=1;i<size;){
            string cur_num;
            while(num_list[i] >= '0' && num_list[i] <= '9'){
                cur_num += num_list[i];
                i += 1;
            }
            if(cur_num.size() > 0) dq.push_back(stoi(cur_num));
            i += 1;
        }

        ac_function(cur_func,dq);
        tcase -= 1;
    }

    return 0;
}