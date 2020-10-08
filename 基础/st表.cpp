//https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using namespace std;
const int maxn=100001;
//stmax[i][j]:[i,i+2^j-1]范围内的最大值 
int stmax[maxn][30],a[maxn],n,m;

//预处理st表，求其值 
//dp思想 
//stmax[i][j]=max([i][i+2^(j-1)-1],[i+2^(j-1)][i+2^j-1])=max(stmax[i][j-1],stmax[i+2^(j-1)][j-1])
void init()		//O(nlogn)
{
	for(int i=n;i>=1;i--){
		for(int j=0;i+(1<<j)-1<=n;j++){
			if(j==0) stmax[i][j]=a[i];
			else stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
		}
	}
}

//询问答案 
//return max(stmax[l][log2(r-l+1)],stmax[r-2^log2(r-l+1)+1][log2(r-l+1)])	//ps:右边的stmax前后同时用log2可消掉log2计算精度的影响，右端结果最后必是r 
//相当于 
//return max([l][l+2^t-1],[r-2^t+1][r]) 	ps:t=log2(r-l+1)
//若t精准计算则有 
//return max([l][r],[l][r])
//否则造成相应偏差 
//即 
//return max([l][r-x],[l+x][r])		ps:x为误差 
int ask(int l,int r)
{
	int x=log2(r-l+1);
	return max(stmax[l][x],stmax[r-(1<<x)+1][x]);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	//建立st表 
	init();
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",ask(l,r));
	}
	return 0;
}

