//题目：https://leetcode-cn.com/problems/longest-palindromic-substring/ 
//O(n^2) 

#include <bits/stdc++.h>
using namespace std;
//状态转移方程：
//if(jud) dp[i][j]=dp[i+1][j-1]+2;--->jud:s[i]与s[j]是否相等，且中间部分是回文串 
int dp[1001][1001],cnt,s1,s2;	//dp[i][j]:i开始到j结尾的回文长度 
string longestPalindrome(string s) {
	int n=s.length();
	for(int j=0;j<n;j++){
		for(int i=j;i>=0;i--){
			if(i==j) dp[i][j]=1;
			else if(s[i]==s[j]&&(i+1>j-1||dp[i+1][j-1]))
			dp[i][j]=dp[i+1][j-1]+2;
			//都不满足长度即为0 
			//答案处理 
			if(cnt<dp[i][j]) cnt=dp[i][j],s1=i,s2=j;
		}
	}
	string ans;
	for(int i=s1;i<=s2;i++) ans.push_back(s[i]);
	return ans;
}
int main()
{
	string s;
	cin>>s;
	cout<<longestPalindrome(s);
	return 0;
}
