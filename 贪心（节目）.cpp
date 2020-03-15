#include <stdio.h>
int main()                             //贪心（节目时间安排）|策略：每次找节目时间结束最早者，但开始时间不能早于上一节目 
{
	int n,A[100][2],t,k,i,j,z=0,t1,a,n1;
	while(scanf("%d",&n)!=EOF&&n)
	{
		i=0;
		t=t1=100,z=0;
		n1=n;
		while(n1--)
		{
			scanf("%d %d",&A[i][0],&A[i][1]);
			if(t>A[i][1]) t=A[i][1];
			i++;
		}
		while(1)
		{
			a=0;
			for(i=0;i<n;i++)
			{
				if(A[i][0]>=t)            //t表示结束时间 ,再找出结束时间最短的 
				{
					if(t1>=A[i][1]) 
					{
						t1=A[i][1];      //注意比较方式，用大求最小的，但是上一部分是最小的，不可能大于，需要重置！！ 
						a=1;
					}
				}
			}
			z++;
			t=t1;
			t1=100;
			if(a==0) break;
		}
		printf("%d\n",z);
	}
	return 0;
}
