#include<iostream>
#include<cstdio>
#include<cstring>
//#include<cmath>     在cmath中abs返回值和参数是double类型
#include<cstdlib> 

//dp[i][j] 表示前i个数的组合能否除以k得到余数j，
//通过dp[i-1][.]的情况，可以得到dp[i][j]情况
 
using namespace std; 

bool dp[10005][105];   //10005是根据n,105是根据k的范围 
int a[10005];

int n,k;

int main(){
	memset(dp,0,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//第一行初始化 
	int firstmod=(a[0]+abs(a[0])*k)%k;
	dp[0][firstmod]=true;
	for(int i=1;i<n;i++){
		for(int j=0;j<k;j++){
			if(dp[i-1][j]){
				int plus=(j+a[i]+k*abs(a[i]))%k;
				int minus=(j-a[i]+k*abs(a[i]))%k;
				dp[i][plus]=true;
				dp[i][minus]=true;
			}
		}
	}
	if(dp[n-1][0]) cout<<"Divisible";
	else cout<<"Not divisible";

}
