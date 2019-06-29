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
			//�����֮ǰdp�����ֵ���ټ��ϵ�ǰֵp[i]
			//��Ϊ�������int tem=dp[j]+p[i]�У�����p[i]����һ��Ҫ��ǰ���һ�𣬶����Լ������� 
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
