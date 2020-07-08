#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
ll n,a[1001],dp[1001],ans;	//dp[i]:以a[i]为结尾的最大上升子序列和 
int main()
{
	while(~scanf("%lld",&n)&&n){
		for(int i=0;i<n;i++) scanf("%lld",&a[i]),dp[i]=a[i];	//初始化dp:即为a[i]本身 
		ans=a[0];
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
			}
		}
		for(int i=0;i<n;i++) ans=max(ans,dp[i]);
		printf("%lld\n",ans); 
	}
	return 0;
}
