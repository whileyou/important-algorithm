//http://acm.hdu.edu.cn/showproblem.php?pid=3746
//���ģ����next���飨ǰi���ַ��������ǰ��׺���ȣ� 
#include <bits/stdc++.h>
using namespace std;
const int maxn=100001;
int t,len;
char a[maxn];
int ne[maxn];	//ne[i]:�ַ���0~i�������ǰ��׺���� 
void getne()
{
	//��iö�ٺ�׺��j��������׺��ͬ��ǰ׺ 
	for(int i=1,j=0;i<len;i++){
		while(a[i]!=a[j]&&j) j=ne[j-1];	//���������ǰ��׺ 
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
		int minx=len-ne[len-1];		//����Сѭ���ڳ��� 
		if(len%minx==0&&len!=minx) printf("0\n");
		else printf("%d\n",(len/minx+1)*minx-len);
	}
	return 0;
}
