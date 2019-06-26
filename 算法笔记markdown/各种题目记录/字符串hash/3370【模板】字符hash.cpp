#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

typedef unsigned long long ull;

int n;
ull hashrecord[10005]; 
int base=19260817;     //6~8位质数 
int mod=1e9+9;      //1e9+7 or 1e9+9 

ull hashe(string s){   //只需返回一个最终的字符串hash值 
	ull res=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		res=(res*base+(ull)s[i])%mod;     //id(s[i])=s[i]，ASCII，base相当于p 
	}
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		hashrecord[i]=hashe(s);
	}
	sort(hashrecord,hashrecord+n);
	int num=1;  // 
	for(int i=0;i<n-1;i++){
		if(hashrecord[i]!=hashrecord[i+1])   //对于相同的数不需要加1 
			num++;
	}
	printf("%d",num);
	
}

