#include <bits/stdc++.h>
using namespace std;
int dp[100][100],w[100],v[100];      //��dp[i][j]��ά���鴢�����������Ž⣬ֱ���㵽���һ���õ�ǰ���Ž� 
int main()
{
	int n,bag;
	cout<<"��Ʒ������"<<endl;
	cin>>n; 
	for(int i=1;i<=n;i++)    //Ԥ��0ֵ����������ʱֱ�ӷ��뱳�� 
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cout<<"������С:"<<endl;
	cin>>bag;
	for(int i=1;i<=n;i++)               //����ǰi����Ʒ���Ž� 
	{
		for(int j=0;j<=bag;j++)      //����ǰj���ݻ����Ž� (֮���Լ���ÿ���ݻ����Ƿ�װ��i����Ϊ�˸�������ܸ�������ĵ���) 
		{
			if(j<w[i]) dp[i][j]=dp[i-1][j];   //�ݻ�����������װ 
			else
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]); //�жϱ����ݻ�Ϊjʱװ���ǲ�װ,j-w[i]������װ���ݻ������Ž�(״̬ת�Ʒ���) 
		}
	}
	cout<<dp[n][bag]<<endl;
	return 0;
} 
