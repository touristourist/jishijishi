#include<iostream>
#include<cstdio>

using namespace std;

//���ַ�ʵ�ֿ����� ע��left��right�ı仯 

double fabs(double x){  //����������ֵ 
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
//ʹ��ţ�ٵ�����      ������ 

int main(){
	cout<<sqrt(2)<<endl;	
}
