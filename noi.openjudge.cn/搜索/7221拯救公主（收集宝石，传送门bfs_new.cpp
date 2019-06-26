#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
#define debug

struct point{
	int i,j,dist;
	point(int _i,int _j,int _dist):i(_i),j(_j),dist(_dist) {}
};

char g[300][300];
int d[300][300];
int si,sj;
int ei,ej;
int t,r,c,k;
set<int> baoshi;
vector<pair<int,int>> vgate;
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
			int ni=di[i]+temp.i,nj=dj[i]+temp.j,ndist=temp.dist+1;
			if(ni>=0&&ni<r&&nj>=0&&nj<c&&g[ni][nj]!='#'&&ndist<d[ni][nj]){
				d[ni][nj]=ndist;
				q.push(point(ni,nj,ndist));
				char ch=g[ni][nj];
				if(ch=='$'){
					int len=vgate.size(); 
					for(int index=0;index<len;index++){
						int ii=vgate[index].first;
						int jj=vgate[index].second;
						int nowd=d[ii][jj];
						if(nowd>ndist){
							d[ii][jj]=ndist;
							q.push(point(ii,jj,ndist));
						}
					}
				}
				if(ch>='1'&&ch<='4')
					baoshi.insert((int)(ch-'0'));
			}
		}
	}
	
}

int main(){
	#ifdef debug
	freopen("7221.txt","r",stdin);
	#endif
	
	cin>>t;
	for(int cnt=0;cnt<t;cnt++){
		cin>>r>>c>>k;
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
			}
			else if(ch=='$')
				vgate.push_back(pair<int,int>(i,j));
			
		}
		bfs();
		if(d[ei][ej]>40000) cout<<"oop!"<<endl;
		else cout<<d[ei][ej]<<endl;
	}
	
}
