#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

int n,m;
ll dp[55];  //dp[i]表示前i个位置能放的方案总数 

int main(){
	scanf("%d%d",&n,&m);
	dp[0]=1;  //当i==m+1时，需要用到dp[0] 
	dp[1]=2;   //初始化，有放和不放两种可能 
	for(int i=2;i<=n;i++){
		if(i<m) dp[i]=2*dp[i-1];   //dp[i]=2^i 
		else if(i==m) dp[i]=2*dp[i-1]-1;
		else dp[i]=dp[i-1]+(dp[i-1]-dp[i-1-m]);
	}
	printf("%lld",dp[n]); 
}
