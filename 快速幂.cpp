#include <iostream>
using namespace std;    //��ѧ���ʽ:a^b 

long long qpow(int a,int b) //��ͨ(δȡ�࣬��������ʱ) 
{
	long long ans=1,t=a;
	while(b>0)
	{
		if(b&1) ans*=t;
		t*=t;
		b>>=1;     //�ȼ���b=b>>1 (b����1λ) 
	}
	return ans;
}

long long qpow(int a,int b,int c)    //c��ʾȡ���(���ô���) 
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
