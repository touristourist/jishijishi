#include<iostream>
#include<cstdio>

using namespace std;
//http://dsalgo.openjudge.cn/sort/4/ 
//�鲢��������ͨ�����������������Ҫ������������ǱȽ������ı�һ�� 

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
	//ͳ��A��B֮���������������A��B������������ģ�����һ���ҵ�A�б�B�д������
	//��ôA�и���֮��Ķ���B�󣬶�������� 
//	for(int i=mid+1;i<=e;i++)      ͳ�Ƹ������ںϲ�AB������������̣������ø��Ӷȸ��� 
//		for(int j=s;j<=mid;j++){
//			if(a[j]>a[i]){
//				res+=(mid-j+1);
//				break;
//			}
//		}
	
	//����д���ź����ֵ 
	int i=s,j=mid+1,index=0;
	while(i<=mid&&j<=e){   //������С�ڵ��ڣ����ã�= 
		if(a[i]<=a[j]){
			temp[index++]=a[i++];	
		}
		else {
			temp[index++]=a[j++];
			res+=(mid-i+1);    //����a[i]>a[j]�������ֱ�Ӹ�res����i~mid������ 
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
