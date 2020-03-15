#include <stdio.h>
#include <math.h>
long long n,m;
int main()
{
	long long s,a1;                            //m=(1+i)*i/2----->i*i+i-2*m=0
	while(~scanf("%lld %lld",&n,&m)&&(n||m))  //s=(a1+an)*n/2=(a1+a1+(n-1))*n/2
	{
		for(long long i=(-1+sqrt(1+8*m))/2;i>=1;i--)      //±éÀú¸öÊýn 
		{
			long double a=(long double)2.0*m/i+1-i;
			a=a/2;
			a1=a;
			if(a==a1&&a>0) printf("[%lld,%lld]\n",(long long)a,(long long)a+i-1);
		}
		printf("\n");
	}
	return 0;
}
