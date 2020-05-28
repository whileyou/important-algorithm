//洛谷P1923 
//快速求第k小数（O(n)） 
//算法思想：快排+随机选取 
#include <bits/stdc++.h>
using namespace std;
#define maxn 5000001
int n,k,a[maxn];
int sol(int x,int y,int k)
{
	if(y>=x){
		int i=x,j=y,got=rand()%(y-x+1)+x;
		swap(a[x],a[got]),got=x;
		while(i<j){
			while(a[j]>=a[got]&&i<j) j--;
			while(a[i]<=a[got]&&i<j) i++;
			swap(a[i],a[j]);
		}
		swap(a[i],a[got]);
		if(i-x+1==k) return a[i];
		else if(i-x+1>k) sol(x,i-1,k);
		else if(i-x+1<k) sol(i+1,y,k-(i-x+1));
	}
}
int main()
{
	srand(time(NULL));
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",sol(1,n,k+1));
	return 0;
}
