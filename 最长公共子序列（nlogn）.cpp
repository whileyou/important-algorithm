#include <bits/stdc++.h>	//LCSת����LIS���� O(nlogn)
using namespace std;		//���P1439 
int n,x,a[100001],f[100001],go[100001],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);f[x]=i;	//��������λ�õ�ӳ�佨�� 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);a[i]=f[x];	//ӳ��Ӧ�� 
	}
	//��a�����������Ϊ�����������
	for(int i=1;i<=n;i++)
	{
		if(a[i]>go[ans]) go[++ans]=a[i];
		else go[lower_bound(go,go+ans,a[i])-go]=a[i];
	}
	printf("%d",ans);
	return 0;
}
