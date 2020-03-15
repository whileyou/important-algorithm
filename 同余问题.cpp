#include <bits/stdc++.h>    //川大新生赛(欧拉筛) 
using namespace std;
long long f(int n)
{
	long long ans=1,s=0;
	for(int i=2;i<=n;i++)
	{
		int j;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) break;
		}
		if(j>sqrt(i)) 
		{
			ans=1;
			for(int k=2;k<=i;k++)
			{
				ans*=k;
			}
			s+=ans;
		}
	}
	return s;
}
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
	{
		cin>>n,cin>>p;
		if(n>=25) n=24;
		cout<<f(n)%p<<endl;
	}
	return 0;
}
