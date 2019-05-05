#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
//用float不过，用double就过了！！！ 

//#define debug
#define rep(i,n) for(int i=0;i<n;i++)

struct point{
	int num;
	double avg;
};

bool cmp(point a,point b){
	return a.avg>b.avg;
}

int k,w,s;
int wt[110],p[110];
point ap[110];

int main(){
	#ifdef debug
	freopen("1797.txt","r",stdin);
	#endif
	
	scanf("%d",&k);
	while(k--){
		cin>>w>>s;
		rep(i,s){
			cin>>wt[i]>>p[i];
			ap[i].avg=(double)p[i]/(double)wt[i];
			ap[i].num=i;
		}
		sort(ap,ap+s,cmp);
		double val=0,wei=0;
		int i=0;
		while(wei<=w){      //对于该循环，更应该写成for(int i=0;i<s;i++)形式 
			int num=ap[i].num;
			double avgg=ap[i].avg;
//			printf(" num:%d pi:%d ",num,p[num]);
			
			if(wei+wt[num]>w){
				val+=(w-wei)*avgg;
				break;
			}
			else{
				val+=p[num];	
				wei+=wt[num];
			} 
			i++;
			if(i>=s) break;
//			printf(" val:%f ",val);
		}
		printf("%.2f\n",val);
	}
	
}
