#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define INF 1<<20

class point{
public:
	int i,j;
	int dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};
int r,c;
char maze[50][50];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int D[50][50];
queue<point> Q;


int main(){
	freopen("2753.txt","r",stdin);
	
	scanf("%d%d",&r,&c);
	
	rep(i,1,r)
	rep(j,1,c){
		cin>>maze[i][j];
		if(maze[i][j]=='#')
			D[i][j]=0;
		else D[i][j]=INF;
	}
	
//	rep(i,0,r){
//		rep(j,0,c)
//		printf("%d ",D[i][j]);
//		printf("\n");
//	}
	
	
	Q.push(point(1,1,1));
	D[1][1]=0;
	while(!Q.empty()){
		point temp=Q.front();
		Q.pop();
		int ii=temp.i,jj=temp.j,dist=temp.dist;
		rep(ind,0,3){
			int ni=ii+dx[ind],nj=jj+dy[ind],ndist=dist+1;
			
//			printf("i: %d, j: %d ndist:%d %d %c r:%d c:%d\n",ni,nj,ndist,D[ni][nj],maze[ni][nj],r,c);
//			printf("tf:%d\n",(ni>=1&&ni<=r&&nj>=1&&nj<=c));
			if(ni>=1&&ni<=r&&nj>=1&&nj<=c&&ndist<D[ni][nj]&&maze[ni][nj]!='#'){
//				printf("ni: %d, nj: %d\n",ni,nj);
				D[ni][nj]=ndist;
				Q.push(point(ni,nj,ndist));
			}
			
		}
	}
//	rep(i,0,r){
//		rep(j,0,c)
//		printf("%d ",D[i][j]);
//		printf("\n");
//	}
	
	
	printf("%d",D[r][c]);
	
}
