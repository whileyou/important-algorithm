#include <bits/stdc++.h>		// ���P3375 
using namespace std;			// �㷨ѧϰ��ַ��https://www.bilibili.com/video/av3246487?from=search&seid=17199625369609405904 
char s1[1000001],s2[1000001];  //���� �Ӵ� 
int next[1000001];  //��ʱ���� 
int main()
{
	scanf("%s %s",s1,s2);
	int str1=strlen(s1),str2=strlen(s2);	//ע���ȴ洢�䳤�ȣ���������strlen����������ѭ����ʹʱ�临�Ӷȱ��� 
	//������ʱ����
	int l,r;
	for(l=0,r=1,next[0]=0;r<str2;r++)
	{
		if(s2[l]==s2[r])
		{
			next[r]=l+1;
			l++;
		}
		else
		{
			if(l) l=next[l-1],r--;  //r�ƶ���ͣ 
			else next[r]=0;
		}
	}
	//ƥ��׶� 
	for(int i=0,j=0;i<str1;i++)
	{
		if(s1[i]==s2[j])
		{
			if(j==str2-1)			//ƥ��ɹ� 
			{
				printf("%d\n",i-str2+2);
				j=next[j];
			}
			else j++;
		}
		else if(j) j=next[j-1],i--;			//ƥ��ʧ��������ʱ���鷵�� (i--ʹ֮��ͣ)
	} 
	//��ʱ�����ӡ 
	for(int i=0;i<str2;i++)
	{
		if(i) printf(" ");
		printf("%d",next[i]);
	}
	return 0;
}
