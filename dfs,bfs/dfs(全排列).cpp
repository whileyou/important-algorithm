#include <bits/stdc++.h>
using namespace std;
int n,vis[100000],a[100000];
void dfs(int x)
{
	if(x>n){              //所有数找完则输出 
		for(int i=1;i<=n;i++);
		cout<<setw(5)<<a[i];
		cout<<endl;
	}
	for(int i=1;i<=n;i++)    //该循环保证先找小再找大，且找过后的数返回上一层时因为i++将被跳过，只有返回上上层时才刚好被加入，且因其vis被清可选(仍满足字典序) 
	{
		if(!vis[i])        //未找过,则选入 
		{
			a[x]=i;        //存数 
			vis[i]=1;      //标记找过 
			dfs(x+1);      //dfs找下一个数,下一层还有for循化,相当于可任意选未选过的数(一般剩余最小) 
			vis[i]=0;      //回溯：重新找另一个数以达全排列 
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
