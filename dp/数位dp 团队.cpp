//https://www.luogu.com.cn/problem/P2657
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,num[20];	//num:��¼��λ 
ll dp[20][20];	//dp[i][j]:�ڵ�iλ����ʱ����ǰһλ��СΪjʱ�ĺϷ�������iλ������ʱ�� 

//�Ӹ�λ����λ�����Ϸ����� 
ll dfs(int pos,int pre,bool lead,bool lim)	//pos:��¼��ǰλ�� pre:��¼��һλ���� lead:ǰ���Ƿ�Ϊ0 lim:�Ƿ����Ͻ����� 
{
	if(pos<=0) return 1;	//�ѵ��׷��� 
	if(!lim&&!lead&&dp[pos][pre]) return dp[pos][pre];	//��֦ 
	int up=9;
	if(lim) up=num[pos]; //����Ϊ�������Ͻ� 
	ll tmp=0;
	for(int i=0;i<=up;i++){
		//������ǰλΪiʱ��ֵ 
		if(abs(i-pre)>=2||lead){	//���Ϸ��ż��� 
			tmp+=dfs(pos-1,i,lead&&i==0,lim&&i==up);
		}
	}
	//�Ը�λ���м�¼ 
	//posλ�����ƣ���ǰ���㣬��������ѡ������Ҫ����������� 
	if(!lim&&!lead) dp[pos][pre]=tmp;
	return tmp;
}

ll sol(int x)
{
	memset(dp,0,sizeof(dp));
	int tmpx=x,pos=0;
	while(tmpx){
		num[++pos]=tmpx%10;	//�ӵ͵��߽��м�¼ 
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
