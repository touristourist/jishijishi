#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

//8 queens question (backtrack) uses dfs method

#define rep(i,s,t) for(int i=s;i<=t;i++)

typedef pair<int,int> pint;
const int N=8;
int array[N];
int cnt=0;

void output(){    //output chess board
	rep(i,0,N-1){
		rep(j,0,N-1){
			if(j!=0) printf(" ");
			if(array[j]==i)	printf("1");
			else printf("0");
		}
		printf("\n");
	}
}

bool checksafe(pint posi){
	//验证的col列之前的是否又冲突，因为放的顺序是按照0~N-1列的 
	int row=posi.first,col=posi.second;
	rep(i,0,col-1){
		//传入的参数保证了列数不会相同 
		if(array[i]==row) return false;
		if(abs(row-array[i])==abs(col-i)) return false;
	}
	return true;
}
void dfsPlace(int depth){  //depth=0~7,
	if(depth>=8){
		printf("No. %d\n",++cnt);
		output();
		return;
	}
	else{
		rep(j,0,N-1)
			if(checksafe(make_pair(j,depth))) {
				array[depth]=j;
				dfsPlace(depth+1);
			}	
	}
}

int main(){
	dfsPlace(0);
}
