//https://vjudge.net/contest/381844#problem/F
//F题 
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
int t,e,f,n,w[501],v[501];
int dp[10001][501];
char jud[10001][501];
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&e,&f,&n);
		f=f-e;
		//重置 
		for(int i=0;i<=f;i++)
		for(int j=0;j<=n;j++)
		dp[i][j]=jud[i][j]=0;
		for(int i=1;i<=n;i++) scanf("%d %d",&v[i],&w[i]);
		for(int i=1;i<=f;i++){
			for(int j=1;j<=n;j++){
				//选与不选都能恰好装满，选取值最小的 
				if((i-w[j]>=0&&(jud[i-w[j]][j]||i-w[j]==0))&&jud[i][j-1]){
					dp[i][j]=min(dp[i][j-1],dp[i-w[j]][j]+v[j]);
					jud[i][j]=1;
				}
				//下面的两种情况都只有一种成立，被迫选择 
				else if((i-w[j]>=0&&(jud[i-w[j]][j]||i-w[j]==0))){
					dp[i][j]=dp[i-w[j]][j]+v[j];
					jud[i][j]=1;
				}
				else if(jud[i][j-1]){
					dp[i][j]=dp[i][j-1];
					jud[i][j]=1;
				}
				//都不满足，不用执行，还是为0 
			}
		}
		if(!dp[f][n]) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f][n]);
	}
	return 0;
} 
