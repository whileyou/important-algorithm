#include <bits/stdc++.h>
using namespace std;
char a[100001],*p,*q;   //abcababec
int vis[200];  //统计字母出现次数 
int main()
{
	int n,all=0,ans=100000;
	cin>>n>>a;
	//统计所有字母种类
	for(int i=0;i<n;i++)
	{
		if(!vis[a[i]]) all++;
		vis[a[i]]++;
	}
	memset(vis,0,sizeof(vis));
	int l=0,r=0,part=0;
	while(r<n)
	{
		if(vis[a[r]]==0) part++;
		vis[a[r++]]++;
		while(part==all)
		{
			vis[a[l]]--;
			if(!vis[a[l]]) part--;
			if(ans>r-l) ans=r-l;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
