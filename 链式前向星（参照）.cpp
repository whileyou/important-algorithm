#include <bits/stdc++.h>	//�������� 
using namespace std;		//���P4017		bfs+���仯 
int n,m,head[5001],cal[5001],know[5001],x1,x2,ans,mod=80112002;
queue<int> q;
struct edge{		//��ʽǰ���� 
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
	for(int i=1;i<=n;i++) if(!cal[i]) q.push(i),x1++;	//���д洢�����Ϣ 
	while(!q.empty())	//x1������һ���Ľ������x2������һ���Ľ���� 
	{
		while(x1--)
		{
			for(int i=head[q.front()],s=q.front();i;i=edge[i].go)	//�������ڽ�� 
			{
				know[edge[i].to]+=(know[s]==0?1:know[s]);know[edge[i].to]%=mod;
				cal[edge[i].to]--;
				//���Ϊ0ʱ���� 
				if(!cal[edge[i].to]&&head[edge[i].to]) q.push(edge[i].to),x2++;
				//����Ϊ0�Ҽ������ʱ����ans�Ӵ� 
				if(!head[edge[i].to]&&!cal[edge[i].to]) ans=(ans+(know[edge[i].to]==0?(know[s]==0?1:know[s]):know[edge[i].to]))%mod;
			}
			q.pop();
		}
		x1=x2;x2=0;
	}
	printf("%d",ans);
	return 0;
}

