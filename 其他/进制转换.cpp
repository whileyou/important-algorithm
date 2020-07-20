#include <stdio.h>
#include <math.h>
char A[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void p(long long n,long long r)
{
	if(n>=r) p(n/r,r);
	printf("%c",A[n%r]);
}
int main()
{
	long long n,r;
	while(scanf("%lld %lld",&n,&r)!=EOF)
	{
		if(n<0) printf("-");
		n=fabs(n);
		p(n,r);
		printf("\n");
	}
	return 0;
}
