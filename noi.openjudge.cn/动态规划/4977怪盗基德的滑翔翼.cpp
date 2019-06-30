#include<iostream>
#include<cstdio>

using namespace std;

//因为可以从任意方向开始飞 
//所以正反都做一遍dp 

int k,n;
int m[200];
int w[200];
int dp1[200];
int dp2[200];

int main(){
	
	
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=0;i<n;i++){
			dp1[i]=1;   //初始化就是1（只算自己一个）
			dp2[i]=1; 
		}
			
			
		for(int i=0;i<n;i++){
			cin>>m[i];
			w[n-i-1]=m[i];
		}
			
		for(int i=0;i<n;i++){
			int max=1;   //最少也是1（只算自己一个） 
			for(int j=0;j<i;j++){
				if(m[i]<m[j])
					max=(max>dp1[j]+1)?max:dp1[j]+1;
			}
			dp1[i]=max;
		}
		for(int i=0;i<n;i++){
			int max=1;
			for(int j=0;j<i;j++){
				if(w[i]<w[j])
					max=(max>dp2[j]+1)?max:dp2[j]+1;
			}
			dp2[i]=max;
		}
		
//		for(int i=0;i<n;i++)
//			cout<<dp[i]<<" ";
//		cout<<endl;
		
		int max1=1,max2=1;
		for(int i=0;i<n;i++){
			max2=(max2>dp2[i])?max2:dp2[i];
			max1=(max1>dp1[i])?max1:dp1[i];
		}
			
		int res=max1>max2?max1:max2;
		cout<<res<<endl;
		
	}
	
}
