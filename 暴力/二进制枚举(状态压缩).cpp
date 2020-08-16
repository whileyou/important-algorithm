//题目：https://ac.nowcoder.com/acm/contest/profile/900654179/practice-coding?search=200190 
//思路：二进制枚举(状态压缩) 
//时间复杂度：O(n^2*2^m) 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,mapp[20][20],vis[20],h[20],l[20],hx[20],ans;	//h\l:行和，列和 
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mapp[i][j]);
			h[i]+=mapp[i][j];
			l[j]+=mapp[i][j];
		}
	}
	for(int i=0;i<=(1<<m)-1;i++){
		int cnt=0,cal=0;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++) hx[j]=h[j];
		for(int j=0;j<m;j++){
			int x=(1<<j);
			if(i&x) cnt++,vis[j]=1;
		}
		if(cnt<=k){
			int kx=k-cnt;
			for(int j=0;j<m;j++){
				if(vis[j]){
					cal+=l[j];
					for(int z=0;z<n;z++) hx[z]-=mapp[z][j];
				}
			}
			sort(hx,hx+n,greater<int>());
			for(int j=0;j<kx&&j<n;j++) cal+=hx[j];
			ans=max(ans,cal);
		}
	}
	printf("%d",ans);
	return 0;
}
