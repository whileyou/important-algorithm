#include <bits/stdc++.h>	//LCS转换成LIS问题 O(nlogn)
using namespace std;		//洛谷P1439 
int n,x,a[100001],f[100001],go[100001],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);f[x]=i;	//将该序列位置的映射建出 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);a[i]=f[x];	//映射应用 
	}
	//求a最长上升子序列为最长公共子序列
	for(int i=1;i<=n;i++)
	{
		if(a[i]>go[ans]) go[++ans]=a[i];
		else go[lower_bound(go,go+ans,a[i])-go]=a[i];
	}
	printf("%d",ans);
	return 0;
}
