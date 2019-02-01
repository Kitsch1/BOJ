#include <stdio.h>

int m_first[100][100];
int m_second[100][100];
int m_second_trans[100][100];
int res[100][100];

int main(){
    int n,m,k;
    int a,b,c;

    scanf("%d %d",&n,&m);
    for(a=0;a<n;a++){
        for(b=0;b<m;b++){
            scanf("%d",&m_first[a][b]);
        }
    }
    scanf("%d %d",&m,&k);
    for(a=0;a<m;a++){
        for(b=0;b<k;b++){
            scanf("%d",&m_second[a][b]);
        }
    }

    for(a=0;a<m;a++){
        for(b=0;b<k;b++){
            m_second_trans[b][a] = m_second[a][b];
        }
    }
    for(a=0;a<n;a++){
        for(b=0;b<k;b++){
            for(c=0;c<m;c++){
                res[a][b] += m_first[a][c] * m_second_trans[b][c];
            }
        }
    }
    for(a=0;a<n;a++){
        for(b=0;b<k;b++){
            printf("%d ",res[a][b]);
        }
        printf("\n");
    }


    return 0;
}