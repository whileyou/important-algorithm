//题目：https://leetcode-cn.com/problems/split-array-largest-sum/ 

#include <bits/stdc++.h>
using namespace std;
double dp[1001][51],sum[1001];	//dp[i][j]：前i个数划分j段的最大和的最小值 
int splitArray(vector<int>& nums, int m) {
	int len=nums.size();
	for(int i=1;i<=len;i++) sum[i]=sum[i-1]+nums[i-1];
	for(int i=1;i<=len;i++){
		for(int j=1;j<=i&&j<=m;j++){
			//状态转移方程 
			//dp[i][j]=min(max(dp[k][j-1],sub(k+1,i)));	(j>1)
			double got=0;
			if(j==1) got=sum[i];
			else
			for(int k=j-1;k<i;k++){
				if(k==j-1) got=max(dp[k][j-1],sum[i]-sum[k]);
				else got=min(got,max(dp[k][j-1],sum[i]-sum[k]));
			}
			dp[i][j]=got;
		}
	}
	return (int)dp[len][m];
}
int main()
{
	int n,m;
	vector<int> nums;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		nums.push_back(a);
	}
	printf("%d\n",splitArray(nums,m));
	return 0;
}

/*
14 8
10 5 13 4 8 4 5 11 14 9 16 10 20 8

25
*/
