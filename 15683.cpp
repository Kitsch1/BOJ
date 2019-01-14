#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

typedef struct dir{
    int r;
    int c;
}dir;

dir way[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int cctv_check[15][4] = { {0},{1},{2},{3},
                        {0,1},{2,3},
                        {0,3},{1,3},{1,2},{0,2},
                        {0,1,2},{0,1,3},{0,2,3},{1,2,3},
                        {0,1,2,3} };

int room[8][8];
bool blind[8][8];
vector<pair<int,pair<int,int>>> cctv_case;
int res = -1;
int r,c;

void checking_room(int cctv_num){
    bool blind_now[8][8];
    int cur_res = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            blind_now[i][j] = blind[i][j];
        }
    }

    for(int i=0;i<cctv_num;i++){
        int cctv_kind = cctv_case[i].first;
        int cctv_r = cctv_case[i].second.first;
        int cctv_c = cctv_case[i].second.second;
        int way_to_size;

        if(cctv_kind >= 0 && cctv_kind < 4){
            way_to_size = 1;
        }
        else if(cctv_kind >= 4 && cctv_kind < 10){
            way_to_size = 2;
        }
        else if(cctv_kind >= 10 && cctv_kind < 14){
            way_to_size = 3;
        }
        else{
            way_to_size = 4;
        }
        for(int j=0;j<way_to_size;j++){
            int way_to = cctv_check[cctv_kind][j];
            int cur_r = cctv_r + way[way_to].r;
            int cur_c = cctv_c + way[way_to].c;
            
            while(cur_r >= 0 && cur_r < r && cur_c >= 0 && cur_c < c){
                if(room[cur_r][cur_c] == 6){
                    break;
                }
                blind_now[cur_r][cur_c] = true;
                cur_r += way[way_to].r;
                cur_c += way[way_to].c;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(blind_now[i][j] == false){
                cur_res += 1;
            }
        }
    }
    if(res == -1 || res > cur_res){
        res = cur_res;
    }
}

void cctv_comb(int cctv_idx,int cctv_num,vector<pair<int,pair<int,int>>> &cctv_list){
    if(cctv_idx == cctv_num){
        checking_room(cctv_num);
        return;
    } // base case
    int cctv_kind = cctv_list[cctv_idx].first;
    int cctv_r = cctv_list[cctv_idx].second.first;
    int cctv_c = cctv_list[cctv_idx].second.second;

    if(cctv_kind == 1){
        for(int i=0;i<4;i++){
            cctv_case.push_back(make_pair(i,make_pair(cctv_r,cctv_c)));
            cctv_comb(cctv_idx+1,cctv_num,cctv_list);
            cctv_case.pop_back();
        }
    } // 0,1,2,3
    else if(cctv_kind == 2){
        for(int i=4;i<6;i++){
            cctv_case.push_back(make_pair(i,make_pair(cctv_r,cctv_c)));
            cctv_comb(cctv_idx+1,cctv_num,cctv_list);
            cctv_case.pop_back();
        }
    } // 4,5
    else if(cctv_kind == 3){
        for(int i=6;i<10;i++){
            cctv_case.push_back(make_pair(i,make_pair(cctv_r,cctv_c)));
            cctv_comb(cctv_idx+1,cctv_num,cctv_list);
            cctv_case.pop_back();
        }
    } // 6,7,8,9
    else if(cctv_kind == 4){
        for(int i=10;i<14;i++){
            cctv_case.push_back(make_pair(i,make_pair(cctv_r,cctv_c)));
            cctv_comb(cctv_idx+1,cctv_num,cctv_list);
            cctv_case.pop_back();
        }
    } // 10,11,12,13
    else{
        cctv_case.push_back(make_pair(14,make_pair(cctv_r,cctv_c)));
        cctv_comb(cctv_idx+1,cctv_num,cctv_list);
        cctv_case.pop_back();
    } // 12
}

int main(){
    vector<pair<int,pair<int,int>>> cctv_list;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&room[i][j]);
            if(room[i][j] >= 1 && room[i][j] <= 5){
                cctv_list.push_back(make_pair(room[i][j],make_pair(i,j)));
                blind[i][j] = true;
            } // cctv
            else if(room[i][j] == 6){
                blind[i][j] = true;
            }
        }
    }
    int size = cctv_list.size();
    cctv_comb(0,size,cctv_list);
    printf("%d\n",res);

    return 0;
}