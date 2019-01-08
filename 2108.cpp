#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int counting[4001][2]; // 0 : positive, 1 : negative

int main(){
    int n,num_max,num_min;
    int freq_max = 0;
    double avg;
    scanf("%d",&n);
    vector<int> numbers;
    vector<int> freq;

    for(int i=0;i<n;i++){
        int cur;
        scanf("%d",&cur);
        numbers.push_back(cur);
        if(cur == 0){
            counting[0][0] += 1;
        }
        else if(cur > 0){
            counting[cur][0] += 1;
        }
        else{
            counting[-cur][1] += 1;
        }
        avg += (double)cur;
    }
    avg = round(avg/n);

    sort(numbers.begin(),numbers.end());
    num_max = numbers[n-1];
    num_min = numbers[0];

    for(int i=0;i<=4000;i++){
        for(int j=0;j<2;j++){
            if(counting[i][j] > freq_max){
                freq_max = counting[i][j];
            }
        }
    }
    for(int i=0;i<=4000;i++){
        for(int j=0;j<2;j++){
            if(counting[i][j] == freq_max){
                if(j == 0){
                    freq.push_back(i);
                }
                else{
                    freq.push_back(-i);
                }
            }
        }
    }
    sort(freq.begin(),freq.end());
    
    printf("%d\n",(int)avg);
    printf("%d\n",numbers[n/2]);
    if(freq.size() == 1){
        printf("%d\n",freq[0]);
    }
    else{
        printf("%d\n",freq[1]);
    }
    printf("%d\n",num_max - num_min);

    return 0;
}