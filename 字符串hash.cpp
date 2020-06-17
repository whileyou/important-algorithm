 #include <bits/stdc++.h>
using namespace std;
char a[1501];
long long base=131,mod=1e9+7,hash[10001],vis[10001],j,ans;
int main()
{
	int n,n1;
	cin>>n;n1=n;
	while(n--)
	{
		cin>>a;
		int i;
		for(i=1;i<=strlen(a);i++)                            //¹«Ê½ 
		hash[i] = ( ( hash[i-1] * base ) + a[i-1] ) % mod ;   //¹«Ê½ 
		vis[j++]=hash[i];          //Ó³Éä´æ´¢ 
		//cout<<hash[i-1]<<endl;
	}
	sort(vis,vis+n1);
	for(int i=1;i<n1;i++) if(vis[i]==vis[i-1]) ans++;
	cout<<n1-ans;
	return 0;
}
