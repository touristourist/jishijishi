#include<iostream>
#include<cstdio>

using namespace std;

//以i为界，分成两个部分，分别求两部分的最大连续子段和 
//和最大字段和的差别是：因为只求加和的最大值，当最大值为负数时，本题依然是该负数而不是0 

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define per(i,s,t) for(int i=s;i>=t;i--)
#define maxfun(x,y) (x)>(y)?(x):(y)

int n,m;
int num[50005]; 
int dp1[50005]; 
int dp2[50005];  //dp[i]表示以num[i]结尾的最大值，dp[i]可以小于0 
int f1[50005];     //f[i]表示处理到num[i]位置时的最大值       //f[i]最小是0（为负数时赋值为0）（错误） 
int f2[50005];

void ascBigest(int bound){  //从左往右直到bound 
	int maxnum=-100000;
	rep(i,1,bound){
		dp1[i]=maxfun(dp1[i-1]+num[i],num[i]);
		maxnum=maxfun(maxnum,dp1[i]);
		f1[i]=maxnum;
	}
//	return maxnum;
}
void dscBigest(int bound){
	int maxnum=-100000;
	per(i,m,bound){
		dp2[i]=maxfun(dp2[i+1]+num[i],num[i]);
		maxnum=maxfun(maxnum,dp2[i]);
		f2[i]=maxnum;
	}
//	return maxnum;
}

int main(){
//	freopen("1481.txt","r",stdin);
	
	scanf("%d",&n);
	while(n--){
		getchar();
		scanf("%d",&m);
		num[0]=0; num[m+1]=0;
		rep(i,1,m) scanf("%d",num+i);
		int max=-100000;
		
		ascBigest(m-1);
		dscBigest(2);   //填好dp1[]和dp2[]然后再用i分割 
		
		rep(i,1,m-1){
			int max1=f1[i],max2=f2[i+1];
//			rep(j,1,i) max1=maxfun(max1,dp1[j]);
//			per(j,m,i+1) max2=maxfun(max2,dp2[j]);   不能，对于O(n^2)会超时 
			int sum=max1+max2;
//			printf("r: %d %d\n",max1,max2);
			max=max>sum?max:sum;
		}
		printf("%d\n",max);
		
	}
	
}
