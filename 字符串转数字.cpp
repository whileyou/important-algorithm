#include <bits/stdc++.h>
using namespace std;
string s;
long long charge(int sx,int e) //sx:开始位置,e:结束位置   --->字符串转数字 
{
	long long ans=0;
	for(int i=sx;i<=e;i++)
	{
		ans=(s[i]-'0')+ans*10;
	}
	return ans;
}
int main()
{
	cin>>s;
	cout<<charge(1,5)<<endl;   //---->将字符串第2个字符至第6个字符转成数字输出 
	return 0;
}
