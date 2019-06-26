#include<iostream>
#include<cstdio>

using namespace std;
//ע��˴�����������±��1��ʼ����������������2*i,������2*i+1 
int a[]={0,16,54,89,23,1,8,4,9,76,5,1,32,1,847,12,3};
int arrsize=16;              //������ķ�Χ 
int heapsize=arrsize;

void heapify(int a[],int i){
	//���±�Ϊi��Ԫ�ؽ��е��� 
	int left=i*2,right=i*2+1;
	int largest=i;           //largest��ֵΪi������������ֹ�ݹ���� 
	//����Ƿ����ӽڵ� 
	//arrsize����ʵʱ�ĶѴ�С��arrsize�����Ŷ�����Ĺ����иı� ���������������������� 
	if(left<=arrsize&&a[left]>a[i]) 
		largest=left;
	if(right<=arrsize&&a[right]>a[largest])       
		largest=right;
	//�õ������ڵ��е����ڵ��±�
	if(largest!=i){   
//		int temp=a[i];
//		a[i]=a[largest];
//		a[largest]=temp;
		//���� 
		a[i]^=a[largest];
		a[largest]^=a[i];
		a[i]^=a[largest];
		//����������ƻ�largest��һ֧�����Ի�Ҫ�����ݹ���� 
		heapify(a,largest); 
	} 
}
void build_max_heap(int a[]){
	int st=heapsize/2;
	for(int i=st;i>=1;i--){// ��ǰһ�뿪ʼһֱ����һ��Ԫ�� 
		heapify(a,i);
	}
}
void heap_sort(int a[]){
	
	build_max_heap(a);
	for(int i=arrsize;i>=1;i--){
		int temp=a[1];// ��ǰ���Ԫ��
		a[1]=a[i];
		a[i]=temp;
		//��ǰ�ѵĴ�Сÿ��ȷ��һ������Ԫ�غ���Ҫ��һ������������������������Сheapify��Χ��������� 
		arrsize--; 
		heapify(a,1); 
		
	}
}

int main(){
	heap_sort(a);
	for(int i=1;i<=heapsize;i++)
		cout<<a[i]<<" ";
}
