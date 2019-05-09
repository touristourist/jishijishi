#include<iostream>
#include<cstdio>

using namespace std;

#define debug
#define rep(i,s,t) for(int i=s;i<=t;i++)

int mday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//int mon[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
//int mmon[]={0,31,60,91,121,152,182,213,244,274,305,335,366};

bool isrun(int y){
	if((y%4==0&&y%100!=0)||y%400==0)
	return true;
}

int main(){
	#ifdef debug
	int sum=0;
	rep(i,0,12){
		sum+=mday[i];
		printf("%d,",sum);
	}
	#endif
	
	//将开始年份加到年末的12.31 
	int sy,sm,sd,ey,em,ed;
	cin>>sy>>sm>>sd>>ey>>em>>ed;
	int fsum=0;
	for(int i=sm+1;i<=12;i++)
			fsum+=mday[i];
	fsum+=(mday[sm]-sd);   //加到今年的12.31 
	if(sm>2) ;
	else if(sm<=2){
		if(isrun(sy)) fsum+=1;
		else ;
	} 
	int rynum=0,durdays=0;
	for(int i=sy+1;i<=ey-1;i++)   //算到中止年份前一年的12.31（1.1之前 
		if(isrun(i)) rynum++;
	durdays=365*(ey-sy-1)+rynum;
	
	//中止年份的1.1~这一年的当前日期 
	int pnum=0;
	for(int i=1;i<=em-1;i++)
		pnum+=mday[i];
	pnum+=ed;
	if(isrun(ey)&&em>2) pnum+=1;
	
	
	printf("fsu:%d pnu:%d  dur:%d\n",fsum,pnum,durdays);
	printf("%d",pnum+fsum+durdays);
} 

