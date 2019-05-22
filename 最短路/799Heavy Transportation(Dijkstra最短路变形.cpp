#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>

using namespace std;

//使用dijkstra最短路的思想(就是对节点值不断更新   d[i]表示到i节点路径的最大承重 
//类似CCF 2018-12第三题 
//题目中边是双向的！！！！！！！！！所以也可以用 最大生成树 做！！！ 
//求最大生成树的最小边就是结果！！！ 


//最大生成树解法： 
//用并查集求最大生成树的过程中按照边从长到短的顺序选择，这样一定能构建从1到n的**唯一**路径，
//求出最大生成树路径中的最小值就是答案 


#define debug
#define rep(i,s,t) for(int i=s;i<=t;i++)

struct edge{
	int no,w;
	edge(int _n,int _w):no(_n),w(_w){}
	edge(){}
};

struct point{
	int no,maxwi;
	point(int _n,int _m):no(_n),maxwi(_m){}
	point(){}
};

struct cmp{
	bool operator ()(point a,point b){
		return a.maxwi<b.maxwi;
	}
};

//需要设置vis数组，因为使用pq优先队列，保证更大d[i]先出队，每次出对就找到一个d[i] 
int vis[1005]; 
int d[1005];
int scenum;
int n,m;
vector<edge> g[1005];

void dijkstra(){
	priority_queue<point,vector<point>,cmp> pq;
	while(!pq.empty()) pq.pop();
//	pq.push(point(1,0));
	d[1]=1000000;
	vis[1]=1;
 	//源点 则直接放入相连的节点 
	int len=g[1].size();
	for(int j=0;j<len;j++){
		pq.push(point(g[1][j].no,g[1][j].w));
		d[g[1][j].no]=g[1][j].w;
	} 
		
	while(!pq.empty()){
		point temp=pq.top();
		pq.pop();
//		cout<<temp.maxwi<<" "<<temp.no<<" |";
		int no=temp.no,maxw=temp.maxwi;
		if(!vis[no]){
			
			vis[no]=1;
			d[no]=maxw;
			int len=g[no].size();
			for(int j=0;j<len;j++){
				int endp=g[no][j].no,ew=g[no][j].w;
				int ddnext=(d[no]<ew)?d[no]:ew;
				if(ddnext>d[endp]&&!vis[endp]){
					pq.push(point(endp,ddnext));
					d[endp]=ddnext;
				} 
				
			}
		}
	}
}

int main(){
	#ifdef debug
	freopen("799.txt","r",stdin);
	#endif
	
	
	cin>>scenum;
	rep(i,1,scenum){
		memset(d,-1,sizeof(d));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<1005;i++)
			g[i].clear();
		cin>>n>>m;
		rep(dd,1,m){
			int st,en,wi;
			cin>>st>>en>>wi;
			g[st].push_back(edge(en,wi));
			g[en].push_back(edge(st,wi));   //原来一直没有看到边是双向的所以一直WA 
		}
		dijkstra();
		printf("Scenario #%d:\n",i);
		cout<<d[n]<<endl<<endl; 	
	}
	
	
}
