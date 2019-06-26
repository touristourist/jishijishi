#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

//#define debug

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {} 
};

char g[110][110];
int d[110][110];
int n,m;
int si,sj;
int ei,ej;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

void bfs(){
	d[si][sj]=0;
	queue<point> q;
	q.push(point(si,sj,0));
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int ni=temp.i+di[i],nj=temp.j+dj[i],ndist=temp.dist+1;
			if(ni>=0&&ni<n&&nj>=0&&nj<m&&g[ni][nj]!='#'){
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
	freopen("6264.txt","r",stdin);
	#endif 
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		char ch;
		cin>>ch;
		g[i][j]=ch;
		if(ch=='S'){
			si=i;
			sj=j;
		}
		else if(ch=='T'){
			ei=i;
			ej=j;
		}
	}
	memset(d,127,sizeof(d));
	bfs();
	cout<<d[ei][ej];
	
}
