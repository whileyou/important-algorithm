#include <bits/stdc++.h>
using namespace std;
int pre[10001];
int find(int x)	//查询根节点 
{
	if(!pre[x]||pre[x]==x) return x;	//注意自己连接自己的情况 
	return pre[x]=find(pre[x]);	//路径压缩算法：将find(pre[x])修改为pre[x]=find(pre[x])
								//				即令上一级等于根节点，最终达到压缩效果 
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>z>>x>>y;
		int prex=find(x),prey=find(y);
		if(z==1)
		{
			if(!prex) pre[x]=prey;
			else if(!prey) pre[y]=prex;
			else pre[prex]=prey;
		}
		else
		{
			if(prex==prey) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
} 
