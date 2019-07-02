#include<iostream>
#include<cstdio>

using namespace std;

//#define debug

int bin[30005];

int find(int x){
	int r=x;
	while(r!=bin[r])
		r=bin[r];
	return r;
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	bin[fy]=fx;
}

bool same(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return true;
	else return false;
}

int n,m;
int agroup[30001];

int main(){
	#ifdef debug
	freopen("1611.txt","r",stdin);
	#endif
	
	while(cin>>n>>m&&(n||m)){
		for(int i=0;i<n;i++)
			bin[i]=i;
		for(int i=0;i<m;i++){
			int gno;
			cin>>gno;
			for(int j=0;j<gno;j++){
				cin>>agroup[j];
			}
			for(int j=0;j<gno-1;j++)
				merge(agroup[j],agroup[j+1]);
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(same(i,0)) cnt++;
		}
		cout<<cnt<<endl; 
	}
	
}

//²¢²é¼¯ 
