//DFS题解
#include <bits/stdc++.h> 
using namespace std;
int G[6][6];        //存图数组
int dir[4][2] = {0,1,1,0,0,-1,-1,0};//方向数组 
int fd = 0;     //标记是否已经找到路径
int vis[6][6];  //标记数组
struct node{     
	int x,y;
};
stack<node> res;
void dfs(int x,int y)
{
    if(x == 4 && y == 4) fd = 1;        
	else 
	{         
		for(int i = 0;i < 4;++i)
		{       
			int nx = x + dir[i][0];             
			int ny = y + dir[i][1];            
			if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && G[nx][ny] == 0 &&!vis[nx][ny])
			{
            vis[nx][ny] = 1;                 
			dfs(nx,ny);                 
			if(fd)
			{
                    res.push({nx,ny});      //? //记录路径，放入栈中准备逆序输出
                    return;
            }
            }
        }
    }
}
int main()
{
    for(int i = 0;i < 5;++i)         
	for(int j = 0;j < 5;++j)             
	scanf("%d",&G[i][j]);     
	dfs(0,0);     
	printf("(0, 0)\n");     
	while(!res.empty())
	{
        printf("(%d, %d)\n",res.top().x,res.top().y);   //逆序输出栈中路径
        res.pop();  //输出后删掉该元素
    }
    return 0;
}


/*自己写的： 
#include <bits/stdc++.h>
using namespace std;
int go[][2]={1,0,0,1,0,-1,-1,0};
int map_[5][5];
int judge[5][5];
int fd;
stack<int> roadx,roady;   //声明栈来标记路径 (用数组难以保存递归时在不同层的变量)
void dfs(int x,int y)
{
	if(x==y&&x==4)
	{
		fd=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+go[i][0],ny=y+go[i][1];
		if(nx>=0&&nx<=4&&ny>=0&&ny<=4&&!judge[nx][ny]&&map_[nx][ny]==0)
		{
			judge[nx][ny]=1;
			dfs(nx,ny);        //此阶段为试探 
			if(fd){
			roadx.push(nx);   //存入有问题,未找到真正路径就存 
			roady.push(ny);
			return;
			}
		}
	}
	return;
}
int main()
{
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	cin>>map_[i][j];
	dfs(0,0);
	cout<<"(0, 0)"<<endl;
	while(!roadx.empty())
	{
		printf("(%d, %d)\n",roadx.top(),roady.top());
		roadx.pop();
		roady.pop();
	} 
	return 0;
}
