//https://www.luogu.com.cn/problem/P3805
//核心：求解len数组（le[i]:以i为回文中心的最长回文长度（直径）） 
#include <bits/stdc++.h>
using namespace std;
const int maxn=12000001;
char str[maxn];	//原字符串 
char tmp[maxn<<1];	//转换字符串 
int le[maxn<<1];	//回文长度数组 
int ans;
//转换字符串 
void init()
{
	int len=strlen(str),cnt=0;
	for(int i=0;i<len;i++){
		tmp[cnt++]='$';
		tmp[cnt++]=str[i];
	}
	tmp[cnt]='$';
}
void getle()
{
	int len=strlen(tmp),m=0,r=0;	//r:回文串最大右边界 m:对应的回文中心 
	//枚举i逐次求解le[i] 
	for(int i=0;i<len;i++){
		int j=2*m-i;		//j为i关于m的对称 
		if(i<r) le[i]=min(r-i,le[j]);	//i未越界直接解值 
		else le[i]=1;
		while(i-le[i]>=0&&tmp[i-le[i]]==tmp[i+le[i]]) le[i]++;	//回文枚举 
		//更新r和m 
		int r_new=i+le[i],m_new=i;
		if(r_new>r) r=r_new,m=m_new;
		ans=max(ans,le[i]-1);	//le[i]-1为原字符串回文长度 
	}
}
int main()
{
	scanf("%s",str);
	init();
	getle();
	printf("%d",ans);
	return 0;
}
