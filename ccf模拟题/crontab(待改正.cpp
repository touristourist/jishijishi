#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>

using namespace std;


#define long long ll
#define rep(i,s,t) for(int i=s;i<=t;i++)
//#define debug
#define out(name,val) cout<<name<<" :"<<val<<" "
#define outl(name,val) cout<<name<<" : "<<val<<endl;
#define outc(n) cout<<n<<endl;

int mm[]= {31,29,31,30,31,30,31,31,30,31,30,31};
int notrun[]= {0,31,59,90,120,151,181,212,243,273,304,334,365};
int run[]= {0,31,60,91,121,152,182,213,244,274,305,335,366};

class dealweek
{
	public: 
    string datetime;   //包括时、分
    dealweek() {}
    dealweek(string s):datetime(s) {}
    void setweek(string s)
    {
        datetime=s;
    }
    int resweek()   //计算星期几
    {
//    	outl("datetime",datetime);
        int year,month,day;
        string ystr=datetime.substr(0,4);
        string mstr=datetime.substr(4,2);
        string dstr=datetime.substr(6,2);
        sscanf(ystr.c_str(),"%d",&year);
        sscanf(mstr.c_str(),"%d",&month);
        sscanf(dstr.c_str(),"%d",&day);
        int runcnt=0;
        for(int i=1970; i<=year-1; i++)
            if(isrunyear(i)) runcnt++;
        int psum=365*(year-1970)+runcnt;
        int lsum=0;  //最后一年的天数
        if(month<=2) lsum=notrun[month-1]+day;
        else if(month>2)
        {
            lsum=notrun[month-1]+day;
            if(isrunyear(year)) lsum+=1;
        }
        
//        cout<<year<<" "<<month<<" "<<day<<endl;
        
        int totsum=psum+lsum;
        int res=(totsum-1+4)%7;
        return res;
    }
    bool isrunyear(int y)
    {
        if((y%4==0&&y%100!=0)||y%400==0) return true;
        else return false;
    }
};


class crontab
{
public:
    set<int> minute;
    set<int> hour;
    set<int> day;
    set<int> month;
    set<int> week; //鏄熸湡鍑犻檺鍒?
    string command;
    vector<set<int> > tot;
    crontab(vector<set<int> > cv,string com)
    {
        tot=cv;
        minute=cv[0];
        hour=cv[1];
        day=cv[2];
        month=cv[3];
        week=cv[4];
        command=com;
    }
    crontab() {}
};
class datetime
{
public:
    string dtime;
    string lowbound,upbound;
    datetime(string _d,string l,string u):dtime(_d),lowbound(l),upbound(u) {}
    datetime() {}
    void settime(int m,int d,int h,int mi)
    {
//        char ych[10];
//        sprintf(ych,"%d",y);
//        string ystr(ych);
        string ystr=dtime.substr(0,4);

        char mch[10];
        sprintf(mch,"%d",m);
        string mstr(mch);
        if(m<10) mstr.insert(0,"0");

        char dch[10];
        sprintf(dch,"%d",d);
        string dstr(dch);
        if(d<10) dstr.insert(0,"0");

        char hch[10];
        sprintf(hch,"%d",h);
        string hstr(hch);
        if(h<10) hstr.insert(0,"0");

        char mich[10];
        sprintf(mich,"%d",mi);
        string mistr(mich);
        if(mi<10) mistr.insert(0,"0");

        dtime=ystr+mstr+dstr+hstr+mistr;
    }
    bool inrange()
    {
        if(dtime>=lowbound&&dtime<upbound) return true;
        else return false;
    }
    void addyear()
    {
        string ys=dtime.substr(0,4);
        int yea;
        sscanf(ys.c_str(),"%d",&yea);
        yea++;
        char ych[10];
        sprintf(ych,"%d",yea);
        string ly(ych);
        dtime.replace(0,4,ly);
    }

};



//鍒濆鍖栨椂閿€煎涔嬮棿浣跨敤閫楀彿鑰屼笉鏄啋鍙?
map<string,string> weekmap= {{"Sun","0"},{"Mon","1"},{"Tue","2"},{"Wed","3"},{"Thu","4"},{"Fri","5"},{"Sat","6"}};
map<string,string> monthmap= {{"Jan","1"},{"Feb","2"},{"Mar","3"},{"Apr","4"},{"May","5"},{"Jun","6"},{"Jul","7"},{"Aug","8"},{"Sep","9"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};

 //瑕佸厛鍘婚櫎鍓嶅0锛岃浆鎹ONda
crontab parseinput(vector<string> ins) {
	string minu=ins[0],hour=ins[1],day=ins[2],mon=ins[3],week=ins[4];
	vector<set<int> > cv(5);
	string com=ins[5];
	//   	rep(i,0,ins.size()-1) out("ins",ins[i]);
	for(int i=0; i<5; i++)
	{
	    string dstr=ins[i];
	    if(dstr.find("*")!=string::npos)  // *
	    {
	//        outc(-1);
	        switch(i)
	        {
	        case 0:  //minute
	            rep(j,0,59)  cv[0].insert(j);
	            break;
	        case 1:  //hour
	            rep(j,0,23) cv[1].insert(j);
	            break;
	        case 2:  //day
	            rep(j,1,31) cv[2].insert(j);
	            break;
	        case 3: //month
	            rep(j,1,12) cv[3].insert(j);
	            break;
	        case 4:   //week
	            rep(j,0,6) cv[4].insert(j);
	            break;
	        }
	//            outc(1);
	    }
	    else if(dstr.find(",")!=string::npos)
	    {
	//        	outc(-2);
	        char chs[200];
	        strcpy(chs,dstr.c_str());
	        char *head=strtok(chs,",");
	        while(head!=NULL)
	        {
	            string stem(head);
	            if(stem.find("-")!=string::npos)
	            {
	                int div=stem.find("-");
	                string be=stem.substr(0,div),en=stem.substr(div+1,stem.length()-div-1);
	                int beint,enint;
	                sscanf(be.c_str(),"%d",&beint);
	                sscanf(en.c_str(),"%d",&enint);
	                for(int j=beint; j<=enint; j++)   cv[i].insert(j);  // 灏唙ector鏀规垚set,淇濊瘉涓嶉噸澶?
	            }
	            else
	            {
	                int numb;
	                sscanf(head,"%d",&numb);
	                cv[i].insert(numb);
	            }
	            head=strtok(NULL,",");
	        }
	//			outc(2);
	    }
	    else
	    {
	//        	outc(-3);
	        string stem(dstr);
	        if(stem.find("-")!=string::npos)
	        {
	//            	outc(3);
	            int div=stem.find("-");
	            string be=stem.substr(0,div),en=stem.substr(div+1,stem.length()-div-1);
	            int beint,enint;
	            sscanf(be.c_str(),"%d",&beint);
	            sscanf(en.c_str(),"%d",&enint);
	            for(int j=beint; j<=enint; j++)   cv[i].insert(j);  // 灏唙ector鏀规垚set,淇濊瘉涓嶉噸澶?
	
	        }
	        else
	        {
	//            	outc(4);
	            int numb;
	            sscanf(stem.c_str(),"%d",&numb);
	            cv[i].insert(numb);
	        }
	
	    }
	
		}
	
		crontab restab(cv,com);
		return restab;
}

vector<string> dealinput() { //鍓嶅0鍙互涓嶅鐞嗭紝鍥犱负鍦╬arseinput涓殑sprintf浼氬拷?
	vector<string> vs;
	string st;
	rep(i,1,5)
	{
	    cin>>st;    //澶勭悊瀛楁瘝绗﹀彿Monday..
	    for(auto it=weekmap.begin(); it!=weekmap.end(); it++)
	        if(st.find(it->first)!=string::npos)
	            st.replace(st.find(it->first),3,it->second);
	    for(auto it=monthmap.begin(); it!=monthmap.end(); it++)
	        if(st.find(it->first)!=string::npos)
	            st.replace(st.find(it->first),3,it->second);
	    vs.push_back(st);
	}
	cin>>st;
   vs.push_back(st);
//   rep(i,0,vs.size()-1) out("vs[i]",vs[i]);
//   outc('\n');
   return vs;
}



   typedef pair<string,string> pss;

   int n;
   string s,t;
   vector<pss> result;


int main()
{
#ifdef debug
    freopen("crontab.txt","r",stdin);
#endif // debug

    cin>>n>>s>>t;
    vector<crontab> vcron;
    rep(i,1,n)
    {
        vector<string> vtem=dealinput();
        vcron.push_back(parseinput(vtem));
    }

//    dealweek dwk;    测试 
//    dwk.setweek("20190516");
//    cout<<"weasdfsadf:   "<<dwk.resweek()<<endl;
	
//	set<int> sint=vcron[0].tot[4];    检查set的内容 
//	for(auto it=sint.begin();it!=sint.end();it++)
//		cout<<*it<<" ";


//	datetime dtt(s,s,"201712312352");
//	cout<<dtt.dtime<<endl;
//	dtt.addyear();
//	cout<<dtt.dtime<<endl;
//	cout<<dtt.inrange()<<endl;
//	dtt.settime(1,2,3,4);
//	cout<<dtt.dtime<<endl;
//
//	cout<<"ssssssssss\n"; 

    for(int i=0; i<n; i++)
    {
        crontab temtab=vcron[i];
        datetime dt(s,s,t);
        vector<set<int> > vset=temtab.tot;
        
        
        while(dt.inrange())
        {
            for(auto it1=vset[3].begin(); it1!=vset[3].end(); it1++){//month
				for(auto it2=vset[2].begin(); it2!=vset[2].end(); it2++) { //day      
                	for(auto it3=vset[1].begin(); it3!=vset[1].end(); it3++) {//hour    注意it不要写成其他的it（死循环 
                    	for(auto it4=vset[0].begin(); it4!=vset[0].end(); it4++) {	//minute
                        
                        	  //需要判断星期是否符合
                            int mo=*it1,d=*it2,h=*it3,mi=*it4;
//                            printf("%d %d %d %d \n",mo,d,h,mi);
//                            getchar();
                            dt.settime(mo,d,h,mi);
//                            cout<<"dt ";
//                            out(dt.dtime,dt.inrange());
//                            cout<<endl;
							dealweek dwk;
							dwk.setweek(dt.dtime);
							int weeknum=dwk.resweek();
                            if(dt.inrange()&&vset[4].find(weeknum)!=vset[4].end())  //筛选星期几 
                            {
                            	result.push_back(pss(dt.dtime,temtab.command));
                            }
                            else continue;
                        }
                    }
                    
                }
                
			}      
                        
            dt.addyear();
        }
        //排序
        int rlen=result.size();
        for(int i=rlen-2; i>=0; i--)
            for(int j=0; j<=i; j++)
            {
                if(result[j].first>result[j+1].first)
                {
                    pss temp=result[j];
                    result[j]=result[j+1];
                    result[j+1]=temp;
                }
            }
    }
	
	rep(i,0,result.size()-1){
		cout<<result[i].first<<" "<<result[i].second<<endl;
	}


#ifdef debugoj
    for(int i=0; i<vcron.size(); i++)
    {
        cout<<vcron[i].command<<" ";
    }
#endif // debug

}
