#include<iostream>
#include<cstdio>
#include<cstring> 

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a))

char out[85][30];
int numarr[26];


int main(){
//	freopen("2800.txt","r",stdin);
	
	
	mst(numarr);
	rep(i,0,84)
	rep(j,0,25){
		out[i][j]=' ';
		if(i==84)	out[i][j]=char('A'+j);
	}
	string s;
	int maxrow=-1;
	while(cin>>s){
		int len=s.length();
		rep(i,0,len-1)
			if(s[i]>='A'&&s[i]<='Z'){
				numarr[s[i]-'A']++;
				int row=numarr[s[i]-'A'];
				maxrow=maxrow>row?maxrow:row;
				out[84-row][s[i]-'A']='*';
			}
	}
	
	rep(i,84-maxrow,84){
		rep(j,0,25){
		if(j!=0) printf(" ");
		printf("%c",out[i][j]);
		}
		printf("\n");
	}
	
}
