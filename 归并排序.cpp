#include <bits/stdc++.h>
using namespace std;
int a[500001],b[500001];
long long ans;
void merge(int start,int mid,int end)
{
	int i=start,j=mid+1,now=0;
	while(i<=mid||j<=end)
	{
		if((j<=end&&i<=mid&&a[i]>a[j])||i>mid)
		{
			b[now++]=a[j];j++;if(i<=mid) ans+=mid-i+1;	//
		}
		else
		{
			b[now++]=a[i];i++;
		}
	}
	int jud=end-start+1;
	for(int i=0;i<jud;i++)
	{
		a[start++]=b[i];
	}
}
void sort(int start,int end)
{
	if(start==end) return;
	int mid=(start+end)/2;
	sort(start,mid);
	sort(mid+1,end);
	merge(start,mid,end);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(0,n-1);
	for(int i=0;i<n;i++) printf("%d\n",a[i]);
	//cout<<ans;
	return 0;
} 
