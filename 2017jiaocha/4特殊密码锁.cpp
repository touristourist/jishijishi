#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define debug

char before[100];
char aim[100];
char test[100];
int len;

void touch(int i){
	if(i>=len||i<0) return;
	
	if (test[i]=='0') test[i]='1';
	else if(test[i]=='1') test[i]='0';
	
	int a=i-1,b=i+1;
	if(a>=0&&a<len){
		test[a]=(test[a]=='0')?'1':'0';
	}
	if(b>=0&&b<len)
		test[b]=(test[b]=='0')?'1':'0';
} 

int main(){
	#ifdef debug
	freopen("4.txt","r",stdin);
	#endif
	
	fgets(before,100,stdin);
	fgets(aim,100,stdin);
	len=strlen(before);
	len=len-1;  //fgets会读入\n 
	before[len]='\0';
	aim[len]='\0';
//	cout<<len;
	strcpy(test,before);
//	printf("%s\n",test);

	//两种情况，第一个按下/不按
	int minnum=100000;
	int tnum=0;
	touch(0);
//	printf("%s\n",test);
	tnum++;
	int ind=0;
	while(ind<len){
		if(test[ind]==aim[ind]){
			ind++;
		}
		else{
			touch(ind+1);
//			printf("%s\n",test);
			ind++;
			if(ind<len) 
				tnum++;
			
		}
	}
//	printf("%s\n",test);
	if(test[len-1]==aim[len-1]){
		minnum=(minnum>tnum)?tnum:minnum;
	}
	
	tnum=0;
	strcpy(test,before);
	ind=0;
	while(ind<len){
		if(test[ind]==aim[ind]){
			ind++;
		}
		else{
			touch(ind+1);
			ind++;
			if(ind<len)
				tnum++;
			
		}
	}
//	printf("%s\n",test);
	
	if(test[len-1]==aim[len-1]){
		minnum=(minnum>tnum)?tnum:minnum;
	}
	
	if(minnum==100000) cout<<"impossible";
	else cout<<minnum;
	
	
	
}

//写的比较乱，需要精简一下 
