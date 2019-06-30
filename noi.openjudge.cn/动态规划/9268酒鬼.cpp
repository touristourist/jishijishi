#include<iostream>
#include<cstdio>

using namespace std;

#define max(a,b) ((a)>(b))?(a):(b)

int m[710];
int dp[710];
int n;

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m[i];
	dp[1]=m[1];
	dp[2]=m[1]+m[2];
	for(int i=3;i<=n;i++){
		int temp=max(dp[i-1],dp[i-2]+m[i]);
		int ot=dp[i-3]+m[i-1]+m[i];
		dp[i]=max(temp,ot);
	}
	cout<<dp[n];
	
	
} 
