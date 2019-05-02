#include<iostream>
#include<cstdio>
#include<cstring>

//dp[i]��ʾ��i�͹ݽ�β��������� (����������������У� 


using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a)  memset(a,0,sizeof(a))
#define max(x,y) x>y?x:y
#define INF 1<<30

int T,n,k;
int m[105],p[105],dp[105];

int main(){
	scanf("%d",&T);
	while(T--){
		mst(dp);
		scanf("%d %d",&n,&k);
		rep(i,0,n-1)
			cin>>m[i];
		rep(i,0,n-1)
			cin>>p[i];
			
		long long maxtot=-INF;
		dp[0]=p[0];
		rep(i,1,n-1){
			dp[i]=p[i];  //dp[i]����Ϊp[i]����Ϊ��i��β��,���Կ����ȸ��丳ֵ 
			rep(j,0,i-1){
				if(m[i]-m[j]>k) dp[i]=max(dp[i],dp[j]+p[i]);
			}
			maxtot=max(maxtot,dp[i]);   //ֻ��1~n-1�Ƚ��ˣ���������i=0��� 
		}
		maxtot=max(dp[0],maxtot);    //ע��Ƚ����ֵ��Ҫ©������һ�������� ���߿��԰�dp[0]=p[0]���뵽ѭ���� 
		
		printf("%lld\n",maxtot);
	}
	
}
