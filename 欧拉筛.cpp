#include <bits/stdc++.h>  //����n�������1-n�������� 
using namespace std;
long long prime[100000000],p[100000000],cnt;
void f(int n)       //ŷ��ɸ 
{
	for(long long i=2;i<=n;i++)          //ʱ�临�Ӷ�(O(n)) 
	{
		if(!p[i])
		{
			prime[cnt++]=i;
		}
		for(long long j=0;j<cnt&&i*prime[j]<=n;j++)	
		{
			p[i*prime[j]]=1;            //����2�������ֽܷ��һ������������,�Դ�ɸ������ 
			if(i%prime[j]==0) break;   //��֤����С����������һ�����ɸ��i 
		}
	}
}
int main()
{
	long long n;
	cin>>n;
	f(n);
	for(int i=0;i<cnt;i++)
	{
		cout<<prime[i]<<endl;
	}
	return 0;
}
