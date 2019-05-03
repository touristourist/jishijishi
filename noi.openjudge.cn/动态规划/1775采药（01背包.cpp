#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//dp[i][j]表示在前i件（1~i）物品中做选择，重量限制是j，这样的到的最优价格 

#define oj
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a)) 
#define max(x,y) x>y?x:y


int t,m;
int p[105],wt[105];
int dp[105][1005];    //注意！！！ T是1000，所以T要开到1000+ ！！！！！！ 
//第i行代表前i个背包，第j列表示当前重量限制为j，行和列都是离散的整数 

int main(){
	
#ifndef oj
	freopen("1775.txt","r",stdin);
	scanf("%d %d",&t,&m);
	
	rep(i,1,m){	
		cin>>wt[i]>>p[i];
	}
	mst(dp);
	rep(i,1,m)
	rep(j,1,t){
		//若选不了第i件，则只从前i-1件考虑 
		if(j<wt[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+p[i]); 
		//若能选第i件物品，则有不选和选两种情况。
		//不选，则不考虑第i件，直接考虑从前i-1件里选，重量限制是j
		//若选，则剩下j-wt[i]用于前i-1件的选择。 
	}
	
	rep(i,0,m){
		rep(j,0,t)
		printf("%d ",dp[i][j]);
		printf("\n");
	}
	
	printf("%d",dp[m][t]);
#endif
#ifdef oj
	scanf("%d %d",&t,&m);
	rep(i,1,m){	
		cin>>wt[i]>>p[i];
	}
	mst(dp);
	rep(i,1,m)
	rep(j,1,t){
		//若选不了第i件，则只从前i-1件考虑 
		if(j<wt[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+p[i]); 
		//若能选第i件物品，则有不选和选两种情况。
		//不选，则不考虑第i件，直接考虑从前i-1件里选，重量限制是j
		//若选，则剩下j-wt[i]用于前i-1件的选择。 
	}
	printf("%d",dp[m][t]);
#endif
	
}
