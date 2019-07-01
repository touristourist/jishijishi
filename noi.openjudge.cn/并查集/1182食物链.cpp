#include<iostream>
#include<cstdio>

using namespace std;

const int N=50001;

//poj上的这题输入输出必须用scanf,printf,用cin会超时。
//openjudge可以使用cin,cout。 

//bin[i]是i的同类（的下标）    A
//bin[i+n]表示和i吃的是同类,存的是被i吃的某个动物的下标  B 
//bin[i+2*n]表示和吃i的是同类   C

int bin[3*N];
int n,k;	 

//在poj上会TLE，尝试路径压缩，压不压缩不是关键问题。（cin,cout才是) 
int find(int x){
	int r=x;
	while(r!=bin[r])
		r=bin[r];
//	while(x!=bin[x]){
//		int y=x;
//		x=bin[x];
//		bin[y]=r;
//	}
	return r;
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	else {
		bin[fy]=fx;
	}
}

void init(){
	for(int i=1;i<=3*n;i++)
		bin[i]=i;
}

bool same(int a,int b){ //判断是不是同一类 
	int fa=find(a);
	int fb=find(b);
	if(fa==fb) return true;
	else return false;
}

int main(){
	
	int resnum=0;
	scanf("%d%d",&n,&k);
	init();
	for(int i=0;i<k;i++){
		int d,x,y;
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||x<=0||y>n||y<=0) resnum++;
		else if(d==1){
			//这里拿same(y,x+n)这种条件来判断是一样的 
			if(same(x,y+n)||same(x,y+2*n)) resnum++;
			else{
				merge(x,y);   //x和y是同类，则吃x的和吃y的也是同类 
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		}
		else if(d==2){  //x吃y 
			if(x==y) resnum++;
			else{
	//这里的判断和挑战书上有些出入，因为我对bin[y+n]等的定义是按照开头定义来的，但也能过 
				if(same(x,y)||same(x,y+n)) resnum++;
				else{
					merge(x,y+2*n);   //此出体现A->B,B->C,C->A这种环形关系 
					merge(x+n,y);
					merge(x+2*n,y+n); //x被 y吃的类 吃 
				}
			}
		}
	}
	
	printf("%d",resnum); 
}
