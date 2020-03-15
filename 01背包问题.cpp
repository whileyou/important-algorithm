//hdu2602

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[1005];
ll v[1005];
ll dp[1005];
ll dp2[1005][1005];
int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&v[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&w[i]);
        }
        //Ò»Î¬Êý×é
        /*for(int i = 0; i < n; i++)
        {
            for(int j = m; j >= w[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%lld\n",dp[m]);*/
        for(int i = 0; i < n; i++)
        {
            for(int j = w[i]; j <= m; j++)
            {
                dp2[i][j] = max(dp2[i-1][j],dp2[i-1][j-w[i]]+v[i]);
            }
        }
        printf("%lld\n",dp2[n-1][m]);
    }

}
