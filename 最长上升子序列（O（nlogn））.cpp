#include <bits/stdc++.h>	//学习网址:https://blog.csdn.net/dreamtrue1101/article/details/83818937 
using namespace std;		//最长上升子序列(LIS) O(nlongn)算法--->贪心 + 二分查找
int a[100001],go[100001],ans;	//go[i]:a序列长度为i的末尾元素值(有多种结果时,取最小的) 
void search(int l,int r,int x,int &po)		//二分查找O(logn)--->go有序 
{
	if(l==r-1&&go[l]<x&&go[r]>x)
	{
		po=r;return;
	}
	else if(go[l]>=x||go[r]<=x) return;
	int m=(l+r)/2;
	if(x>go[m]) search(m,r,x,po);
	else search(l,m,x,po);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	go[1]=a[1];ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>go[ans]) go[++ans]=a[i];	//记录末尾值 
		else	//查找并更新go[po],使末尾值最小 (go[l]<go[po]<go[r],l==r-1) 
		{
			int po=0;
			search(0,ans,a[i],po);
			if(po) go[po]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
