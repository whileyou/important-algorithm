#include <bits/stdc++.h>      //Âå¹Èp1162 
using namespace std;
int n,map_[32][32],vis[32][32],dir[][2]={1,0,-1,0,0,1,0,-1};
queue<int> xx;
queue<int> yy;
void bfs(int x,int y)
{
	xx.push(x),yy.push(y);
	vis[x][y]=1;
	while(!xx.empty())
	{
		for(int i=0;i<4;i++)
		{
			int tx=xx.front()+dir[i][0],ty=yy.front()+dir[i][1];
			if(tx>=0&&tx<=n+1&&ty>=0&&ty<=n+1&&map_[tx][ty]==0&&!vis[tx][ty])
			{
				vis[tx][ty]=1;
				xx.push(tx),yy.push(ty);
			}
		}
		xx.pop(),yy.pop();
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>map_[i][j];
		}
	}
	bfs(0,0);
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
		if(vis[i][j]==0&&map_[i][j]==0)
		{
			cout<<2;
		}
		else cout<<map_[i][j];
		if (j!=n) cout<<" ";
	}
	cout<<endl;
	}
	return 0;
} 


/*
#include <bits/stdc++.h>   //Âå¹È p1141
using namespace std;
int A[1001][1001],dir[][2]={0,1,0,-1,1,0,-1,0},n,m,s[1001*1001];
int x,y,nx=1,vis[1001][1001];
queue<int> xx,yy;
void bfs(int x,int y)
{
	xx.push(x),yy.push(y);
	vis[x][y]=nx;       //
	s[nx]++;
	while(!xx.empty())
	{
		for(int i=0;i<4;i++)
		{
			int tx=xx.front()+dir[i][1],ty=yy.front()+dir[i][0];        //
			if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!vis[tx][ty]&&A[xx.front()][yy.front()]!=A[tx][ty])   //
			{
				xx.push(tx),yy.push(ty);
				vis[tx][ty]=nx;
				s[nx]++;
			}
		}
		xx.pop(),yy.pop();
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		scanf("%1d",&A[i][j]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(!vis[i][j])
		{
			bfs(i,j);
			nx++;
		}
	}
	while(m--)
	{
		cin>>x>>y;
		cout<<s[vis[x][y]]<<endl;
	}
	return 0;
} 
