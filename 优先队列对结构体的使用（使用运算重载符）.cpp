//题目链接：https://ac.nowcoder.com/acm/contest/5667/F 
//运算重载符参考博客：https://blog.csdn.net/sunny1996/article/details/51242184?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.compare&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.compare
//状态：不通过（内存被卡掉-->使用单调队列） 
//进行运算符重载可以运用到stl中 

/*
operator 格式:
bool operator 运算符 (const 结构体名称 b) const
{
    return(什么时候这个运算符对结构体成立);//注意对此运算符使用this->元素名；
} 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
typedef struct mapp{
	int v,x,y;	//v:值，x与y表位置坐标  
	bool operator<(const mapp b) const	//优先队列的运算符必须是< 
	{
		return this->v<b.v;		//以mapp.v为依据进行大根堆排序 
	}
}mapp;
ll ans;
priority_queue<struct mapp> q[5001];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=n-k;i++){
		priority_queue<struct mapp> p[5001];
		for(int j=0;j<m;j++){
			if(!i)	//
			for(int add=0;add<k;add++){
				mapp a;
				int got=__gcd(i+1+add,j+1);
				a.v=(i+1+add)*(j+1)/got;
				a.x=i+add;
				a.y=j;
				q[j].push(a);
			}
			else{
				mapp a;
				int got=__gcd(i+k,j+1);
				a.v=(i+k)*(j+1)/got;
				a.x=i+k-1;
				a.y=j;
				q[j].push(a);
			}
			p[j].push(q[j].top());
			if(j<k-1) continue;
			while(!(p[j].top().x>=i&&p[j].top().y<=j&&p[j].top().x<i+k&&p[j].top().y>j-k)){
				p[j].pop();
			}
			ans+=p[j].top().v;
			printf("%d a\n",p[j].top().v);
		}
	}
	printf("%lld",ans);
	return 0;
}
