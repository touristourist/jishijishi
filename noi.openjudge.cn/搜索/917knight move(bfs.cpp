#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
//#define debug

//bfs的题目，就是走的规则不一样，走的八个方向用di[],dj[]数组表示就好 

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};

int s;
int l;
int si,sj;
int ei,ej;
int d[500][500];
int di[]={-1,-2,-2,-1,1,2,2,1};
int dj[]={-2,-1,1,2,2,1,-1,-2};


void bfs(){
	memset(d,127,sizeof(d));
	d[si][sj]=0;
	queue<point> q;
	q.push(point(si,sj,0));
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int ni=temp.i+di[i],nj=temp.j+dj[i],ndist=temp.dist+1;
			if(ni>=0&&ni<l&&nj>=0&&nj<l){
				if(ndist<d[ni][nj]){
					d[ni][nj]=ndist;
					q.push(point(ni,nj,ndist));
				}
			}
		}
	}
}

int main(){
	#ifdef debug
	freopen("917.txt","r",stdin);
	#endif
	
	cin>>s;
	for(int cnt=0;cnt<s;cnt++){
		cin>>l;
		cin>>si>>sj;
		cin>>ei>>ej;
		bfs();
		cout<<d[ei][ej]<<endl;
	}
	
	
}
