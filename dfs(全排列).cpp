#include <bits/stdc++.h>
using namespace std;
int n,vis[100000],a[100000];
void dfs(int x)
{
	if(x>n){              //��������������� 
		for(int i=1;i<=n;i++);
		cout<<setw(5)<<a[i];
		cout<<endl;
	}
	for(int i=1;i<=n;i++)    //��ѭ����֤����С���Ҵ����ҹ������������һ��ʱ��Ϊi++����������ֻ�з������ϲ�ʱ�Ÿպñ����룬������vis�����ѡ(�������ֵ���) 
	{
		if(!vis[i])        //δ�ҹ�,��ѡ�� 
		{
			a[x]=i;        //���� 
			vis[i]=1;      //����ҹ� 
			dfs(x+1);      //dfs����һ����,��һ�㻹��forѭ��,�൱�ڿ�����ѡδѡ������(һ��ʣ����С) 
			vis[i]=0;      //���ݣ���������һ�����Դ�ȫ���� 
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
