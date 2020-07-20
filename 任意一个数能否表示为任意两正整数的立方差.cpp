 #include <bits/stdc++.h>
using namespace std;  //x^3-y^3==p--->(x-y)*(x^2+x*y+y^2)==p--->Áîx-y==1; 
bool f(long long p)
{
	for (long long i = 1; i*i + i * (i + 1) + (i + 1)*(i + 1) <= p; i++) {
		cout<<i*i + i * (i + 1) + (i + 1)*(i + 1)<<endl;
    	if (i*i + i * (i + 1) + (i + 1)*(i + 1) == p) {
            return true;
        }
    }
    return false;
}
int main()
{
	int t;
	long long p;
	cin>>t;
	while(t--)
	{
		cin>>p;
		if(f(p)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
 
