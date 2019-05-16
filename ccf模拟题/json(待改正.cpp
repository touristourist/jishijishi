#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define out(name,val) cout<<name<<" :"<<val<<" "
#define outl(name,val) cout<<name<<" :"<<val<<endl;
#define debug

//一开始写搓了，以为要构造一个嵌套递归的hashmap，结果发现不能实现这个hashmap（大小不确定）
//其实这题的解法只需要搜索输入的字符串即可
//对于字符转中可能有"",所以不能用""来区别key


/*
class json         不能这样定义，因为json里面有map，map里面又有json，因为map不能确定大小，所以json也不能确定大小，这样的嵌套是错误的
{                  而对于与之类似的 链表的struct Node{int val; Node* pN;} 这里的指针的大小是确定的，所以Node的大小也是确定的，所以没错。
public:
    unordered_map<string,string> simhash;
    int recurtag;
    unordered_map<string,json> comhash;
    json() {}
    json(unordered_map<string,string> _sim,unordered_map<string,json> _com):simhash(_sim),comhash(_com) {}
};

typedef unordered_map<string,string> uss;
typedef unordered_map<string,json> usj;
*/


typedef pair<string,string> pss;

int  n,m;
vector<string> vsin;


void dealinput(string s)
{
//    out("s",s);
//    cout<<endl;
    char inch[200];
    strcpy(inch,s.c_str());
    char * head=strtok(inch,".");
    while(head!=NULL)
    {
        #ifdef debug
        out("head",head);
        #endif // debug
        vsin.push_back(head);

        head=strtok(NULL,".");
    }
}

string dealtrans(string s)
{
    int len=s.length();
    int i=-1;
    while((i=s.find("\\\\",i+1))!=-1)    //注意使用转义
    {
        s.replace(i,2,"\\");
    }
    while((i=s.find("\\\"",i+1))!=-1)
    {
        s.replace(i,2,"\'");
    }
    return s;
}

string findobj(int a,string str)   //a是左{ 下标
{

    int i=a,j=a;

    while(true)    //找到左右括号匹配的规律
    {
        i=str.find("{",i+1);
        j=str.find("}",j+1);
        if(i<j&&i!=-1)  //里面还有obj ,用stack求括号匹配
        {
            ;
        }
        else
            break;
    }
    //退出循环后j指示该obj的右括号}
    return str.substr(a,j+1-a);
}

bool judgekey(string k,string str,int i)
{
    int mao=str.find(":",i+1);
    int dou=str.find(",",i+1);
    if(dou>mao||(dou==-1&&mao!=-1))
        return true;
    else
        return false;

}

pss findkey(string k,string str)   //找出key对应的value
{
    if(str.find(k)==string::npos)
    {
        return pss("NOTEXIST","");
        cout<<"not1  ";
    }
    else
    {
        int i=str.find(k);
        while(judgekey(k,str,i)==false&&i!=-1)
        {
            i=str.find(k,i+1);
        }
        if(i==-1)
            return pss("NOTEXIST","");
        else  //i对应key的左引号 en是key的右引号
        {
            int en=str.find("\"",i+1);
            int a=str.find("{",i+1);
            int b=str.find("\"",en+1);
            if(a<b&&a!=-1)   //object
            {
                string res=findobj(a,str);
                return pss("OBJECT",res);
            }
            else    //string
            {
                int c=str.find("\"",b+1);
                string res=str.substr(b+1,c-b-1);
                return pss("STRING",res);
            }
        }
    }
}

string transback(string s){
    int i=-1;
    while((i=s.find("\'",i+1))!=-1){
        s.replace(i,1,"\"");
    }
    return s;
}

int main()
{
#ifdef debug
    freopen("json.txt","r",stdin);
#endif // debug

    cin>>n>>m;
    getchar();
    string totcontent;
    rep(i,1,n)
    {
        char strch[200];
        fgets(strch,sizeof(strch),stdin);
        string tem(strch);
        totcontent+=tem;
    }
    totcontent=dealtrans(totcontent);
    #ifdef debug
    cout<<totcontent;
    #endif


    rep(i,1,m)
    {
        string instr;
        cin>>instr;
//        outl("instr",instr);
        vsin.clear();
        dealinput(instr);

        //output
        int len=vsin.size();

        #ifdef debug
        for(int i=0; i<len; i++)
        {
            cout<<vsin[i]<<" ";
        }
        cout<<endl;
        #endif // debug

        for(int i=0; i<len; i++)
        {
            pss keyres;
            keyres=findkey(vsin[i],totcontent);
            if(keyres.first=="NOTEXIST"){
                cout<<"NOTEXIST1"<<endl;
                break;
            }
            else if(keyres.first=="OBJECT"&&i!=len-1) totcontent=keyres.second;
            else if(keyres.first=="STRING"&&i!=len-1){
                cout<<"NOTEXIST2"<<endl;
                break;
            }
            else if(keyres.first=="OBJECT"&&i==len-1){
                cout<<"OBJECT"<<endl;
            }
            else if(keyres.first=="STRING"&&i==len-1){
                cout<<"STRING "<<transback(keyres.second)<<endl;
            }

        }


    }

}


