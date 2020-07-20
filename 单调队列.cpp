//题目链接：https://ac.nowcoder.com/acm/contest/5667/F
//参考文献：https://www.cnblogs.com/RealMadrid/articles/10599588.html
//状态：通过 
//注：单调队列如何使用详见文献
//单调队列（递增）要点：
//1.队列长度等于范围长度时或有k次未出队头，出队头 
//2.空队时或元素不大于队尾，入队 
//3.元素大于队尾，则一直出队尾，直到队空或元素不大于队尾，入队
//4.记录队头值，得一行或一列的从i开始，长度为k范围的最大值 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,mapp[5001][5001],know[5001][5001];
ll ans;

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        int got=__gcd(i+1,j+1);
        mapp[i][j]=(i+1)*(j+1)/got;
    }
    for(int j=0;j<m;j++){
    	deque<int> q;	//单调队列 
    	int cal=0;
        for(int i=0;i<=n-k;i++){
            if(!i)
            for(int add=0;add<k;add++){
            	if(q.size()==k||cal==k) q.pop_front(),cal=0;
            	else cal++;
				if(q.empty()||mapp[i+add][j]<=q.back()) q.push_back(mapp[i+add][j]);
            	else{
            		while(!q.empty()&&mapp[i+add][j]>q.back()){
            			q.pop_back();
            		}
            		if(q.empty()) cal=0;
            		q.push_back(mapp[i+add][j]);
            	}
            }
            else {
            	if(q.size()==k||cal==k) q.pop_front(),cal=0;
            	else cal++;
				if(q.empty()||mapp[i+k-1][j]<=q.back()) q.push_back(mapp[i+k-1][j]);
            	else{
            		while(!q.empty()&&mapp[i+k-1][j]>q.back()){
            			q.pop_back();
            		}
            		if(q.empty()) cal=0;
            		q.push_back(mapp[i+k-1][j]);
            	}
            }
            know[i][j]=q.front();
            //printf("%d a\n",q.front());
        }
    }
    for(int i=0;i<=n-k;i++){
    	deque<int> q;
    	int cal=0;
    	for(int j=0;j<m;j++){
    		if(q.size()==k||cal==k) q.pop_front(),cal=0;
        	else cal++;
			if(q.empty()||know[i][j]<=q.back()) q.push_back(know[i][j]);
        	else{
        		while(!q.empty()&&know[i][j]>q.back()){
        			q.pop_back();
        		}
        		if(q.empty()) cal=0;
        		q.push_back(know[i][j]);
        	}
    		if(j<k-1) continue;
            ans+=q.front();
    	}
    }
    printf("%lld",ans);
    return 0;
}
