//https://www.luogu.com.cn/problem/P3805
//���ģ����len���飨le[i]:��iΪ�������ĵ�����ĳ��ȣ�ֱ������ 
#include <bits/stdc++.h>
using namespace std;
const int maxn=12000001;
char str[maxn];	//ԭ�ַ��� 
char tmp[maxn<<1];	//ת���ַ��� 
int le[maxn<<1];	//���ĳ������� 
int ans;
//ת���ַ��� 
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
	int len=strlen(tmp),m=0,r=0;	//r:���Ĵ�����ұ߽� m:��Ӧ�Ļ������� 
	//ö��i������le[i] 
	for(int i=0;i<len;i++){
		int j=2*m-i;		//jΪi����m�ĶԳ� 
		if(i<r) le[i]=min(r-i,le[j]);	//iδԽ��ֱ�ӽ�ֵ 
		else le[i]=1;
		while(i-le[i]>=0&&tmp[i-le[i]]==tmp[i+le[i]]) le[i]++;	//����ö�� 
		//����r��m 
		int r_new=i+le[i],m_new=i;
		if(r_new>r) r=r_new,m=m_new;
		ans=max(ans,le[i]-1);	//le[i]-1Ϊԭ�ַ������ĳ��� 
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
