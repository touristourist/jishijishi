#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

//#define debug
#define INF 1<<30
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a)) 
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y

class point{
public:
	int n;
	int dist;  
	point(int _n,int _dist):n(_n),dist(_dist) {}
};

struct cmp{
	bool operator ()(point a,point b){
		return a.dist>b.dist;   //最小堆 
	}
};

int vis[105],d[105];
int M[105][105];
int n;
priority_queue<point,vector<point>,cmp> PQ;
int maxedge=-INF;

void input(){   //下三角，只有下三角的值才有意义 
	scanf("%d",&n);
	rep(i,0,n-1)
	rep(j,0,n-1)
		M[i][j]=INF;
	rep(i,1,n-1){
		rep(j,0,i-1){
			string s;
			cin>>s;
			if(s=="x") M[i][j]=INF;
			else{
				int dd;
				sscanf(s.c_str(),"%d",&dd);
				M[i][j]=dd;
			}
		}
	}
	#ifdef debug
	rep(i,0,n-1){
		rep(j,0,n-1)
		printf("%d ",M[i][j]);
		printf("\n");
	}
	#endif
	
}

void dij(){
	mst(vis);
	rep(i,0,n-1) d[i]=INF;
	d[0]=0;
	PQ.push(point(0,0));
	//*******注意dijkstra此处条件是PQ队列不为空！！！而不是n次循环(n+2也不行,因为已经确定vis=1的点仍可能在PQ中，所以循环次数不确定 
	while(!PQ.empty()){         
		point tep=PQ.top();
		PQ.pop();
		int node=tep.n;    //找出当前最小的点 
		vis[node]=1;
		rep(j,0,n-1){  //遍历所有的邻边 
			int dd=min(M[node][j],M[j][node]);
			if(dd<INF-1&&d[node]+dd<d[j]&&vis[j]==0){
				d[j]=d[node]+dd;
				PQ.push(point(j,d[j]));
			}
		}
	} 
	
}


int main(){
	mst(M);
	
	#ifdef debug
	freopen("1502.txt","r",stdin);
	//测试最小堆 
	priority_queue<point,vector<point>,cmp> pq;
	for(int i=10;i>=1;i--)	pq.push(point(0,i));
	while(!pq.empty()){
		cout<<pq.top().dist<<" ";
		pq.pop();
	}
	cout<<endl;
	#endif
	
	input();
	dij();
	#ifdef debug
	rep(i,0,n-1)
	printf("%d ",d[i]);
	printf("\n");
	#endif
	rep(i,0,n-1)
		maxedge=max(maxedge,d[i]);
	printf("%d",maxedge);
	
}
