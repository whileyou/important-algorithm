#include <iostream>
using namespace std;    //数学表达式:a^b 

long long qpow(int a,int b) //普通(未取余，数不够大时) 
{
	long long ans=1,t=a;
	while(b>0)
	{
		if(b&1) ans*=t;
		t*=t;
		b>>=1;     //等价于b=b>>1 (b右移1位) 
	}
	return ans;
}

long long qpow(int a,int b,int c)    //c表示取余的(适用大数) 
{
	long long ans=1,t=a;
	while(b>0)
	{
		if(b&1) ans*=t;
		ans%=c;
		t*=t;
		t%=c;
		b>>=1;
	}
	return ans%c;
}

int main()
{
	int a,b,c;
	cin>>a,cin>>b,cin>>c;
	cout<<qpow(a,b,c);
	return 0;
}
