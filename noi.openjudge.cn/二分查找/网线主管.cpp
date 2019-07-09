#include<iostream>
#include<cstdio>

using namespace std;

int n,k;
int a[10005];

//使用long long 防止数据溢出！！！     数据没使用long long 溢出后会出现wrong answer
//对于二分的边界条件 left==answer时的情况要作判断 


int main(){
	cin>>n>>k;
	double td;
	for(int i=0;i<n;i++){
		cin>>td;
		a[i]=(int)(td*100);
	}
	long long left=1,right=10000000;
	long long mid;
	long long sum;
	long long maxsum=0;
	while(left<right){
		mid=(left+right)/2;
		sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i]/mid;
		}
		if(sum>=k) left=mid+1;
		else if(sum<k) right=mid-1;
		
	}
	maxsum=0,sum=0;
	for(int i=0;i<n;i++){
		maxsum+=a[i]/1;
		sum+=a[i]/left;
	}
	if(sum<k) left--;
		
	double out=(double)left/100.0;
	if(maxsum<k) cout<<"0.00";
	else
		printf("%.2f",out);
	
}

