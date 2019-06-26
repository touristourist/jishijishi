#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const long long N=1000000;

//����΢Ԫ�ķ������r=1��1/4Բ��������ٳ���4����pi 
//int main(){          
//	double d=1.0/N;    
//	double area=0;
//	for(double i=d;i<=1;i+=d){
//		double y=sqrt(1-i*i);
//		area+=d*y;
//	}
//	cout<<4*area<<endl;
//}

 //������������Ҫ�õ�cmathͷ�ļ���sqrt��
 //��������ʹ��taylor��ʽ��pi       tan(pi/4)=1,����atan(1)=pi/4 ��������atan(1)��չ��ʽ 
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
 
