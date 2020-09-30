//https://www.luogu.com.cn/problem/P1352
//该题模型一定形成一颗树 
#include <bits/stdc++.h>
using namespace std;
const int maxn=6001;
int n,dp[maxn][2],val[maxn],head[maxn],vis[maxn];
//dp[i][0]:第i个结点不来时的最大值（只含i和i的所有子树） 
//dp[i][1]:第i个结点来时的最大值（只含i和i的所有子树） 
//dp[i][0]+=max(dp[j][0],dp[j][1])
//dp[i][1]+=dp[j][0]		(j表i的子结点)
struct edge{	//链式前向星存储 
	int to,next;
}edge[maxn];

//树形dp 
void tree_dp(int root)
{
	//x表边号 
	if(head[root]==0) dp[root][1]=val[root];	//给叶节点赋值 
	else
	for(int x=head[root];x;x=edge[x].next){	//搜该结点的所有子结点 
		if(edge[x].to) tree_dp(edge[x].to);	//向下搜子结点（从叶节点开始dp） 
		//dp开始 
		dp[root][0]+=max(dp[edge[x].to][0],dp[edge[x].to][1]);
		if(dp[root][1]==0) dp[root][1]=val[root];	//首次选，进行赋值 
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
		//建立上下级关系，b为a上司 
		edge[i].to=a;	//第i号边指向a 
		edge[i].next=head[b];	//第i号边指向第一个出发指向边的编号 
		head[b]=i;	//第一个出发指向边的编号变为i（即新增） 
		vis[a]=1;
	}
	//查找到根节点 
	int root;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			root=i;
			break;
		}
	}
	//进行树形dp 
	tree_dp(root);
	printf("%d",max(dp[root][0],dp[root][1]));
	return 0;
}

