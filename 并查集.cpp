#include <bits/stdc++.h>
using namespace std;
int pre[10001];
int find(int x)	//��ѯ���ڵ� 
{
	if(!pre[x]||pre[x]==x) return x;	//ע���Լ������Լ������ 
	return pre[x]=find(pre[x]);	//·��ѹ���㷨����find(pre[x])�޸�Ϊpre[x]=find(pre[x])
								//				�����������һ�������մﵽѹ��Ч�� 
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
