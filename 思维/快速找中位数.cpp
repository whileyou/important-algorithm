//题目：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
//解法：二分
 
#include <bits/stdc++.h>
using namespace std;
//(n1+n2)/2
int n1,n2,jud;
void find(int l,int r,vector<int>& nums1, vector<int>& nums2,double& ans)
{
	if(l==r||jud) return;
	int x1,y1,x2,y2;
	int m1=(l+r)/2,m2=(n1+n2)/2-m1;
	if(m2>n2){
		find(m1+1,r,nums1,nums2,ans);
		return;
	}
	if(m2<0){
		find(l,m1,nums1,nums2,ans);
		return;
	}
	if(m1==0) x1=-INT_MAX,y1=nums1[m1];
	else if(m1==n1) x1=nums1[m1-1],y1=INT_MAX;
	else x1=nums1[m1-1],y1=nums1[m1];
	if(m2==0) x2=-INT_MAX,y2=nums2[m2];
	else if(m2==n2) x2=nums2[m2-1],y2=INT_MAX;
	else x2=nums2[m2-1],y2=nums2[m2];
	//左移 
	if(x1>y2) find(l,m1,nums1,nums2,ans);
	//右移 
	else if(x2>y1) find(m1+1,r,nums1,nums2,ans);
	if((n1+n2)%2==0){
		if(!jud){
			ans=(max(x1,x2)+min(y1,y2))/2.0,jud=1;
		}
	}
	else{
		if(!jud) ans=min(y1,y2),jud=1;
	}
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	n1=nums1.size(),n2=nums2.size();
	if(n1==0){
		if(n2%2==0) return (nums2[n2/2-1]+nums2[n2/2])/2.0;
		return nums2[n2/2];
	}
	if(n2==0){
		if(n1%2==0) return (nums1[n1/2-1]+nums1[n1/2])/2.0;
		return nums1[n1/2];
	}
	double ans;
	find(0,n1+1,nums1,nums2,ans);
	return ans;
}
int main()
{
	int n,m;
	vector<int> nums1,nums2;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		nums1.push_back(a);
	}
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		nums2.push_back(a);
	}
	printf("%lf\n",findMedianSortedArrays(nums1,nums2));
	return 0;
}
/*
4 2
1 2 3 6
4 5
*/
