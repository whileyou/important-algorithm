#include <stdio.h>
#include <math.h>
int main()
{
	int n,A[100][2];
	while(~scanf("%d",&n)&&n)
	{
		int i=0,n1=n;
		double s=0;
		while(n1--)
		{
			scanf("%d %d",&A[i][0],&A[i][1]);
			i++;
		}
		for(i=0;i<n-1;i++)
		{
			s=s+(A[i+1][0]-A[i][0])*(A[i][1]+A[i+1][1]);
		}
		s=s+(A[0][0]-A[i][0])*(A[0][1]+A[i][1]);
		s=s/2;
		printf("%.3lf\n",fabs(s));
	}
	return 0;
}
