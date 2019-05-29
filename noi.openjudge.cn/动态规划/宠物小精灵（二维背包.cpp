#include<iostream>
#include<cstdio>

using namespace std;

#define max(a,b) (a)>(b)?(a):(b)

struct op{
	int num,cost;
};

int dp[1010][510];

int n,m,k;
op arr[110];

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
		cin>>arr[i].num>>arr[i].cost;
	for(int i=1;i<=k;i++)
	for(int j=n;j>=0;j--)
	for(int k=m;k>=0;k--){
		if(j>=arr[i-1].num&&k>=arr[i-1].cost)
			dp[j][k]=max(dp[j][k],dp[j-arr[i-1].num][k-arr[i-1].cost]);
	}
	cout<<dp[n][m];
	int ans=0;
	for(int i=m-1;i>=0;i--)
		if(dp[n][i]==dp[n][m])
			ans=i;
		else 
			break;
	cout<<m-ans<<endl;
	
}
