#include <bits/stdc++.h>
using namespace std;  //¼ÆËã2^100
int a[1000000],len;
int main()
{
	a[0]=2;len=1;
	for(int i=2;i<=100;i++)
	{
		int m=0;
		for(int j=0;j<len;j++)
		{
			a[j]=a[j]*2+m;   //m±í½øÎ» 
			m=0;
			if(j==len-1&&a[j]>=10) len++;
			if(a[j]>=10)
			{
				m=a[j]/10;a[j]=a[j]%10;
			}
		}
	}
	for(int i=len-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
