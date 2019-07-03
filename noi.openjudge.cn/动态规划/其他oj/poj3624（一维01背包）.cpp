#include<iostream>
#include<cstdio>

using namespace std;

//http://poj.org/problem?id=3624

#define max(a,b) (a)>(b)?(a):(b)

int n,m;
int w[3500];
int d[3500];
//int dp[3500][12900];    ��ͨ��ά������MLE
int dp[12900]; 


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>d[i];
	}
	//������Ŵ�1��ʼ������ dp[i][j]=dp[i-1][j]�Ų���Խ�� 
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=m;j++){
//		if(j<w[i]) dp[i][j]=dp[i-1][j];
//		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+d[i]);
//	}
	for(int i=1;i<=n;i++)
	for(int j=m;j>=w[i];j--)
		dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
	
			cout<<dp[m];	
	
}
