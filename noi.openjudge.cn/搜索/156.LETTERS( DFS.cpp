#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>

using namespace std;
#define max(x,y) x>y?x:y
//#define debug
#define outky(name,val) cout<<name<<" :"<<val<<" ";
#define out(a) cout<<a<<" "

//找的是最长路径长度，想到用dfs的回溯求出这个过程中的最长路径 

set<char> exletter;
int visit[50][50];
char g[50][50];
int maxstep;
int r,c;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

void dfs(int i,int j,int step){
	maxstep=max(maxstep,step);
	exletter.insert(g[i][j]);
	visit[i][j]=1;
	
//	out(i);
//	out(j);
//	out(g[i][j]);
//	outky("step",step);
//	cout<<"          exletter:   ";
//	for(auto it=exletter.begin();it!=exletter.end();it++)
//		cout<<*it<<" ";
//	cout<<endl;

///当时循环变量随便取了一个变量名c，结果就刚好和行数c变量弄混了，后来改成index就没问题 ==  所以变量名要慎重！！！ 
	for(int index=0;index<4;index++){    
		int ni=i+di[index],nj=j+dj[index];
//		printf("(%d,%d,%d)",ni,nj,ni>=0&&ni<r&&nj>=0&&nj<c);
		if(ni>=0&&ni<r&&nj>=0&&nj<c){
//			cout<<g[ni][nj]<<" ";
//			cout<<visit[ni][nj]<<" ";
//			for(auto it=exletter.begin();it!=exletter.end();it++)
//				cout<<*it<<" ";
//			cout<<endl;
			
			if(visit[ni][nj]!=1&&exletter.find(g[ni][nj])==exletter.end()){
//				cout<<g[ni][nj]<<" "<<visit[ni][nj]<<" ";
				dfs(ni,nj,step+1);
				visit[ni][nj]=0;
				exletter.erase(g[ni][nj]);
			}
		
		}
		
	}
}

int main(){
	#ifdef debug
	freopen("156.txt","r",stdin);
	#endif
	
	cin>>r>>c;
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++){
		cin>>g[i][j];
	}
	memset(visit,0,sizeof(visit));
	dfs(0,0,1);
	cout<<maxstep<<endl;
}
