#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector> 
#include<cstring>

using namespace std;

//匈牙利算法（二分图匹配），对于田鼠尽量使更多的田鼠能找到洞
//将田鼠和洞都视为节点，因为只有田鼠和洞之间有边，所以这是一个二分图，求的是二分图的最大匹配 


//#define debug
#define rep(i,t) for(int i=0;i<t;i++)
#define dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

struct point{
	double x,y;
	point(double _x,double _y):x(_x),y(_y) {}
	point() {}
};

int n,m,s,v;
point gop[105],hol[105];
vector<int> g[105];          //对于vector，记住对其值清除，因为其不是像数组样覆盖原值，而是pushback 
int used[105];
int linker[105];

int dfs(int u){
	int len=g[u].size();
	for(int i=0;i<len;i++){  //邻接表 
		int v=g[u][i];
		if(!used[v]){
			used[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	for(int i=0;i<m;i++)
		linker[i]=-1;
	int res=0;
	for(int i=0;i<n;i++){
		memset(used,0,sizeof(used));
		if(dfs(i)) res++;
	}
	return res;
}

int main(){
	#ifdef debug
	freopen("1538.txt","r",stdin);
	#endif
	
	while(cin>>n>>m>>s>>v){
		rep(i,n) cin>>gop[i].x>>gop[i].y;
		rep(i,m) cin>>hol[i].x>>hol[i].y;
		rep(i,105) g[i].clear();
		rep(i,n){
			rep(j,m){
				double x1=gop[i].x,y1=gop[i].y;
				double x2=hol[j].x,y2=hol[j].y;
				double distance=dis(x1,y1,x2,y2);
//				printf("i:%d<->j:%d dis:%f \n",i,j,distance);
				if(distance<=s*v){
					g[i].push_back(j);   //注意对vecotr清除上一次的空间，因为它不是和数组一样覆盖值！！！ 
//					printf("i:%d-j:%d\n",i,j);
				}
			}
		}
		int res=hungary();
		
		#ifdef debug
		printf("res: %d\n",res);
		#endif
		
		printf("%d\n",n-res);    //最终结果是vulnerable 
	}
} 
