#include<iostream>
#include<cstdio>

using namespace std;
//http://dsalgo.openjudge.cn/sort/4/ 
//归并排序求“普通”逆序对数（对于重要逆序对数不过是比较条件改变一下 

//#define debug

typedef long long ll;

ll n;
ll a[20010];
ll temp[20010];

ll res;

void merge(ll s,ll e){
	if(s>=e) return;
	ll mid=(s+e)/2;
	merge(s,mid);
	merge(mid+1,e);
	//统计A和B之间的逆序数，由于A，B两个都是有序的，所以一旦找到A中比B中大的数，
	//那么A中该数之后的都比B大，都是逆序对 
//	for(int i=mid+1;i<=e;i++)      统计个数放在合并AB有序数组的流程，可以让复杂度更低 
//		for(int j=s;j<=mid;j++){
//			if(a[j]>a[i]){
//				res+=(mid-j+1);
//				break;
//			}
//		}
	
	//最终写入排好序的值 
	int i=s,j=mid+1,index=0;
	while(i<=mid&&j<=e){   //条件用小于等于，不用！= 
		if(a[i]<=a[j]){
			temp[index++]=a[i++];	
		}
		else {
			temp[index++]=a[j++];
			res+=(mid-i+1);    //对于a[i]>a[j]的情况，直接给res加上i~mid的所有 
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
	freopen("putongnixu.txt","r",stdin);
	#endif
	
	
	while(cin>>n){
		if(n==0) break;
		for(int i=0;i<n;i++)
			cin>>a[i];
//			scanf("%lld",a+i);
		res=0;
		merge(0,n-1);
		cout<<res<<endl;
//		printf("%lld\n",res);
//		for(int i=0;i<n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
	}
	
	
}
