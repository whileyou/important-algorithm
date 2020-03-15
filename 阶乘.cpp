#include <bits/stdc++.h>
#include <string>
using namespace std;
void f(long long n)
{
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%(int)1e5;
	}
	cout<<ans<<endl;
}
int main()
{
	long long n;
	while(1)
	{
		cin>>n;
		f(n);
	}
	return 0;
} 
