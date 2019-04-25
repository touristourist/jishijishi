#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

#define max(x,y) (x)>(y)?(x):(y)


//dp[i,j]表示跑完第i分钟，且疲劳值为j的最长距离 

//最终要求的是dp[n][0] 

//dp[i,j]=dp[i-1,j-1]+d[i]   i>=1,j>=1
//dp[i,0]=  max{ dp[i-j][j] }  j>=1&&j<=m&&j<i 

int dp[10005][505];

int main()
{
	int n,m;
//	int d[m]; 还没scanf所以造成error 
//	cout<<"sdf";
	scanf("%d %d",&n,&m);
	int d[n+1];
	for(int i=0;i<n;i++)
		scanf("%d",d+i+1);  //d[1]~d[n]
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];     //一定要做此赋值，保证dp[i][0]的下限
		//不能保证dp[i][0]和dp[i][1]到底哪个更大！！！ 
		for(int j=1;j<=m;j++)
		{
			if(j<i)
				dp[i][0]=max(dp[i][0],dp[i-j][j]);
			dp[i][j]=dp[i-1][j-1]+d[i];
		}
	}
	
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//		cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	
	
	cout<<dp[n][0];

}
