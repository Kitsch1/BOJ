#define INF 987654321
#include <cstdio>
#include <vector>
using namespace std;

typedef struct city{
    int tele;
    int r;
    int c;
}city;
vector<city> all_cities;

int tele_dist(int n,int city_idx){
    int r_start = all_cities[city_idx].r;
    int c_start = all_cities[city_idx].c;
    int dist = INF;

    for(int i=1;i<=n;i++){
        if(all_cities[i].tele){
            int r_dist = all_cities[i].r - r_start;
            if(r_dist < 0) r_dist = -r_dist;
            int c_dist = all_cities[i].c - c_start;
            if(c_dist < 0) c_dist = -c_dist;
            if(dist > r_dist + c_dist) dist = r_dist + c_dist;
        }
    }
    return dist;
}

int main(){
    int n,t_time;
    scanf("%d %d",&n,&t_time);
    all_cities.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&all_cities[i].tele,&all_cities[i].r,&all_cities[i].c);
    }
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int c1,c2;
        scanf("%d %d",&c1,&c2);
        
        int r_diff = all_cities[c1].r - all_cities[c2].r;
        if(r_diff < 0) r_diff = -r_diff;
        int c_diff = all_cities[c1].c - all_cities[c2].c;
        if(c_diff < 0) c_diff = -c_diff;
        int ans = r_diff + c_diff;
        int tele_ans = tele_dist(n,c1) + tele_dist(n,c2) + t_time;
        if(ans > tele_ans) ans = tele_ans;
        printf("%d\n",ans);
        tcase -= 1;
    }

    return 0;
}