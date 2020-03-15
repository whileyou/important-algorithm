//DFS���
#include <bits/stdc++.h> 
using namespace std;
int G[6][6];        //��ͼ����
int dir[4][2] = {0,1,1,0,0,-1,-1,0};//�������� 
int fd = 0;     //����Ƿ��Ѿ��ҵ�·��
int vis[6][6];  //�������
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
                    res.push({nx,ny});      //? //��¼·��������ջ��׼���������
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
        printf("(%d, %d)\n",res.top().x,res.top().y);   //�������ջ��·��
        res.pop();  //�����ɾ����Ԫ��
    }
    return 0;
}


/*�Լ�д�ģ� 
#include <bits/stdc++.h>
using namespace std;
int go[][2]={1,0,0,1,0,-1,-1,0};
int map_[5][5];
int judge[5][5];
int fd;
stack<int> roadx,roady;   //����ջ�����·�� (���������Ա���ݹ�ʱ�ڲ�ͬ��ı���)
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
			dfs(nx,ny);        //�˽׶�Ϊ��̽ 
			if(fd){
			roadx.push(nx);   //����������,δ�ҵ�����·���ʹ� 
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
