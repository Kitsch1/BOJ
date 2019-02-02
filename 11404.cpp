#include <cstdio>

int dist[101][101];

int main(){
    int city,bus;
    scanf("%d",&city);
    scanf("%d",&bus);

    for(int r=1;r<=city;r++){
        for(int c=1;c<=city;c++){
            if(r == c) dist[r][c] = 0;
            else dist[r][c] = 987654321;
        }
    }
    for(int i=0;i<bus;i++){
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        if(dist[from][to] > cost) dist[from][to] = cost;
    }
    for(int k=1;k<=city;k++){
        for(int r=1;r<=city;r++){
            for(int c=1;c<=city;c++){
                if(dist[r][c] > dist[r][k] + dist[k][c]){
                    dist[r][c] = dist[r][k] + dist[k][c];
                }
            }
        }
    }
    for(int r=1;r<=city;r++){
        for(int c=1;c<=city;c++){
            if(dist[r][c] == 987654321) printf("0 ");
            else printf("%d ",dist[r][c]);
        }
        printf("\n");
    }

    return 0;
}