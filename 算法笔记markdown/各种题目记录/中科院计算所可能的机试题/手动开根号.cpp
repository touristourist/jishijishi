#include<iostream>
#include<cstdio>

using namespace std;

//二分法实现开根号 注意left和right的变化 

double fabs(double x){  //浮点数绝对值 
	if(x<0) return -x;
	else return x;
}

double sqrt(double x){
	double i=x/2;
	double left=0,right=x;
	while(fabs(i*i-x)>1e-6){
		if(i*i-x>0){
			right=i;	
		}
		else {
			left=i;
		}
		i=(left+right)/2; 
	}
	return i;
}
//使用牛顿迭代法      待补充 

int main(){
	cout<<sqrt(2)<<endl;	
}
