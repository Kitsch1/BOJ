#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main(){
    char sentence[104];
    
    while(1){
        fgets(sentence,104,stdin);
        sentence[strlen(sentence) - 1] = '\0';
        if(sentence[0] == '.' && sentence[1] == '\0'){
            break;
        }

        stack<char> par;
        int size = strlen(sentence);
        int weird = 0;

        for(int i=0;i<size;i++){
            if(sentence[i] == '(' || sentence[i] == '['){
                par.push(sentence[i]);
            }
            else if(sentence[i] == ')'){
                if(par.empty() || par.top() == '['){
                    weird++;
                    continue;
                }
                if(par.top() == '('){
                    par.pop();
                }
            }
            else if(sentence[i] == ']'){
               if(par.empty() || par.top() == '('){
                   weird++;
                   continue;
               }
               if(par.top() == '['){
                   par.pop();
               }
            }
        }

        if(par.empty() && weird == 0){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        memset(sentence,0,sizeof(char)*104);
    }

    return 0;
}