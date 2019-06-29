#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

//http://poj.org/problem?id=3268

#define debug

struct edge{
	int from,to,dist;
	edge(int _f,int _t,int _dist):from(_f),to(_t),dist(_dist) {}
};

struct point{
	int n,dist;
	point(int _n,int _d):n(_n),dist(_d) {}
};

struct cmp{
	bool operator()(point a,point b){
		return a.dist>b.dist;
	}
};

vector<edge> g1[1010];  //正边 
vector<edge> g2[1010];  //逆边 

int d1[1010];  //从party到各个牛的位置的距离
int d2[1010];  //倒置边之后从party到各个牛之间距离 

int n,m,x;

//尽量把正边的dij和逆边的dij分成两个函数写！！！dij函数中放太多参数不好 
void dijk1(int s){
	priority_queue<point,vector<point>,cmp> pq;
	memset(d1,127,sizeof(d1));
	
	
	d1[s]=0;
	int slen=g1[s].size();
	for(int i=0;i<slen;i++)
		pq.push(point(g1[s][i].to,g1[s][i].dist));
	while(!pq.empty()){
		point temp=pq.top();

		pq.pop();
		int nod=temp.n,dis=temp.dist;
		
		if(dis>d1[nod]) continue;
		
		d1[nod]=dis;
		

		
		int nodlen=g1[nod].size();
		for(int i=0;i<nodlen;i++){
			int tonod=g1[nod][i].to,leng=g1[nod][i].dist;
			if(dis+leng<d1[tonod])
				pq.push(point(tonod,dis+leng));
		}
	}
	

}

void dijk2(int s){
	priority_queue<point,vector<point>,cmp> pq;
	memset(d2,127,sizeof(d2));
	
	
	d2[s]=0;
	int slen=g2[s].size();
	for(int i=0;i<slen;i++)
		pq.push(point(g2[s][i].to,g2[s][i].dist));
	while(!pq.empty()){
		point temp=pq.top();

		pq.pop();
		int nod=temp.n,dis=temp.dist;
		

		if(dis>d2[nod]) continue;
		
		d2[nod]=dis;
		
		
		int nodlen=g2[nod].size();
		for(int i=0;i<nodlen;i++){
			int tonod=g2[nod][i].to,leng=g2[nod][i].dist;
			if(dis+leng<d2[tonod])
				pq.push(point(tonod,dis+leng));
		}
	}
	

}

int main(){
	#ifdef debug
	freopen("h.txt","r",stdin);
	#endif 
	
	cin>>n>>m>>x;
	for(int i=0;i<m;i++){
		int a,b,t;
		cin>>a>>b>>t;
		g1[a].push_back(edge(a,b,t)); 
		
		//逆置边
		g2[b].push_back(edge(b,a,t));
	}
	
	dijk1(x);
	
	dijk2(x);
	
	
	int max=0;
	for(int i=1;i<=n;i++){
		int tem=d1[i]+d2[i];
		max=(max>tem)?max:tem;
	}
	
	cout<<max;

	
	
} 
