//https://www.luogu.com.cn/problem/P3808
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000001;
int n;
int trie[maxn][26];	//字典树 
int word[maxn];	//单词出现次数 
int fail[maxn];	//失配指针 
int cnt=0;	//字典树编号 
char s[maxn];

//建立字典树 
void build(char s[])
{
	int root=0,len=strlen(s);
	for(int i=0;i<len;i++){
		if(trie[root][s[i]-'a']) root=trie[root][s[i]-'a'];
		else root=trie[root][s[i]-'a']=++cnt;
	}
	word[root]++;	//该节点单词出现数 
}

//建立失配指针（bfs方法） 
void getfail()
{
	queue<int> q;
	for(int i=0;i<26;i++){	//将第二层入队 
		if(trie[0][i]){
			q.push(trie[0][i]);
		}
	}
	while(!q.empty()){
		int root=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int next=trie[root][i];	//next为该节点指向的下一个节点 
			if(next){
				q.push(next);	//如存在该节点，则入队 
				//该节点fail指针指向父节点fail指针所指子节点 
				fail[next]=trie[fail[root]][i];
			} 
			else{
				//不存在该节点直接指向父节点fail指针所指子节点 
				trie[root][i]=trie[fail[root]][i];
			} 
		}
	}
}

//从树中查找文本串 
int ask(char s[])
{
	int root=0,ans=0,len=strlen(s);
	for(int i=0;i<len;i++){
		root=trie[root][s[i]-'a'];	//进行字符查找 
		//加上每个包含的单词 
		for(int j=root;word[j];j=fail[j]){
			ans+=word[j];
			word[j]=0;
		}
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		build(s);
	}
	getfail();
	scanf("%s",s);
	printf("%d\n",ask(s));
	return 0;
}
