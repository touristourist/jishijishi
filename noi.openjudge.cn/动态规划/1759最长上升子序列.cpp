#include<iostream>
#include<cstdio>

using namespace std;

//时间复杂度O(n^2)
//dp[i]表示以a[i]结尾的LIS长度，需要遍历i之前的所有a[j]求得最大值才是dp[i]的值
//初始化时dp[]全为1 

#define MINF -10000

int n;
int a[1005];
int dp[1005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		dp[i]=1;
	int finalMax=MINF;
	for(int i=0;i<n;i++)
	{
		int max=1;  //dp[]的最小值 
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])	max=max>(dp[j]+1)?max:(dp[j]+1);
		}
		dp[i]=max;
		finalMax=finalMax>max?finalMax:max;  //注意最长上升子序列的最大值不一定在最后取得，所以中途记录最大值 
	}
	printf("%d",finalMax);
}
