//https://www.luogu.com.cn/problem/P1352
//����ģ��һ���γ�һ���� 
#include <bits/stdc++.h>
using namespace std;
const int maxn=6001;
int n,dp[maxn][2],val[maxn],head[maxn],vis[maxn];
//dp[i][0]:��i����㲻��ʱ�����ֵ��ֻ��i��i������������ 
//dp[i][1]:��i�������ʱ�����ֵ��ֻ��i��i������������ 
//dp[i][0]+=max(dp[j][0],dp[j][1])
//dp[i][1]+=dp[j][0]		(j��i���ӽ��)
struct edge{	//��ʽǰ���Ǵ洢 
	int to,next;
}edge[maxn];

//����dp 
void tree_dp(int root)
{
	//x��ߺ� 
	if(head[root]==0) dp[root][1]=val[root];	//��Ҷ�ڵ㸳ֵ 
	else
	for(int x=head[root];x;x=edge[x].next){	//�Ѹý��������ӽ�� 
		if(edge[x].to) tree_dp(edge[x].to);	//�������ӽ�㣨��Ҷ�ڵ㿪ʼdp�� 
		//dp��ʼ 
		dp[root][0]+=max(dp[edge[x].to][0],dp[edge[x].to][1]);
		if(dp[root][1]==0) dp[root][1]=val[root];	//�״�ѡ�����и�ֵ 
		dp[root][1]+=dp[edge[x].to][0];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		//�������¼���ϵ��bΪa��˾ 
		edge[i].to=a;	//��i�ű�ָ��a 
		edge[i].next=head[b];	//��i�ű�ָ���һ������ָ��ߵı�� 
		head[b]=i;	//��һ������ָ��ߵı�ű�Ϊi���������� 
		vis[a]=1;
	}
	//���ҵ����ڵ� 
	int root;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			root=i;
			break;
		}
	}
	//��������dp 
	tree_dp(root);
	printf("%d",max(dp[root][0],dp[root][1]));
	return 0;
}

