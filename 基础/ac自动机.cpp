//https://www.luogu.com.cn/problem/P3808
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000001;
int n;
int trie[maxn][26];	//�ֵ��� 
int word[maxn];	//���ʳ��ִ��� 
int fail[maxn];	//ʧ��ָ�� 
int cnt=0;	//�ֵ������ 
char s[maxn];

//�����ֵ��� 
void build(char s[])
{
	int root=0,len=strlen(s);
	for(int i=0;i<len;i++){
		if(trie[root][s[i]-'a']) root=trie[root][s[i]-'a'];
		else root=trie[root][s[i]-'a']=++cnt;
	}
	word[root]++;	//�ýڵ㵥�ʳ����� 
}

//����ʧ��ָ�루bfs������ 
void getfail()
{
	queue<int> q;
	for(int i=0;i<26;i++){	//���ڶ������ 
		if(trie[0][i]){
			q.push(trie[0][i]);
		}
	}
	while(!q.empty()){
		int root=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int next=trie[root][i];	//nextΪ�ýڵ�ָ�����һ���ڵ� 
			if(next){
				q.push(next);	//����ڸýڵ㣬����� 
				//�ýڵ�failָ��ָ�򸸽ڵ�failָ����ָ�ӽڵ� 
				fail[next]=trie[fail[root]][i];
			} 
			else{
				//�����ڸýڵ�ֱ��ָ�򸸽ڵ�failָ����ָ�ӽڵ� 
				trie[root][i]=trie[fail[root]][i];
			} 
		}
	}
}

//�����в����ı��� 
int ask(char s[])
{
	int root=0,ans=0,len=strlen(s);
	for(int i=0;i<len;i++){
		root=trie[root][s[i]-'a'];	//�����ַ����� 
		//����ÿ�������ĵ��� 
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
