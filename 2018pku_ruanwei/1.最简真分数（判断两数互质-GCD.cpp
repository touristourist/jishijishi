#include<iostream>
#include<cstdio>

using namespace std;

#define debug

//两数互质则最大公因数为1   GCD辗转相除法 
bool huzhi(int a,int b){
	int result=false;
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;	
	}
	if(a==1) return true;
	else return false;	
} 

int arr[605];

int main(){
	#ifdef debug
	freopen("1.txt","r",stdin);
	#endif
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	int num=0;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	if(huzhi(arr[i],arr[j])) num++;
	printf("%d",num);
	
}

