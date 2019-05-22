#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>

using namespace std;

//ʹ��dijkstra���·��˼��(���ǶԽڵ�ֵ���ϸ���   d[i]��ʾ��i�ڵ�·���������� 
//����CCF 2018-12������ 
//��Ŀ�б���˫��ģ���������������������Ҳ������ ��������� �������� 
//���������������С�߾��ǽ�������� 


//����������ⷨ�� 
//�ò��鼯������������Ĺ����а��ձߴӳ����̵�˳��ѡ������һ���ܹ�����1��n��**Ψһ**·����
//������������·���е���Сֵ���Ǵ� 


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

//��Ҫ����vis���飬��Ϊʹ��pq���ȶ��У���֤����d[i]�ȳ��ӣ�ÿ�γ��Ծ��ҵ�һ��d[i] 
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
 	//Դ�� ��ֱ�ӷ��������Ľڵ� 
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
			g[en].push_back(edge(st,wi));   //ԭ��һֱû�п�������˫�������һֱWA 
		}
		dijkstra();
		printf("Scenario #%d:\n",i);
		cout<<d[n]<<endl<<endl; 	
	}
	
	
}
