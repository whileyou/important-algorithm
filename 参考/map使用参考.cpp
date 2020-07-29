//https://ac.nowcoder.com/acm/contest/5773
//D.二分 
#include <bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
int n,ans,cal;
struct vis{
	int x;
	char c;
}vis[100001];
map<int,int> m;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %c",&vis[i].x,&vis[i].c);
		if(vis[i].c=='.') m[vis[i].x]++,m[vis[i].x+1]--;
		else if(vis[i].c=='+') m[-inf]++,m[vis[i].x]--;
		else if(vis[i].c=='-') m[inf]--,m[vis[i].x+1]++;
	}
	for(auto x:m){
		cal+=x.second;
		ans=max(cal,ans);
	}
	printf("%d",ans);
	return 0;
}
