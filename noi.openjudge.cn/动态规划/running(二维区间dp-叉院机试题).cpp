#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define max(a,b) ((a)>(b))?(a):(b)
#define debug

//Ϊ�˱�ʾ��һ����Ϣ��ֻ�лظ���0����������
//����dp[i][j]�е�j>=1��ʾǰһʱ�����ƶ��ģ�����
//��dp[i][0]������dp[i-j][j]ֱ�ӱ�����ģ���һ����Ϣ�ͱ�����Ϣ��0�� 

int dp[10005][505];
int n,m;
int d[10005];

int main(){
	#ifdef debug
	freopen("running.txt","r",stdin);
	#endif
	
	while(cin>>n>>m){
	
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>d[i];
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		 dp[i][j]=dp[i-1][j-1]+d[i];
		dp[i][0]=dp[i-1][0];
		for(int k=1;k<=m&&k<=i;k++)
			dp[i][0]=max(dp[i][0],dp[i-k][k]);
	}
	
	
	
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	
	cout<<dp[n][0];
	
	}
	

	
} 
