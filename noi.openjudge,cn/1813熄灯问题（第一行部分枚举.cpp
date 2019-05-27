#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//一个开关最多按一次，且开关按的顺序无所谓，所以开关的结果一定有且是唯一的！！！ 

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a))
//#define debug
#define outc(na) cout<<na<<" ";

int deng[50][50],kai[50][50];
int tem[50][50];   //deng[][]保存原始灯，tem[][]用于保存当前按的灯 

void op(int i,int j){
	tem[i][j]=!tem[i][j];  //0的非就是1
	int di[]={-1,1,0,0};
	int dj[]={0,0,-1,1};
	for(int k=0;k<4;k++){  //遍历上下左右四个点的方式！！！！！！ 
		int dii=di[k],djj=dj[k];
		int ni=i+dii,nj=j+djj;
		if(ni>=1&&ni<=5&&nj>=1&&nj<=6)
			tem[ni][nj]=!tem[ni][nj];
	}
}

bool solve(){
	//按照第一行开关按
	for(int i=1;i<=6;i++){
		if(kai[1][i]) op(1,i);
	}
	//从第二行开关开始，每行的目标都是把上一行的灯按灭 
	//思想是：上一行开关怎么按已经无法改变，要想上一行灯灭只能靠这行开关了 
	for(int i=2;i<=5;i++){
		for(int j=1;j<=6;j++){
			if(tem[i-1][j]){
				op(i,j);
				kai[i][j]=1;
			} 
			else kai[i][j]=0;   //注意因为kai[]每次不memset，所以要明确赋值1/0 
		}
	}
	bool res=true;
	for(int i=1;i<=6&&res;i++)  //之前都是只顾让上一行灯灭，这样前四行一定是全灭的，只要第五行全灭就成功 
		if(tem[5][i]) res=false;
	return res;
}


int main(){
	#ifdef debug
	freopen("1813.txt","r",stdin);
	#endif
//	cout<<"afd";
//	outc("af");
	mst(deng);
	mst(kai);
	mst(tem);
	rep(i,1,5)
	rep(j,1,6){
		cin>>deng[i][j];
		tem[i][j]=deng[i][j];
	}
	

	for(int i=0;i<64;i++){  //枚举第一行 
		for(int j=0;j<6;j++){
			int thisbit=1<<j;
			if(i&thisbit) kai[1][j+1]=1;
			else kai[1][j+1]=0;
		}
	
		if(solve()) break; 
	
		//一次判断后tem[][]原始灯的结果已经按乱需要重置成原始值 
		for(int i=1;i<=5;i++)
		for(int j=1;j<=6;j++)
		tem[i][j]=deng[i][j];
	}
	
	for(int i=1;i<=5;i++){
		for(int j=1;j<=6;j++)
			cout<<kai[i][j]<<" ";
		cout<<endl;
		}
	
	
	

}
