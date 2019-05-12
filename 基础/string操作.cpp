#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define out(name,val)  cout<<name<<": "<<val<<endl;

//对于string的一些操作可以推广到其他STL的数据结构的操作，基本大同小异

int main() {
    //========================赋值========================
    string s1="abcdefghijklmnopqrstuvwxyz";
    string s2;
    s2.assign(s1,3,4);
    cout<<"assign: "<<s2<<endl;
    //========================长度 length和size皆可========================
    cout<<"length:"<<s1.length()<<" size: "<<s1.size()<<endl;
    //========================比大小，两个string可以比较大小,所以可以排序===================
    vector<string> vs={"I","am","tim","Zion","ppp"};
    sort(vs.begin(),vs.end());
    for(auto a:vs)
        cout<<a<<" ";
    //========================查找========================
    string s="abcdefgjijklmnopqrstuvwxyz";
    //从index=1位置开始找，返回efg第一次出现的下标，没找则到返回-1
    cout<<endl<<"find: "<<s.find("efg",1);  
    //反向查找str,rfind(str,pos);  从pos处开始从右往左查找返回第一次出现str的下标
    string ss1 = "ggabcdabcgggabcdefg";
    cout<<endl<<"rfind: "<<ss1.rfind("ggg",15);   //返回值为9
    //========================连接========================
    //使用append    //注意append不能是字符！！！！必须是字符串
    s="abc";
    s.append("a");   
    out("append",s);
    s.append(ss1,2,3);    //append还能在尾部加入一串其他字符串，从ss1的2位置开始3个字符
    out("append++",s);
    //使用+，+的拼接可以是字符
    out("+",s+'a');
    //========================两字符串交换======================================
    s1="first";
    s2="second";
    s1.swap(s2);
    out("s1",s1);
    out("s2",s2);
    //========================子串========================
    s="abcdefghijklmnopqrst";
    out("substr",s.substr(3,5));
    //========================替换========================
    s="abcdefghijklmnopqrst";
    s1="pppppppppppp";
    s.replace(2,3,s1);  //从2位置开始的3个字符被s1替换
    out("replace",s);
    //========================插入========================
    s="abcdefghijklmnopqrst";
    s1="pppppppppppp";
    s.insert(2,s1);    //在2位置处插入s1，原来2位置的被挪到后面
    out("insert",s);
    //========================删除========================
    s="abcdefghijklmnopqrst";
    s.erase(2,3);    //删除从2位置开始的3个字符
    out("delete",s);
    
}
