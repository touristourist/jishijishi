#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//https://loj.ac/problem/103
//ʹ��ull���Բ���mod �����Ҫ��mod�ڶ���ط���Ҫ��mod������ hasha[i]-hasha[i-lenb]*psub==hashb)

typedef unsigned long long ull;

#define maxn 1000005
ull p=19260817,mod=1e+9;

char a[maxn];
char b[maxn];
ull hasha[maxn];
ull hashval;


int main(){
	scanf("%s",a);
	scanf("%s",b);
	int lena=strlen(a);
	int lenb=strlen(b);
	hasha[0]=a[0]%mod;
	for(int i=1;i<lena;i++){
		hasha[i]=(hasha[i-1]*p+a[i]);
	}
	ull hashb=0;
	for(int i=0;i<lenb;i++){
		hashb=(hashb*p+b[i]);
	}
	//�õ�p��j-i�η� 
	ull psub=1;
	for(int i=1;i<=lenb;i++){
		psub*=p;
	}
	ull resnum=0;
	if(hasha[lenb-1]==hashb)  resnum++;
	
	for(int i=lenb;i<lena;i++){
		if(hasha[i]-hasha[i-lenb]*psub==hashb) resnum++;
	}
	cout<<resnum;
	
} 

