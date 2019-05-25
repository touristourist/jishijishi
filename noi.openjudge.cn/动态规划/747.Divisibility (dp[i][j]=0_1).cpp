#include<iostream>
#include<cstdio>
#include<cstring>
//#include<cmath>     ��cmath��abs����ֵ�Ͳ�����double����
#include<cstdlib> 

//dp[i][j] ��ʾǰi����������ܷ����k�õ�����j��
//ͨ��dp[i-1][.]����������Եõ�dp[i][j]���
 
using namespace std; 

bool dp[10005][105];   //10005�Ǹ���n,105�Ǹ���k�ķ�Χ 
int a[10005];

int n,k;

int main(){
	memset(dp,0,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//��һ�г�ʼ�� 
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
