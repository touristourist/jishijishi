#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const long long N=1000000;

//采用微元的方法求出r=1的1/4圆的面积，再乘以4就是pi 
//int main(){          
//	double d=1.0/N;    
//	double area=0;
//	for(double i=d;i<=1;i+=d){
//		double y=sqrt(1-i*i);
//		area+=d*y;
//	}
//	cout<<4*area<<endl;
//}

 //上述方法可能要用到cmath头文件（sqrt）
 //下述方法使用taylor公式求pi       tan(pi/4)=1,所以atan(1)=pi/4 下述就是atan(1)的展开式 
#define PLUS 1
 
int main(){
	double res=0;
	int sign=PLUS;
	for(int i=1;i<N;i+=2){
		res+=sign*(1.0/i);
		sign=-sign;
	}
	cout<<4*res<<endl;
	
}
 
