#include <iostream>
#include <cstdio>
#include <queue>
#include <stdlib.h>
#include <cstring>
using namespace std;
char mapp[110][110];
void dfs(int x,int y)
{
    mapp[x][y]='*';
    int dir[][2]={-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,1,1,-1};
    for(int i = 0;i < 8;i++)
    {
        int nx=x,ny=y;
        nx+=dir[i][0];
        ny+=dir[i][1];
        if(mapp[nx][ny]=='@')
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&m)
    {
        int ans=0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                scanf(" %c",&mapp[i][j]);
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++)
            {
                if(mapp[i][j]=='@')
                {
                    mapp[i][j]='*';
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
