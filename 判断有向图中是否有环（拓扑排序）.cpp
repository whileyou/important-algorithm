//题目：https://leetcode-cn.com/problems/course-schedule/ 

#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,go;
}edge[200001];
int head[100001],in[100001],s[100001],cnt,cal;	//s:起点 
//go:起点,边编号 
void bfs(int go)
{
	queue<int> q;
	q.push(go);
	while(!q.empty()){
		go=head[q.front()];
		while(go){
			in[edge[go].to]--;
			if(!in[edge[go].to])
			q.push(edge[go].to),cal++;
			go=edge[go].go;
		}
		q.pop();
	}
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	int n=prerequisites.size();
	//链式前向星存储 
	for(int i=1;i<=n;i++){
		edge[i].to=prerequisites[i-1][1]+1;
		in[edge[i].to]++;
		edge[i].go=head[prerequisites[i-1][0]+1];
		head[prerequisites[i-1][0]+1]=i;
	}
	//寻找入度为0的点 
	for(int i=1;i<=numCourses;i++) if(!in[i]) s[++cnt]=i;
	//从起点开始bfs遍历（相当于进行了拓扑排序） 
	for(int i=1;i<=cnt;i++){
		bfs(s[i]);
	}
	//所有入度可为0的点与总数不符即为有环 
	if(cal+cnt!=numCourses) return false;
	return true;
}
int main()
{
	
	return 0;
} 
