#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a))
#define out(name,val) cout<<name<<" :"<<val<<" ";
#define outl(name,val) cout<<name<<": "<<val<<endl;
//#define debug

//注意点是replace替换string内容后会导致下标变化 ，所以是一次find紧接着一次replace，而不是find找到多个再replace！ 
//这里的结束标志</ul></p>等需要到下一行才能判断是否要添加，所以设置几种标志来判断 
vector<string> html;

int firstpara,lastpara; //lastpara说明上一行是para 

int firstlist,lastlist; 
//firstxxx判断起始符<p>,<ul>，lastxxx判断结束符<\p>,<\ul> 

char buffer[150];

string dealem(string s){
	int slen=s.length();
	int begin=s.find("_",0);
	int end;
	while(begin!=-1){
		s.replace(begin,1,"<em>");     
		//注意replace替换之后原来的下标会变化，所以end 的find放在replace之后，这样才没问题 
		end=s.find("_",begin+1);
		
		s.replace(end,1,"</em>");

		begin=s.find("_",end+1);

	}
	
	return s;
}

string deallink(string s){
	int begin=-1,end,be,en;
	while((begin=s.find("[",begin+1))!=-1){
		end=s.find("]",begin+1);
		be=s.find("(",end+1);
		en=s.find(")",be+1);

		string text=s.substr(begin+1,end-begin-1);  //要除去[]和()，所以要加一和减一 
		string link=s.substr(be+1,en-be-1);
		string rpcontent="<a href=\""+link+"\""+">"+text+"</a>";
		s.replace(begin,en+1-begin,rpcontent);

	}
	return s;
}

string deals(string s){

	string res=dealem(s);

	res=deallink(res);

	return res;
}

void dealhead(string s){
	int tag=0;
	int len=s.length();
	int begin=0,cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]=='#') cnt++;
		else if(s[i]==' ') tag=1;
		else if(tag==1&&s[i]!=' '&&s[i]!='#'){
			begin=i;
			break;
		}
	}
	string h=s.substr(begin,len-begin);
	
	h=deals(h);
	
	#ifdef notoj
	out("begin",begin);
	out("tag",tag);
	out("h",h);
	cout<<endl;
	#endif
	char num[10];
	sprintf(num,"%d",cnt);
	string snum(num);
	string content="<h"+snum+">";
	content=content+h+"</h"+snum+">";
	html.push_back(content);
}

void dealpara(string s){
	s=deals(s);

	if(firstpara==1){
		string content="<p>"+s;
		html.push_back(content);
		firstpara=0;
		lastpara=1;
	}
	else if(firstpara==0){
		html.push_back(s);
	}
}

void deallist(string s){
	int tag=0,slen=s.length(),begin=0;
	for(int i=0;i<slen;i++){
		if(s[i]==' ') tag=1;
		else if(tag==1&&s[i]!=' '){
			begin=i;
			break;
		}
	}
	string content=s.substr(begin,slen-begin);
	content=deals(content);

	if(firstlist==1){
		html.push_back("<ul>");
		html.push_back("<li>"+content+"</li>");
		firstlist=0;
		lastlist=1;
	}
	else if(firstlist==0){
		html.push_back("<li>"+content+"</li>");
	}
}



int main(){
	#ifdef debug
	freopen("markdown.txt","r",stdin);
	#endif
		
	firstpara=1,lastpara=0;
	firstlist=1,lastlist=0;
	while(fgets(buffer,sizeof(buffer),stdin)){
		int slen=strlen(buffer);
		if(slen==1&&buffer[0]=='\n'){  //空行处理 
			if(lastpara==1){        //给上一行添结束符/ 
				int nowlen=html.size();
				html[nowlen-1].append("</p>");
				lastpara=0;
				firstpara=1;
			}
			else if(lastlist==1){    
				html.push_back("</ul>");
				lastlist=0;
				firstlist=1;
			}
			continue; 
		} 
		if(buffer[slen-1]=='\n')	buffer[slen-1]='\0';   //fgets吃回车 
		string instr(buffer);
		char fch=buffer[0];
		if(fch=='#'){ //head
			if(lastpara==1){  //给上一行添结束符/ 
				int nowlen=html.size();
				html[nowlen-1].append("</p>");
				lastpara=0;
				firstpara=1;
			}
			else if(lastlist==1){
				html.push_back("</ul>");
				lastlist=0;
				firstlist=1;
			}
			dealhead(instr);
		}
		else if(fch=='*'){ //list
			if(lastpara==1){  //给上一行添结束符/ 
				int nowlen=html.size();
				html[nowlen-1].append("</p>");
				lastpara=0;
				firstpara=1;
			}	
			//因为这行是* 所以不用判断上一行是否要添加</ul> 
			deallist(instr);
		}
		else{  //text
			dealpara(instr);
		}
		
	}
	//输入的最后一行的处理 
	if(lastpara==1){  //给上一行添结束符/ 
		int nowlen=html.size();
		html[nowlen-1].append("</p>");
		lastpara=0;
		firstpara=1;
	}
	else if(lastlist==1){
		html.push_back("</ul>");
		lastlist=0;
		firstlist=1;
	}
			
	int vlen=html.size();
	for(int i=0;i<vlen;i++)
		cout<<html[i]<<endl;
}
