#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

#define debug

vector<string> res;



int main(){
	#ifdef debug
	freopen("2.txt","r",stdin);
	#endif
	
	string s;
	while(cin>>s){
		res.push_back(s);
	}
	int len=res.size();
	for(int i=len-1;i>=0;i--){
		if(i!=len-1) cout<<" ";
		cout<<res[i];
	}
		
	
}


//借机想到fgets读取，以及其他IO方法！！！！ 
