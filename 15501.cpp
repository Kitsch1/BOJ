#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    bool flag = true;
    int find_start;
    scanf("%d",&n);
    vector<int> numbers(n),dest_num(n);
    for(int r=0;r<n;r++){
        scanf("%d",&numbers[r]);
    }
    for(int r=0;r<n;r++){
        scanf("%d",&dest_num[r]);
        if(dest_num[r] == numbers[0]) find_start = r;
    }
    for(int r=1;r<n;r++){
        int left_num,right_num;
        if(numbers[r] == dest_num[find_start]) continue;
        if(!find_start) left_num = n-1;
        else left_num = find_start - 1;
        if(find_start == n-1) right_num = 0;
        else right_num = find_start + 1;
        if(numbers[r] == dest_num[left_num]){
            find_start = left_num;
        }
        else if(numbers[r] == dest_num[right_num]){
            find_start = right_num;            
        }
        else{
            flag = false; break;
        }
    }
    if(flag) printf("good puzzle\n");
    else printf("bad puzzle\n");

    return 0;
}