#include<iostream>
#include<cstdio>
#include<cstring>

//dp[i]表示以i餐馆结尾的最大利润 (类似最大上升子序列） 


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
			dp[i]=p[i];  //dp[i]至少为p[i]（因为以i结尾）,所以可以先给其赋值 
			rep(j,0,i-1){
				if(m[i]-m[j]>k) dp[i]=max(dp[i],dp[j]+p[i]);
			}
			maxtot=max(maxtot,dp[i]);   //只和1~n-1比较了！！！还有i=0情况 
		}
		maxtot=max(dp[0],maxtot);    //注意比较最大值不要漏了任意一个！！！ 或者可以把dp[0]=p[0]并入到循环中 
		
		printf("%lld\n",maxtot);
	}
	
}
