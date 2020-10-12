//http://acm.hdu.edu.cn/showproblem.php?pid=3746
//核心：求解next数组（前i个字符的最长公共前后缀长度） 
#include <bits/stdc++.h>
using namespace std;
const int maxn=100001;
int t,len;
char a[maxn];
int ne[maxn];	//ne[i]:字符串0~i的最长公共前后缀长度 
void getne()
{
	//以i枚举后缀，j代表最长与后缀相同的前缀 
	for(int i=1,j=0;i<len;i++){
		while(a[i]!=a[j]&&j) j=ne[j-1];	//查找最长公共前后缀 
		if(a[i]==a[j]) j++;
		ne[i]=j;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		len=strlen(a);
		getne();
		int minx=len-ne[len-1];		//解最小循环节长度 
		if(len%minx==0&&len!=minx) printf("0\n");
		else printf("%d\n",(len/minx+1)*minx-len);
	}
	return 0;
}
