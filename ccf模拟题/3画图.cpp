#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define mst(a) memset(a,0,sizeof(a))
#define out(name,val)  cout<<"name: "<<val<<endl;
//#define debug

//ǰ�󻭵��߿��ܻ��غ� 
//ע��-��|����Ϊ+,ԭ��Ϊ+�Ͳ��ñ䣨��Ϊǰ�󻭵��߿��ܻ��غϣ���ԭ����+�Ͳ��ñ� 


int m,n,q;
char g[110][110];
int vis[110][110];
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

void dfs(int i,int j,char c){
	vis[i][j]=1;
	g[i][j]=c;
	rep(ind,0,3){
		int ii=i+di[ind],jj=j+dj[ind];
		if(ii>=0&&ii<m&&jj>=0&&jj<n&&!vis[ii][jj]&&g[ii][jj]!='-'&&g[ii][jj]!='|'&&g[ii][jj]!='+')
			dfs(ii,jj,c);
	}
}
 
int main(){
	#ifdef debug
	freopen("20151203.txt","r",stdin);
	#endif
		
	cin>>n>>m>>q;
	rep(i,0,m-1)
	rep(j,0,n-1){
		g[i][j]='.';
	}
//	out(q,q); 
	rep(i,1,q){
		int op=-1;
		cin>>op;
		if(op==1){
			mst(vis);
			int x,y;
			char c;
			cin>>x>>y;
			cin>>c;
			dfs(m-1-y,x,c);
		}
		else if(op==0){
					
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			if(x1==x2){
				y1=m-1-y1;  //���� �����е� ͼ ��ע������任 
				y2=m-1-y2;  
				int miny=min(y1,y2),maxy=max(y1,y2);  //��֪���Ǹ���������Ҫ�ȴ�С 
				rep(j,miny,maxy){
					if(g[j][x1]=='-') g[j][x1]='+';
					else if(g[j][x1]=='+') ;   
					else g[j][x1]='|';
				}
			}
			else if(y1==y2){
				y1=m-1-y1;
				y2=m-1-y2;
				int minx=min(x1,x2),maxx=max(x1,x2);
				rep(j,minx,maxx){
					if(g[y1][j]=='|') g[y1][j]='+';
					else if (g[y1][j]=='+') ;
					else g[y1][j]='-';
				}
			}
		}
	}
	rep(i,0,m-1){
		rep(j,0,n-1)
			cout<<g[i][j];
		cout<<endl;
	}
	
	
	
	
}
