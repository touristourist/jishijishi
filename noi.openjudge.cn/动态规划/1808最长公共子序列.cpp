#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

#define rep(i,k) for(int i=0;i<k;i++)
#define max(x,y) x>y?x:y
const int N=205;
int lcsLen[N][N];

int main(){
	string x,y;
	while(cin>>x>>y){
		rep(i,N){
			lcsLen[0][i]=0;
			lcsLen[i][0]=0;
		}
		int xlen=x.length(),ylen=y.length();
		for(int i=1;i<=xlen;i++)
		for(int j=1;j<=ylen;j++)
		{
			if(x[i-1]==y[j-1])	//string中 x和y 的下标从0开始 
				lcsLen[i][j]=lcsLen[i-1][j-1]+1;
			else if(x[i-1]!=y[j-1])
				lcsLen[i][j]=max(lcsLen[i-1][j],lcsLen[i][j-1]);
		}
		printf("%d\n",lcsLen[xlen][ylen]);
	}
	
}
