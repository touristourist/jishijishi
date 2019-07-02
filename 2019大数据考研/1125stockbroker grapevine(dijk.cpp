#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

#define INF 1<<20
//#define debug

struct edge{
	int to,dist;
	edge(int _t,int _d):to(_t),dist(_d) {}
};

struct point{
	int no,dist;
	point(int _n,int _d):no(_n),dist(_d) {}
};

struct cmp{
	bool operator ()(point a,point b){
		return a.dist>b.dist;
	}
};


int d[110];
vector<edge> g[110];    //全局变量注意清空 
int dm[110][110];
int maxdm[110];
int n;



void dijk(int s){
	memset(d,127,sizeof(d));
	d[s]=0;
	priority_queue<point,vector<point>,cmp> pq;
	for(int i=0;i<g[s].size();i++){
		int to,dd;
		to=g[s][i].to;
		dd=g[s][i].dist;
		pq.push(point(to,dd));
	}
	while(!pq.empty()){
		point temp=pq.top();
		pq.pop();
		int to=temp.no,dist=temp.dist;
		if(d[to]<dist) continue;
		d[to]=dist;
		for(int i=0;i<g[to].size();i++){
			int ndist=dist+g[to][i].dist;
			int tto=g[to][i].to;
			if(ndist<d[tto])
				pq.push(point(tto,ndist));
		}
	}
	
	int max=-1;
	for(int i=1;i<=n;i++){
		dm[s][i]=d[i];	
		max=(max>d[i])?max:d[i];
	}
	maxdm[s]=max;
		
		
//	for(int i=1;i<=n;i++)
//		cout<<d[i]<<" ";
//	cout<<endl;
}



int main(){
	
	#ifdef debug
	freopen("1125.txt","r",stdin);
	#endif 
	
	while(cin>>n&&n){
		//清空上一次的图 
		for(int i=0;i<110;i++)
			g[i].clear();
		
		
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int v,di;
				cin>>v>>di;
				g[i].push_back(edge(v,di));
			}
		}
		
		
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<g[i].size();j++)
//				cout<<g[i][j].to<<" "<<g[i][j].dist<<"        ";
//			cout<<endl;
//		}
			
		
		
		for(int i=1;i<=n;i++)
			dijk(i);
		
		int index=-1,min=INF;
		for(int i=1;i<=n;i++){
			if(maxdm[i]<min){
				min=maxdm[i];
				index=i;
			}
		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				cout<<dm[i][j]<<" ";
//			cout<<endl;
//		}
		
		
		cout<<index<<" "<<maxdm[index]<<endl;
	}
	
}

//用堆优化的dij 求出任意两点之间的最短距离（比floyd高效） 
