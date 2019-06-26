#include<iostream>
#include<cstdio>

using namespace std;
#define INF 1<<25

int a[]={16,54,89,23,1,8,4,9,76,5,1,32,1,847,12,3};


void merge(int a[],int l,int mid,int r){
	int tem[100];
	int ind=0;
	int i=l,j=mid+1;
	while(i<=mid||j<=r){
		int inum=(i>mid)?INF:a[i];
		int jnum=(j>r)?INF:a[j];
		if(inum>jnum){
			tem[ind]=jnum;
			j++;
		}
		else {
			tem[ind]=inum;
			i++;
		}
		ind++;
	}
	for(int i=l;i<=r;i++){
		a[i]=tem[i-l];
	}
}

void merge_sort(int a[],int l,int r){
	if(l>=r) return ;
	int mid=(l+r)/2;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,l,mid,r);
}


int main(){
	
	merge_sort(a,0,15);
	for(int i=0;i<=15;i++)
		cout<<a[i]<<" ";
	
}
