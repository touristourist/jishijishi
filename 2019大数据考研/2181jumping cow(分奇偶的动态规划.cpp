#include<iostream>
#include<cstdio>

using namespace std;

#define debug
#define max(a,b) ((a)>(b))?(a):(b)

#define max(a,b) ((a)>(b))?(a):(b) 

int dp1[150005];  //dp1[i]表示前i个数中有偶数次选择的最大值 
int dp2[150005];   //前i个数中有奇数次选择 
int a[150005];
int n;

int main(){
	
	#ifdef debug
	freopen("2181.txt","r",stdin);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ma=-100000;
	for(int i=1;i<=n;i++){
		dp1[i]=max(dp1[i-1],dp2[i-1]-a[i]);
		dp2[i]=max(dp2[i-1],dp1[i-1]+a[i]);
		ma=max(ma,dp1[i]);
		ma=max(ma,dp2[i]);
	}
	cout<<ma;
	
}


//这种做法是n^2复杂度，显然超时！ 

//int dp1[150005];   //第i次是偶数 
//int dp2[150005];   //第i次是奇数 
//int a[150005];
//int n;
//
//int main(){
//	#ifdef debug
//	freopen("2181.txt","r",stdin);
//	#endif 
//	
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>a[i];
//	dp1[2]=-a[2]+a[1];
//	dp2[1]=a[1];
//	dp2[2]=a[2];
//	for(int i=3;i<=n;i++){
//		dp1[i]=-a[i];
//		dp2[i]=a[i];
//		for(int j=1;j<i;j++){
//			dp1[i]=(dp1[i]>dp2[j]-a[i])?dp1[i]:dp2[j]-a[i];
//			dp2[i]=(dp2[i]>dp1[j]+a[i])?dp2[i]:dp1[j]+a[i];
//		}
//	}
//	int maxxx=-100000;
//	for(int i=1;i<=n;i++){
//		maxxx=max(maxxx,dp1[i]);
//		maxxx=max(maxxx,dp2[i]);
//	}
//	cout<<maxxx;
//	
//}
