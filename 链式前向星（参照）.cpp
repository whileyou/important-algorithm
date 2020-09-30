#include <bits/stdc++.h>	//拓扑排序 
using namespace std;		//洛谷P4017		bfs+记忆化 
int n,m,head[5001],cal[5001],know[5001],x1,x2,ans,mod=80112002;
queue<int> q;
struct edge{		//链式前向星 
	int to,go;
}edge[500001];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		edge[i].to=b;edge[i].go=head[a];head[a]=i;cal[b]++;
	}
	for(int i=1;i<=n;i++) if(!cal[i]) q.push(i),x1++;	//队列存储结点信息 
	while(!q.empty())	//x1代表这一级的结点数，x2代表下一级的结点数 
	{
		while(x1--)
		{
			for(int i=head[q.front()],s=q.front();i;i=edge[i].go)	//遍历相邻结点 
			{
				know[edge[i].to]+=(know[s]==0?1:know[s]);know[edge[i].to]%=mod;
				cal[edge[i].to]--;
				//入度为0时存入 
				if(!cal[edge[i].to]&&head[edge[i].to]) q.push(edge[i].to),x2++;
				//出度为0且计算完毕时，给ans加答案 
				if(!head[edge[i].to]&&!cal[edge[i].to]) ans=(ans+(know[edge[i].to]==0?(know[s]==0?1:know[s]):know[edge[i].to]))%mod;
			}
			q.pop();
		}
		x1=x2;x2=0;
	}
	printf("%d",ans);
	return 0;
}

