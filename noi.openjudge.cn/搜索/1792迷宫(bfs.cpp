#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

//#define debug 

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};

char g[110][110];
int d[110][110];
int si,sj;
int ei,ej;
int k,n;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};


void bfs(){
	memset(d,127,sizeof(d));
	d[si][sj]=0;
	queue<point> q;
	q.push(point(si,sj,0));
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int ni=temp.i+di[i],nj=temp.j+dj[i],ndist=temp.dist+1;
			if(ni>=0&&ni<n&&nj>=0&&nj<n&&g[ni][nj]!='#'){
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
	freopen("1792.txt","r",stdin);
	#endif
	
	int flag;
	cin>>k;
	for(int c=0;c<k;c++){
		flag=1;
		cin>>n;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			g[i][j]=ch;
		}
		cin>>si>>sj>>ei>>ej;
		bfs();
		if(g[si][sj]=='#'||g[ei][ej]=='#') flag=0;
		if(d[ei][ej]>10000) flag=0;
		if(flag==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}
