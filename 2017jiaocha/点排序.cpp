#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define debug
#define rep(k) for(int i=0;i<k;i++)

struct point{
	int x,y;
	int dist;
	point(int _x,int _y,int _d):x(_x),y(_y),dist(_d) {}
	point(){}
};

bool cmp(point a,point b){
	if(a.dist<b.dist)	return true;
	else if(a.dist==b.dist){
		if(a.x<b.x) return true;
		else if(a.x==b.x){
			return a.y<b.y;
		}
		else return false;
	}
	else return false;
}

//point allp[110]; //

vector<point> allp;

int x,y;

//距离平方 
int cmtdist(int a,int b){
	return (a-x)*(a-x)+(b-y)*(b-y);	
}

int main(){
	#ifdef debug
	freopen("dian.txt","r",stdin);
	#endif
	
	
	cin>>x>>y;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int nx,ny;
		cin>>nx>>ny;
		int ndist=cmtdist(nx,ny);
		allp.push_back(point(nx,ny,ndist));
//		point temp=point(nx,ny,ndist);
//		allp[i]=temp;
//		cout<<temp.x<<" "; 
	}
//	rep(n)
//		cout<<allp[i].x<<" ";
	
	sort(allp.begin(),allp.end(),cmp);
	for(int i=0;i<n;i++){
		if(i!=0) cout<<", ";
		printf("(%d,%d)",allp[i].x,allp[i].y);
	}
	
}





//结构体数组的赋值，结构体的初始化 
