#include <bits/stdc++.h>	//ѧϰ��ַ:https://blog.csdn.net/dreamtrue1101/article/details/83818937 
using namespace std;		//�����������(LIS) O(nlongn)�㷨--->̰�� + ���ֲ���
int a[100001],go[100001],ans;	//go[i]:a���г���Ϊi��ĩβԪ��ֵ(�ж��ֽ��ʱ,ȡ��С��) 
void search(int l,int r,int x,int &po)		//���ֲ���O(logn)--->go���� 
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
		if(a[i]>go[ans]) go[++ans]=a[i];	//��¼ĩβֵ 
		else	//���Ҳ�����go[po],ʹĩβֵ��С (go[l]<go[po]<go[r],l==r-1) 
		{
			int po=0;
			search(0,ans,a[i],po);
			if(po) go[po]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
