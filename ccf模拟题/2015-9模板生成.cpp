#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

//str.find(st,n),  str.replace ：replace后字符串长度可能变化  ，hashmap 

//#define debug
#define rep(i,t) for(int i=0;i<t;i++)
#define out(name,val) cout<<"name: "<<val<<endl;
int m,n;
vector<string> moban;
unordered_map<string,string> hashmap;


void replace(int i){
	//	string::npos  的类型是string::size_type ,所以不能用int来接收str.find()的返回值 
	//正确做法-直接比较
	string st=moban[i];
	int sindex=-1,eindex=0;
	while(st.find("{{",sindex+1)!=string::npos){  //find(str,n)从n下标开始找str位置 
		sindex=st.find("{{",sindex+1);
		eindex=st.find("}}",sindex+1);
		string keyname=st.substr(sindex+3,eindex-1-sindex-3);
//		out(keyname,keyname);
		unordered_map<string,string>::iterator it;
		it=hashmap.find(keyname);
		if(it!=hashmap.end()){
			st.replace(sindex,eindex+2-sindex,it->second);   //str.replace()替换字符串的部分 
			//注意replace替换后，字符串的长度可能会变化，所以先在st上变换，最后再用st替换moban[i] 
			
		}
		else {
			st.replace(sindex,eindex+2-sindex,"");
		}
	}
	moban[i]=st;
}


int main(){
	#ifdef debug
	freopen("20159.txt","r",stdin);
	#endif
	
	scanf("%d%d",&m,&n);
	getchar();  //getline会吃回车 
	rep(i,m){
		string st;
		getline(cin,st);
		moban.push_back(st);
	}
	rep(i,n){
		string st;
		getline(cin,st);
		int stlen=st.length();
		int index=st.find(' ');  //使用find查找字符第一个出现的位置 
		string key=st.substr(0,index);
		string value=st.substr(index+2,stlen-1-index-2);
		hashmap[key]=value;

	}
	int len=moban.size();
	rep(i,len){
		//search and replace content in {{ }} if exists
		replace(i); 
	}
	#ifdef notoj
	unordered_map<string,string>::iterator it=hashmap.begin();
	while(it!=hashmap.end()){
		cout<<it->second<<endl;
		it++;
	}
	#endif
	
	rep(i,len){
		cout<<moban[i]<<endl;
	}	
}
