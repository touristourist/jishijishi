#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

#define rep(n) for(int i=0;i<n;i++)
#define mst(a) memset(a,0,sizeof(a))
#define INF 1<<20
//#define debug

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};


char g[300][300];
int d[300][300];
int T;
int r,c;
int si,sj;
int ei,ej;

int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};


void bfs(){
	memset(d,127,sizeof(d));    //需要将d[][]全部重置为INF，对于障碍#也重置为INF 
	queue<point> q;
	d[si][sj]=0;
	q.push(point(si,sj,0));
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int ni=temp.i+di[i],nj=temp.j+dj[i],ndist=temp.dist+1;
			if(ni>=0&&ni<r&&nj>=0&&nj<c&&g[ni][nj]!='#'){
				if(ndist<d[ni][nj]){
					q.push(point(ni,nj,ndist));
					d[ni][nj]=ndist;
				}
			}
		}
		
	}
	
}

int main(){
	#ifdef debug
	freopen("7218.txt","r",stdin);
	#endif
	
	
	cin>>T;
	rep(T){
		cin>>r>>c;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			char ch;
			cin>>ch;
			g[i][j]=ch; 
			if(ch=='S'){
				si=i;
				sj=j;
			}
			else if(ch=='E'){
				ei=i;
				ej=j;
				d[i][j]=INF;
			}
			else if(ch=='#')
				d[i][j]=-INF;
			else if(ch=='.')
				d[i][j]=INF;
		}
	
		
		bfs();
		if(d[ei][ej]>4*1e4) 
			cout<<"oop!"<<endl;
		else
			cout<<d[ei][ej]<<endl;
	}
	
}
