#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map> 

using namespace std;

//vector 的insert()用于插入另一个vector
//hashmap的使用，用于查询
//对于有冒号的权限的输入，将权限保存时要去掉冒号！
 

#define rep(i,s,t) for(int i=s;i<=t;i++)
//#define debug
#define out(name,val) cout<<name<<" :"<<val<<endl
 
class Priv{
	public:
		string name;
		bool islevel;  //该权限是否有等级 
		int totlevel;
		Priv(string s,bool il,int tl):name(s),islevel(il),totlevel(tl) {}
		Priv() {}
};
class Role{
	public:
	string name;
	vector<Priv> vp;
	Role(string s,vector<Priv> _vp):name(s),vp(_vp) {}
	Role() {}
};

class User{
	public:
	string name;
	vector<Role> vr;
	unordered_map<string,Priv> hmap;
	User(string s,vector<Role> _vr){
		name=s;
		vr=_vr;
		unordered_map<string,Priv>::iterator it;
		int rlen=vr.size();
		for(int i=0;i<rlen;i++){
			vector<Priv> temp=vr[i].vp;
			int plen=temp.size();
			for(int j=0;j<plen;j++){
				string hpname=temp[j].name;
				it=hmap.find(hpname);
				if(it==hmap.end()){
					hmap[hpname]=temp[j];
				}
				else{  //之前有该权限 
					if(temp[j].islevel==true){
						int ex=hmap[hpname].totlevel,now=temp[j].totlevel;
						if(now>ex) hmap[hpname]=temp[j];
					}
				}
			}
		}
	}
	User() {}
};



int p,r,u,q;
unordered_map<string,User> sUmap;
unordered_map<string,Role> sRmap;


Priv privin(string s){     //对于权限中冒号的处理 
	vector<string> vs;
	char chin[100];
	strcpy(chin,s.c_str());
	char * head=strtok(chin,":");
	while(head!=NULL){
		vs.push_back(head);
		head=strtok(NULL,":");
	}
	int leng=vs.size();
	
	if(leng==1){
		Priv resp(vs[0],false,0);
		return resp;
	}
	else if(leng==2){
		int lev;
//		char intstr[20];
//		strcpy(intstr,vs[1].c_str());   sscanf可以用c_str，只是char[]不能用c_str初始化 
		sscanf(vs[1].c_str(),"%d",&lev);   ////////////////////////-  &符号！！！和scanf一样  
//		out("lev",lev);	
		Priv resp(vs[0],true,lev);
	
		return resp;
	}
	else out("error",404);
}

int search(string user,string s){  //搜索查询的结果 
	vector<string> vs;
	char chpr[100];
	strcpy(chpr,s.c_str());
	char *head=strtok(chpr,":");
	while(head!=NULL){
		vs.push_back(head);
		head=strtok(NULL,":");
	}
	unordered_map<string,User>::iterator it;    //it->first  ,it->second分别表示string,user 
	it=sUmap.find(user);
//	out("user",user);
	if(it==sUmap.end()) return -100;  //-10x表示false 
	int vlen=vs.size();
	unordered_map<string,Priv>::iterator itt;
	itt=(it->second).hmap.find(vs[0]);
	if(itt==(it->second).hmap.end()) return -101;
	Priv tp=itt->second;
	if(vlen==1){
		if(tp.islevel==false) return -2;  //-2表示成功
		else if(tp.islevel==true) return tp.totlevel; 
	}
	else if(vlen==2){
		if(tp.islevel==false) return -103;
		else if(tp.islevel==true){
			int v1;
//			char intstr[20];
//			strcpy(intstr,vs[1].c_str());    sscanf可以用c_str() 
			sscanf(vs[1].c_str(),"%d",&v1);
			
//			cout<<"tp: "<<tp.totlevel<<" v1: "<<v1<<endl;
			if(tp.totlevel>=v1) return -2;
			else return -105;
		} 
	}
}

int main(){
	#ifdef debug
	freopen("cha.txt","r",stdin);
	#endif
	
	cin>>p;
	rep(i,1,p){
		string pr;
		cin>>pr;
		vector<string> temvs;
//		temvs=privin(pr);       此分支无用 
	}
	cin>>r;
	rep(i,1,r){
		string rolename;
		cin>>rolename;
		int times;
		cin>>times;
		vector<Priv> vp;
		string pri;
		
		rep(j,1,times){
			cin>>pri;
			vp.push_back(privin(pri));
			
		}
		int ind=rolename.find(":");    //是rolename不是pri！！！ 
		if(ind!=-1) rolename=rolename.substr(0,ind);
		unordered_map<string,Role>::iterator it;
		it=sRmap.find(rolename);
//		if(it==sRmap.end())
		sRmap[rolename]=Role(rolename,vp);  //角色都是不同名 
	}
	
	cin>>u;
	rep(i,1,u){
		string usname;
		cin>>usname;
		int times;
		cin>>times;
		string rolname;
		vector<Role> vpp;
		rep(j,1,times){
			cin>>rolname;
			int ind=rolname.find(":");
			if(ind!=-1) rolname=rolname.substr(0,ind);
			vpp.push_back(sRmap[rolname]);
//			out("rolname",rolname);
		}
		sUmap[usname]=User(usname,vpp);
//		cout<<"vpp: ";
//		for(int i=0;i<vpp.size();i++)
//			cout<<vpp[i].name<<" ";
//		cout<<endl;
	}
	cin>>q;
	rep(i,1,q){
		string usname;
		cin>>usname;
		string pr;
		cin>>pr;
		int result=search(usname,pr);
//		out("result",result);
//		cout<<result<<" ";  查是哪个分支出的结果 
		if(result<-2) printf("false\n");
		else if(result==-2) printf("true\n");
		else printf("%d\n",result);
	}
	
	#ifdef debug
	unordered_map<string,User>::iterator its;
	for(its=sUmap.begin();its!=sUmap.end();its++){
		cout<<(its->second).name<<" ";
		unordered_map<string,Priv>::iterator ig=its->second.hmap.begin();
		for(;ig!=its->second.hmap.end();ig++)
			cout<<ig->second.name<<"  ";
	}	
	cout<<endl;
	unordered_map<string,Role>::iterator itr;
	for(itr=sRmap.begin();itr!=sRmap.end();itr++)
		cout<<itr->first<<"  ";
	cout<<endl;
	#endif
}
