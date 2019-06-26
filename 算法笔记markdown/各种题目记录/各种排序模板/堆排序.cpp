#include<iostream>
#include<cstdio>

using namespace std;
//注意此处排序数组的下标从1开始，这样才有左子是2*i,右子是2*i+1 
int a[]={0,16,54,89,23,1,8,4,9,76,5,1,32,1,847,12,3};
int arrsize=16;              //堆数组的范围 
int heapsize=arrsize;

void heapify(int a[],int i){
	//对下标为i的元素进行调整 
	int left=i*2,right=i*2+1;
	int largest=i;           //largest初值为i，这样才能中止递归程序 
	//检查是否有子节点 
	//arrsize保存实时的堆大小，arrsize会随着堆排序的过程中改变 ！！！！！！！！！！！ 
	if(left<=arrsize&&a[left]>a[i]) 
		largest=left;
	if(right<=arrsize&&a[right]>a[largest])       
		largest=right;
	//得到三个节点中的最大节点下标
	if(largest!=i){   
//		int temp=a[i];
//		a[i]=a[largest];
//		a[largest]=temp;
		//交换 
		a[i]^=a[largest];
		a[largest]^=a[i];
		a[i]^=a[largest];
		//交换后可能破坏largest那一支，所以还要继续递归调整 
		heapify(a,largest); 
	} 
}
void build_max_heap(int a[]){
	int st=heapsize/2;
	for(int i=st;i>=1;i--){// 从前一半开始一直到第一个元素 
		heapify(a,i);
	}
}
void heap_sort(int a[]){
	
	build_max_heap(a);
	for(int i=arrsize;i>=1;i--){
		int temp=a[1];// 当前最大元素
		a[1]=a[i];
		a[i]=temp;
		//当前堆的大小每次确定一个有序元素后需要减一！！！！！！！！！这样减小heapify范围，否则出错 
		arrsize--; 
		heapify(a,1); 
		
	}
}

int main(){
	heap_sort(a);
	for(int i=1;i<=heapsize;i++)
		cout<<a[i]<<" ";
}
