#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

#define rep(n) for(int i=0;i<n;i++)
//#define debug

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};

char g[300][300];
int d[300][300];

int s;
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
		int ii=temp.i,jj=temp.j,dd=temp.dist;
		for(int i=0;i<4;i++){
			int ni=ii+di[i],nj=jj+dj[i];
			if(ni>=0&&ni<n&&nj>=0&&nj<m&&g[ni][nj]!='#'){
				if(g[ni][nj]=='x'){
					int dist=dd+2;
					if(dist<d[ni][nj]){
						d[ni][nj]=dist;
						q.push(point(ni,nj,dist));
					}
				}
				else{
					int dist=dd+1;
					if(dist<d[ni][nj]){
						d[ni][nj]=dist;
						q.push(point(ni,nj,dist));
					}
				}
			}
		}
	}
}


int main(){
	#ifdef debug
	freopen("4980.txt","r",stdin);
	#endif
	
	
	cin>>s;
	rep(s){
		cin>>n>>m;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
			g[i][j]=ch;
			if(ch=='a'){
				ei=i;
				ej=j;
			}
			else if(ch=='r'){
				si=i;
				sj=j;
			}
		
		}
		memset(d,127,sizeof(d));
		bfs();
		if(d[ei][ej]>40000)
			cout<<"Impossible"<<endl;
		else 
			cout<<d[ei][ej]<<endl;
	}
	
}
