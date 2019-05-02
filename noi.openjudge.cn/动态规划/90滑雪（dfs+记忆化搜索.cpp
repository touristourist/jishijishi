#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//dfs+记忆化搜索 
//dp[i][j]记录从（i，j）开始的最长距离,对于 

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define maxfun(x,y) x>y?x:y

int h[105][105];
int dp[105][105];
int r,c; 
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

void dfs(int i,int j){    //对于dfs用剪枝，而不是用visited数组每次都要完全遍历一遍 
	if(dp[i][j]>0) return ;   
	rep(dd,0,3){
		int ni=i+di[dd],nj=j+dj[dd];
		if(ni>=0&&ni<r&&nj>=0&&nj<c&&h[ni][nj]<h[i][j]){
			dfs(ni,nj);
			dp[i][j]=maxfun(dp[ni][nj]+1,dp[i][j]);
		}
	}
}

int main(){
//	freopen("90.txt","r",stdin);
	
	int maxtot=-1;
	
	rep(i,0,r-1)
	rep(j,0,c-1)
		dp[i][j]=0; 
	
	scanf("%d%d",&r,&c);
	rep(i,0,r-1)
	rep(j,0,c-1){
		cin>>h[i][j];
	}
	
	rep(i,0,r)
	rep(j,0,c){
//		memset(dp,0,sizeof(dp));   会tle 
		dfs(i,j);   
		maxtot=maxfun(maxtot,dp[i][j]);
		
//		rep(i,0,r-1){
//		rep(j,0,c-1)
//		printf("%d ",dp[i][j]);
//		printf("\n");
//		}
	} 
	
//	rep(i,0,r-1){
//		rep(j,0,c-1)
//		printf("%d ",h[i][j]);
//		printf("\n");
//	}
//	
	
	
	printf("%d",maxtot+1); 
}
