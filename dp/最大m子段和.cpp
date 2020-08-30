//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1024 
//思路：dp+滚动数组+记忆化
//时间复杂度：O(n*m)
 
#include <bits/stdc++.h>
using namespace std;
//将长度为n的序列分割成不重叠的m段，求m段的最大和 
//dp[i][j]:前i个数(子段必含第i个数)分为j段的最大和 
//dp方程：
//dp[i][j]=max(dp[i-1][j]+a[i],dp[k][j-1]+a[i]) k->[j-1,i-1]
//dp为a[i]与第j段为一段或a[i]单独一段的最大值 
//用滚动数组优化空间复杂度，记忆化dp[k][j-1]最大值即可 
#define ll long long
ll m,n,a[1000001],dp[1000001],know[1000001],know_new[1000001],ans;//
//know[i]:前i个数的最大dp值 
int main()
{
	while(~scanf("%lld %lld",&m,&n)){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		//注意滚动数组将j当一行需将j作外循环，因为执行完外循环才是一层 
		for(int j=1;j<=m;j++){
			for(int i=j;i<=n;i++){
				//j==1时选know[i-1]与实际冲突（i-1<j） 
				if(j==1) dp[i]=max(dp[i-1]+a[i],a[i]);
				else dp[i]=max(dp[i-1],know[i-1])+a[i];
				//第一次出现符合情况答案直接赋值 
				if(i==j&&j==m) ans=dp[i];
				else ans=max(ans,dp[i]);
				//情况不与实际冲突才更新 
				if(i>=j){
					//i==j时选know_new[i-1]与实际冲突 
					if(i==j) know_new[i]=dp[i];
					else know_new[i]=max(know_new[i-1],dp[i]);
				}
			}
			//记忆化更新 
			for(int i=0;i<=n;i++) know[i]=know_new[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
