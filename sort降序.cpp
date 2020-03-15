#include <bits/stdc++.h>
using namespace std;
long long A[1000000],n;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		cin>>A[i];
		sort(A,A+n,cmp);
		for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
		cout<<endl;
	}
	return 0;
} 
