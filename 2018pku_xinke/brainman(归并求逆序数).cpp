#include<iostream>
#include<cstdio>

using namespace std;
//http://poj.org/problem?id=1804
//�����󽻻��������ֵ���С���������������������Ǵ� ������ 

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
	//ͳ��A��B֮���������������A��B������������ģ�����һ���ҵ�A�б�B�д������
	//��ôA�и���֮��Ķ���B�󣬶�������� 
	for(int i=mid+1;i<=e;i++)
		for(int j=s;j<=mid;j++){
			if(a[j]>a[i]){
				res+=(mid-j+1);
				break;
			}
		}
	
	//����д���ź����ֵ 
	int i=s,j=mid+1,index=0;
	while(i<=mid&&j<=e){   //������С�ڵ��ڣ����ã�= 
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
