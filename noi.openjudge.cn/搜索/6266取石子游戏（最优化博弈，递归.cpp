#include<iostream>
#include<cstdio>
 
using namespace std;
//���Ż�ȡ������˼�������Ϊ�� ֪���ⲽȡ���Ľ�����ջ���ô�� �� 
int a,b;

bool canwin(int a,int b){   //para required: a>=b
	int c=a%b;
	if(a%b==0) return true;
	else if(a/b==1) return !canwin(b,a%b);  //�Է�Ӯ�����Լ��� 
	else if(a/b>=2) return true;   //����������������������Ż�ȡ����һ������Ӯ 
}


int main(){
	while(cin>>a>>b&&a&&b){
		int temp=a+b;
		a=a>b?a:b;
		b=temp-a;   //Ҫ��֤a>b 
		if(canwin(a,b))
			printf("win\n");
		else printf("lose\n");
	}
	
}
