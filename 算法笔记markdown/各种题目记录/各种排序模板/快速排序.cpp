#include<iostream>
#include<cstdio>

using namespace std;

int a[]={16,54,89,23,1,8,4,9,76,5,1,32,1,847,12,3};

//�������� 
void quick_sort(int a[],int l,int r){
	if(l>=r) return ;
	int pivot=a[l];
	int left=l,right=r;   //һ��ʼleftҪָ��pivot��������һ��a[left]=a[right]ʱ�պð�pivot���� 
	while(left<right){
		//right�������� �ҵ���һ����pivotС��������left 
		while(pivot<=a[right]&&left<right){
			right--;
		}
		if(left>=right) break;

		a[left]=a[right];
		left++;
		
		//left�������� �ҵ���һ����pivot���������right 
		while(pivot>=a[left]&&left<right){
			left++;
		}
		if(left>=right) break;
		
		a[right]=a[left];
		right--;
		
	}
	a[left]=pivot;   //pivot�ŵ����յ�λ�� 
	quick_sort(a,l,left-1);
	quick_sort(a,left+1,r);
}

int main(){
	quick_sort(a,0,15);
	for(int i=0;i<16;i++)
		cout<<a[i]<<" ";
}
