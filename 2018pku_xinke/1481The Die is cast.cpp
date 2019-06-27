#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

//#define debug

//对于相邻的X只能算一个，所以一找到一个X之后从这个X出发再dfs消除相连的X 。
 

int w,h;
char g[100][100];
int vis[100][100];
vector<int> vnum;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
int number=0;

void dfsX(int i,int j){
	g[i][j]='*';
	for(int index=0;index<4;index++){
		int ni=i+di[index],nj=j+dj[index];
		if(ni>=0&&ni<h&&nj>=0&&nj<w&&g[ni][nj]=='X')
			dfsX(ni,nj);
	}
}


void dfs(int i,int j){
	vis[i][j]=1;
	
	if(g[i][j]=='X'){
		number++;
		//清除这个X相连的X,变成* 
		dfsX(i,j);
		g[i][j]='X';
	}
	
 	for(int index=0;index<4;index++){
		int ni=i+di[index],nj=j+dj[index];
		if(ni>=0&&ni<h&&nj>=0&&nj<w&&g[ni][nj]!='.'&&vis[ni][nj]==0){
			dfs(ni,nj);
		}
		
	}
}

int main(){
	#ifdef debug
	freopen("1481.txt","r",stdin);
	#endif
	int cnt=1;
	
	while(cin>>w>>h&&w&&h){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			cin>>g[i][j];
		}
		
		vnum.clear();  //对于全局变量注意重置！！！！！
		
		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			if(g[i][j]!='.'&&vis[i][j]==0){
				number=0;
				dfs(i,j);
				vnum.push_back(number);
			}
		}
		
		sort(vnum.begin(),vnum.end());
		cout<<"Throw "<<cnt++<<endl;
		for(int i=0;i<vnum.size();i++)
			cout<<vnum[i]<<" ";
		cout<<endl<<endl;
		 
	}	
	
}
