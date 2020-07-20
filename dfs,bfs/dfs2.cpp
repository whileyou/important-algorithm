#include <stdio.h>
int B[][2]={-1,0,0,1,1,0,0,-1},C[5][5],A[5][5];
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+B[i][0];
		int ny=y+B[i][1];
		if(nx>=0&&nx<=4&&ny>=0&&ny<=4&&A[nx][ny]==0)
		{
			printf("(%d,%d)\n",nx,ny);
			dfs(nx,ny);
		}
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	dfs(0,0);
	return 0;
} 
