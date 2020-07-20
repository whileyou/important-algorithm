#include <bits/stdc++.h>  //输入n，输出从1-n所有素数 
using namespace std;
long long prime[100000000],p[100000000],cnt;
void f(int n)       //欧拉筛 
{
	for(long long i=2;i<=n;i++)          //时间复杂度(O(n)) 
	{
		if(!p[i])
		{
			prime[cnt++]=i;
		}
		for(long long j=0;j<cnt&&i*prime[j]<=n;j++)	
		{
			p[i*prime[j]]=1;            //大于2合数都能分解成一质数与合数相乘,以此筛掉合数 
			if(i%prime[j]==0) break;   //保证是最小质因数与另一数相乘筛掉i 
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
