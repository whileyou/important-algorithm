#include <bits/stdc++.h>
using namespace std;
string s;
long long charge(int sx,int e) //sx:��ʼλ��,e:����λ��   --->�ַ���ת���� 
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
	cout<<charge(1,5)<<endl;   //---->���ַ�����2���ַ�����6���ַ�ת��������� 
	return 0;
}
