#include <bits/stdc++.h>
using namespace std;
char a[100001],*p,*q;   //abcababec
int vis[200];  //ͳ����ĸ���ִ��� 
int main()
{
	int n,all=0,ans=100000;
	cin>>n>>a;
	//ͳ��������ĸ����
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
