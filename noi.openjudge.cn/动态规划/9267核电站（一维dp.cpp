#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

int n,m;
ll dp[55];  //dp[i]��ʾǰi��λ���ܷŵķ������� 

int main(){
	scanf("%d%d",&n,&m);
	dp[0]=1;  //��i==m+1ʱ����Ҫ�õ�dp[0] 
	dp[1]=2;   //��ʼ�����зźͲ������ֿ��� 
	for(int i=2;i<=n;i++){
		if(i<m) dp[i]=2*dp[i-1];   //dp[i]=2^i 
		else if(i==m) dp[i]=2*dp[i-1]-1;
		else dp[i]=dp[i-1]+(dp[i-1]-dp[i-1-m]);
	}
	printf("%lld",dp[n]); 
}
