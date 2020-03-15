#include <bits/stdc++.h>		// 洛谷P3375 
using namespace std;			// 算法学习网址：https://www.bilibili.com/video/av3246487?from=search&seid=17199625369609405904 
char s1[1000001],s2[1000001];  //主串 子串 
int next[1000001];  //临时数组 
int main()
{
	scanf("%s %s",s1,s2);
	int str1=strlen(s1),str2=strlen(s2);	//注意先存储其长度，反复调用strlen函数，会在循环内使时间复杂度暴涨 
	//构建临时数组
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
			if(l) l=next[l-1],r--;  //r移动暂停 
			else next[r]=0;
		}
	}
	//匹配阶段 
	for(int i=0,j=0;i<str1;i++)
	{
		if(s1[i]==s2[j])
		{
			if(j==str2-1)			//匹配成功 
			{
				printf("%d\n",i-str2+2);
				j=next[j];
			}
			else j++;
		}
		else if(j) j=next[j-1],i--;			//匹配失败利用临时数组返回 (i--使之暂停)
	} 
	//临时数组打印 
	for(int i=0;i<str2;i++)
	{
		if(i) printf(" ");
		printf("%d",next[i]);
	}
	return 0;
}
