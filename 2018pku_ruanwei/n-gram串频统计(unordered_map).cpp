#include<iostream>
#include<cstdio>
#include<unordered_map>   //hash_map 

using namespace std;

//注意这里的unorderd_map的使用  unordered_map<string,int> hashmp     hashmp.find(str)返回的是iterator 
//c++中的hash_map可能不具有平台兼容性，所以推荐使用unordered_map(c++11) 
#define debug
#define max(x,y) (x)>(y)?(x):(y)

struct point{
	string s;
	int times;
	point(string _s,int _t):s(_s),times(_t) {}
	point() {}
};


point sta[700];

int main(){
	#ifdef debug
	freopen("2.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	string s;
	cin>>s;
	int len=s.length();
	unordered_map<string,int> hashmp;
	int lastp=0;
	int maxt=0,kinds=0;
	for(int i=0;i<=len-n;i++){
		string st=s.substr(i,n);
		unordered_map<string,int>::iterator iter;
		iter=hashmp.find(st);
		if(iter==hashmp.end()){
			sta[lastp]=point(st,1);
			hashmp[st]=lastp;
			kinds++;
			lastp++;
		}
		else{
			int ind=iter->second;
			sta[ind].times++;
			maxt=max(maxt,sta[ind].times);	
		} 
	}
	
	printf("%d\n",maxt);
	for(int i=0;i<kinds;i++){
		if(sta[i].times==maxt)
			cout<<sta[i].s<<endl;
	}
	for(int i=0;i<kinds;i++){
		cout<<"str: "<<sta[i].s<<" times: "<<sta[i].times<<endl;
	}
	
	
	
}
