#include<iostream>
#include<cstdio>

using namespace std;

int a[]={16,54,89,23,1,8,4,9,76,5,1,32,1,847,12,3};

//递增排序 
void quick_sort(int a[],int l,int r){
	if(l>=r) return ;
	int pivot=a[l];
	int left=l,right=r;   //一开始left要指向pivot，这样第一次a[left]=a[right]时刚好把pivot换掉 
	while(left<right){
		//right从右往左 找到第一个比pivot小的数换到left 
		while(pivot<=a[right]&&left<right){
			right--;
		}
		if(left>=right) break;

		a[left]=a[right];
		left++;
		
		//left从左往右 找到第一个比pivot大的数换到right 
		while(pivot>=a[left]&&left<right){
			left++;
		}
		if(left>=right) break;
		
		a[right]=a[left];
		right--;
		
	}
	a[left]=pivot;   //pivot放到最终的位置 
	quick_sort(a,l,left-1);
	quick_sort(a,left+1,r);
}

int main(){
	quick_sort(a,0,15);
	for(int i=0;i<16;i++)
		cout<<a[i]<<" ";
}
