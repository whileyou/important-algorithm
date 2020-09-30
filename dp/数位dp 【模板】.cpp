//https://www.luogu.com.cn/problem/P2657
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,num[20];	//num:记录数位 
ll dp[20][20];	//dp[i][j]:在第i位数字时，其前一位大小为j时的合法数（第i位无限制时） 

//从高位到低位搜索合法数量 
ll dfs(int pos,int pre,bool lead,bool lim)	//pos:记录当前位置 pre:记录上一位数字 lead:前导是否为0 lim:是否有上界限制 
{
	if(pos<=0) return 1;	//搜到底返回 
	if(!lim&&!lead&&dp[pos][pre]) return dp[pos][pre];	//剪枝 
	int up=9;
	if(lim) up=num[pos]; //更新为真正的上界 
	ll tmp=0;
	for(int i=0;i<=up;i++){
		//搜索当前位为i时的值 
		if(abs(i-pre)>=2||lead){	//若合法才加上 
			tmp+=dfs(pos-1,i,lead&&i==0,lim&&i==up);
		}
	}
	//对该位进行记录 
	//pos位无限制，无前导零，即无限制选，否则要搜索得所需答案 
	if(!lim&&!lead) dp[pos][pre]=tmp;
	return tmp;
}

ll sol(int x)
{
	memset(dp,0,sizeof(dp));
	int tmpx=x,pos=0;
	while(tmpx){
		num[++pos]=tmpx%10;	//从低到高进行记录 
		tmpx/=10;
	}
	ll ans=dfs(pos,-1,true,true);
	return ans;
}

int main()
{
	scanf("%d %d",&a,&b);
	printf("%lld",sol(b)-sol(a-1));
	return 0;
}
