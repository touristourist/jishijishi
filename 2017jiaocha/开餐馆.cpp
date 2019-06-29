#include<iostream>
#include<cstdio>

using namespace std;

//http://bailian.openjudge.cn/practice/4118/
//#define debug
#define rep(k) for(int cc=0;cc<k;cc++)

int t,n,k;
int d[1000000];
int dp[1000000];
int p[1000000];

int main(){
	#ifdef debug
	freopen("e.txt","r",stdin);
	#endif
	
	cin>>t;
	rep(t){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>d[i];
		for(int i=0;i<n;i++)
			cin>>p[i];
		dp[0]=p[0];
		for(int i=1;i<n;i++){
			int max=0;
			for(int j=0;j<i;j++){
				if(d[i]-d[j]>k){
					int tem=dp[j];	
					max=(max>tem)?max:tem;
				}
				
			}
			//先求出之前dp的最大值，再加上当前值p[i]
			//因为如果放在int tem=dp[j]+p[i]中，可能p[i]都不一定要和前面的一起，而是自己单独。 
			dp[i]=max+p[i];
		}
		
		int max=-1;
		for(int i=0;i<n;i++){
			max=(max>dp[i])?max:dp[i];
		}
//		for(int i=0;i<n;i++)
//			cout<<p[i]<<" ";
//		cout<<endl;
		
		cout<<max<<endl;
	}
} 
