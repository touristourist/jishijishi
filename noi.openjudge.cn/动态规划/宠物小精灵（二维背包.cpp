#include<iostream>
#include<cstdio>

using namespace std;

#define max(a,b) (a)>(b)?(a):(b)
//二维背包问题，降维后用二维数组解决 （降维后倒序遍历 

struct op{
	int num,cost;
};

int dp[1010][510];

int n,m,k;
op arr[110];

int main(){
	cin>>n>>m>>k;   //球数，体力值，精灵数 
	for(int i=0;i<k;i++)
		cin>>arr[i].num>>arr[i].cost;
	for(int i=1;i<=k;i++)      //这里i=1表示从前1个精灵中选择 ，但arr[i] 从0开始，所以要减一 
	for(int j=n;j>=0;j--)
	for(int k=m;k>=0;k--){      
		if(j>=arr[i-1].num&&k>=arr[i-1].cost)
			dp[j][k]=max(dp[j][k],dp[j-arr[i-1].num][k-arr[i-1].cost]+1);
	}
	cout<<dp[n][m]<<" ";
	int ans=0;
	for(int i=m-1;i>=0;i--)
		if(dp[n][i]==dp[n][m])    //球数相等时体力需求越小越好 
			ans=i;
		else 
			break;
	cout<<m-ans<<endl;
	
}
