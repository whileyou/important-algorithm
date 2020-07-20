#include <bits/stdc++.h>
using namespace std;        //Cn^m
long long f(int n,int m)
{
	long long ans=1;
	for(int i=n;n-i<m;i--)
	{
		ans*=i;
	}
	for(int i=1;i<=m;i++)
	{
		ans/=i;
	}
	return ans;
}
int main()
{
	int n,m;
	while(1)
	{
	cin>>n,cin>>m;
	cout<<f(n,m)<<endl;
	}
	return 0;
}
