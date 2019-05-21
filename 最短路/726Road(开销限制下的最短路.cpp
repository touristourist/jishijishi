#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

//#define debug
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define outc(nam) cout<<nam<<endl
#define out(name,val) cout<<name<<" :"<<val<<" ";

//有开销限制的单源最短路dijkstra 
//需要维护优先队列即可
//优先队列保证了每次距离最短优先的原则 ,这样在优先队列中的哪个节点先找到N节点就是满足开销的最短距离 

struct edge{
	int end,dist,cost;
	edge(int _e,int _d,int _c):end(_e),dist(_d),cost(_c){}
	edge(){}
};
struct point{
	int no,dist,cost;
	point(int _n,int _d,int _c):no(_n),dist(_d),cost(_c){}
	point(){}
};
struct cmp{
	bool operator()(point a,point b){
		return a.dist>b.dist;
	}
};

//int d[110];    
//int c[110];  由于路径不是最短的也可能是解，所以不用vis数组 ， 
//int vis[110];   也不用d[]记录当前最短距离，因为在 优先队列 中有遍历过的点的所有情况 
vector<edge> g[110];  //1~N
int k,n,r;

int main(){
	#ifdef debug
	freopen("726.txt","r",stdin);
	#endif
	
//	memset(d,-1,sizeof(d));
//	memset(c,-1,sizeof(c));
//	memset(vis,0,sizeof())
	cin>>k>>n>>r;
	rep(i,1,r){
		int ss,dd,ll,tt;
		cin>>ss>>dd>>ll>>tt;
		g[ss].push_back(edge(dd,ll,tt));
	}
	priority_queue<point,vector<point>,cmp> pq;
	for(int i=0;i<g[1].size();i++){
		if(g[1][i].cost<=k)
			pq.push(point(g[1][i].end,g[1][i].dist,g[1][i].cost));
	}
	int flag=0,res=0;
	while(!pq.empty()){
		point temp=pq.top();
		pq.pop();
		int no=temp.no,nowdist=temp.dist,nowcost=temp.cost;
		if(nowcost<=k){  //检查点是否符合开销的限制 
			if(no==n)  {  //只要第一次遍历到点N，这就是满足开销限制的最短距离 
				flag=1;
				res=nowdist;
				break;
			}
			int len=g[no].size();
			for(int i=0;i<len;i++)
				if(g[no][i].cost+nowcost<=k)
					pq.push(point(g[no][i].end,g[no][i].dist+nowdist,g[no][i].cost+nowcost));
		}
		
	}
	if(flag==1) cout<<res;
	else if(flag==0) cout<<-1;
	
}
