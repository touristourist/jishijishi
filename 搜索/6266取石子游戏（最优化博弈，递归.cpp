#include<iostream>
#include<cstdio>
 
using namespace std;
//最优化取法的意思可以理解为： 知道这步取完后的结果最终会怎么样 ！ 
int a,b;

bool canwin(int a,int b){   //para required: a>=b
	int c=a%b;
	if(a%b==0) return true;
	else if(a/b==1) return !canwin(b,a%b);  //对方赢就是自己输 
	else if(a/b>=2) return true;   //若遇到这种情况，采用最优化取法，一定可以赢 
}


int main(){
	while(cin>>a>>b&&a&&b){
		int temp=a+b;
		a=a>b?a:b;
		b=temp-a;   //要保证a>b 
		if(canwin(a,b))
			printf("win\n");
		else printf("lose\n");
	}
	
}
