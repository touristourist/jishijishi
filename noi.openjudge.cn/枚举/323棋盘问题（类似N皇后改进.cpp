#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//只有在#区域中才能摆放棋子 
//由于没有空白行/空白列，所以每一列都至少有一个放棋子的位置
//类似N皇后，但有不同：只有#能放，以及不是每列都一定要放
//借鉴N皇后的方法，按列从左到右处理 
//这里使用dfs(i,j)表示当前是处理放第i个棋子（i=0~n-1),且当前应该从第j列开始放
//方法数目有点类似于组合数 

//#define debug
int n,k;
char bod[20][20];

int rowlist[20];  //下标0~n         rowlist[i]放第i列的行数 

bool check(int i,int ind){  //ind表示处理到 第ind列 
	for(int ii=0;ii<ind;ii++){
		if(rowlist[ii]==i) return false;
	}
	return true;
}

void put(int i,int j){
	
}

int cnt;

void dfs(int i,int nowcol){   //下从左往右数的第i颗棋子( i=0~n-1 )，但不一定在第i列 
	if(i>=k){ 
		cnt++;
		return ;
	} 
	for(int col=nowcol;col<=n-k+i;col++)  //从当前列nowcol到n-k+i是第i个棋子能放的列的范围 
	for(int ii=0;ii<n;ii++){
		if(check(ii,col)&&bod[ii][col]=='#'){
			rowlist[col]=ii;
			dfs(i+1,col+1);
			rowlist[col]=-1;    //该位置放完后复位，准备放此列下一个位置 
		} 
	}
}

int main(){
	#ifdef debug
	freopen("323.txt","r",stdin);
	#endif
	
	while(cin>>n>>k&&n!=-1&&k!=-1){
		cnt=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>bod[i][j];
		
			memset(rowlist,-1,sizeof(rowlist));
			dfs(0,0);
		
			
		cout<<cnt<<endl;
	}
	
	
}
