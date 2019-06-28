#include<iostream>
#include<cstdio>

using namespace std;
//http://poj.org/problem?id=1804
//对于求交换相邻数字的最小次数，求出逆序对数量就是答案 ！！！ 

//#define debug

typedef long long ll;

int n;
int a[20010];
int temp[20010];

ll res;

void merge(int s,int e){
	if(s>=e) return;
	int mid=(s+e)/2;
	merge(s,mid);
	merge(mid+1,e);
	//统计A和B之间的逆序数，由于A，B两个都是有序的，所以一旦找到A中比B中大的数，
	//那么A中该数之后的都比B大，都是逆序对 
	for(int i=mid+1;i<=e;i++)
		for(int j=s;j<=mid;j++){
			if(a[j]>a[i]){
				res+=(mid-j+1);
				break;
			}
		}
	
	//最终写入排好序的值 
	int i=s,j=mid+1,index=0;
	while(i<=mid&&j<=e){   //条件用小于等于，不用！= 
		if(a[i]<a[j]){
			temp[index++]=a[i++];	
		}
		else {
			temp[index++]=a[j++];
		}
	}
	if(i<=mid){
		for(int ind=i;ind<=mid;ind++)
			temp[index++]=a[ind];
	}
	else if(j<=e){
		for(int ind=j;ind<=e;ind++)
			temp[index++]=a[ind];
	}
	
	for(int ind=0;ind<=e-s;ind++)
		a[s+ind]=temp[ind];
}


int main(){
	
	#ifdef debug
	freopen("brainman.txt","r",stdin);
	#endif
	
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		cin>>n; 
		for(int i=0;i<n;i++)
			cin>>a[i];
		res=0;
		merge(0,n-1);
		cout<<"Scenario #"<<cnt++<<":"<<endl;
		cout<<res<<endl<<endl;
//		for(int i=0;i<n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
	}
	
	
}
