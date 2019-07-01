#include<iostream>
#include<cstdio>

using namespace std;

const int N=50001;

//poj�ϵ������������������scanf,printf,��cin�ᳬʱ��
//openjudge����ʹ��cin,cout�� 

//bin[i]��i��ͬ�ࣨ���±꣩    A
//bin[i+n]��ʾ��i�Ե���ͬ��,����Ǳ�i�Ե�ĳ��������±�  B 
//bin[i+2*n]��ʾ�ͳ�i����ͬ��   C

int bin[3*N];
int n,k;	 

//��poj�ϻ�TLE������·��ѹ����ѹ��ѹ�����ǹؼ����⡣��cin,cout����) 
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

bool same(int a,int b){ //�ж��ǲ���ͬһ�� 
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
			//������same(y,x+n)�����������ж���һ���� 
			if(same(x,y+n)||same(x,y+2*n)) resnum++;
			else{
				merge(x,y);   //x��y��ͬ�࣬���x�ĺͳ�y��Ҳ��ͬ�� 
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		}
		else if(d==2){  //x��y 
			if(x==y) resnum++;
			else{
	//������жϺ���ս������Щ���룬��Ϊ�Ҷ�bin[y+n]�ȵĶ����ǰ��տ�ͷ�������ģ���Ҳ�ܹ� 
				if(same(x,y)||same(x,y+n)) resnum++;
				else{
					merge(x,y+2*n);   //�˳�����A->B,B->C,C->A���ֻ��ι�ϵ 
					merge(x+n,y);
					merge(x+2*n,y+n); //x�� y�Ե��� �� 
				}
			}
		}
	}
	
	printf("%d",resnum); 
}
