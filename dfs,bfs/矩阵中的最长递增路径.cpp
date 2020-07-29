//题目：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/ 

#include <bits/stdc++.h>
using namespace std;
int n,m,dir[4][2]={0,1, 1,0, 0,-1, -1,0},vis[2000][2000],know[2000][2000],cnt;
void dfs(int x,int y,vector<vector<int>>&  matrix)
{
	vis[x][y]=1;
	int jud=0;
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0],yy=y+dir[i][1];
		//可走 
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&matrix[x][y]<matrix[xx][yy]){
			jud=1;
			//走路 
			if(!vis[xx][yy]) dfs(xx,yy,matrix);
			//回溯时赋值 
			if(know[xx][yy]) know[x][y]=max(know[x][y],know[xx][yy]+1),cnt=max(know[x][y],cnt);
		}
	}
	//走到尽头处（无路可走时），路长为1 
	if(!jud) know[x][y]=1,cnt=max(know[x][y],cnt);
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
	n=matrix.size();
	if(n==0) return 0;
	m=matrix[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]) dfs(i,j,matrix);
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d",&n,&m);
	vector<vector<int>> x;
	for(int i=0;i<n;i++){
		vector<int> a;
		for(int j=0;j<m;j++){
			int b;
			scanf("%d",&b);
			a.push_back(b);
		}
		x.push_back(a);
	}
	
	printf("%d\n\n",longestIncreasingPath(x));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<know[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
