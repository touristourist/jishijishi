#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

//80分
//使用vector存放英雄和随从，insert和erase就不用考虑移动随从的问题 
//字符串分割使用strtok
//char[]字符数组转int使用sscanf(),反过来则使用sprintf() 

#define out(name,val) cout<<name<<": "<<val<<endl;
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a))
//#define debug

struct actor{
	int att,health,pos;
	actor(int _a,int _h,int _p):att(_a),health(_h),pos(_p) {}
	actor() {}
};

int n;
string op;
vector<actor> fact(1,actor(0,30,0)),lact(1,actor(0,30,0));   //初始化只有一个hero 
vector<string> opvs;
int owner=1;
int endofgame=0;

int str2int(string s){
//	char chnum[100]=s.c_str();   //字符数组的初始化1.要么用{}初始化 2.要么用memcpy复制或for赋值   
	char chnum[100];
//	memcpy(chnum,s.c_str(),sizeof(s.c_str()));
	strcpy(chnum,s.c_str());
	int res;
	sscanf(chnum,"%d",&res); 
	return res;
}

void operate(){
	opvs.clear();
	char opch[100];  
//	memcpy(opch,op.c_str(),sizeof(op.c_str()));   //不对, op.c_str()是一个指针变量，其size就是8 
	strcpy(opch,op.c_str());
//	printf("%s \n",op.c_str());
	char *head=strtok(opch," ");
	while(head!=NULL){
		opvs.push_back(head);
		head=strtok(NULL," ");
	}
	
//	rep(i,0,opvs.size()-1)
//		cout<<opvs[i]<<" ";
	
	int pos,att,heal,attker,defder;
//	vector<actor>::iterator it;
	if(opvs[0]=="summon"){
		pos=str2int(opvs[1]);
		att=str2int(opvs[2]);
		heal=str2int(opvs[3]);
		if(owner==1){
			fact.insert(pos+fact.begin(),actor(att,heal,pos));
//			out("factsize",fact.size());
		}
			
		else if(owner==-1){
			lact.insert(pos+lact.begin(),actor(att,heal,pos));
		}
			
	}
	else if(opvs[0]=="attack"){
		attker=str2int(opvs[1]);
		defder=str2int(opvs[2]);
		if(owner==1){
			int a1=fact[attker].att,&h1=fact[attker].health;
			int a2=lact[defder].att,&h2=lact[defder].health;
			h1-=a2;
			if(h1<=0) fact.erase(fact.begin()+attker);
			h2-=a1;
			if(h2<=0) {
				if(defder==0){
					endofgame=1;
					lact[0].health=0;
				} 
				else
					lact.erase(lact.begin()+defder);
			}			
		} 
		else if(owner==-1){
			int a1=lact[attker].att,&h1=lact[attker].health;
			int a2=fact[defder].att,&h2=fact[defder].health;
			h1-=a2;
			if(h1<=0) lact.erase(lact.begin()+attker);
			h2-=a1;
			if(h2<=0) {
				if(defder==0) {   //英雄死了不移动位置 
					endofgame=-1;
					fact[0].health=0;
				}
				else 
					fact.erase(fact.begin()+defder);
			}	
		}
		
	}
	else if (opvs[0]=="end")
		owner=-owner;
}

int main(){
	#ifdef debug
	freopen("chuanshuo.txt","r",stdin);
	#endif
	cin>>n;
	getchar();
	char temin[100];
	rep(i,1,n){
		fgets(temin,sizeof(temin),stdin);
		int len=strlen(temin);
		if(temin[len-1]=='\n') temin[len-1]='\0';
		op.assign(temin);
		if(endofgame!=0) ;
		else{
			operate();
//			out("op",endofgame);
		} 
	}
	if(fact[0].health==lact[0].health&&lact[0].health==0) endofgame=0; 
	
	cout<<endofgame<<endl;
	cout<<fact[0].health<<endl;
	cout<<fact.size()-1;
	rep(i,1,fact.size()-1)
		cout<<" "<<fact[i].health;
	cout<<endl;
	cout<<lact[0].health<<endl;
	cout<<lact.size()-1;
	rep(i,1,lact.size()-1)
		cout<<" "<<lact[i].health;
	cout<<endl;
	
	
} 
