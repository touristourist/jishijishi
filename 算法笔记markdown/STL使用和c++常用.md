```
字体：consolas
字号：11
devcpp支持c++11的命令 ：-std=c++11
```



# Stack

```c++
#include<stack>

stack<TYPE> StackName;
bool empty();
void pop();
void push(const TYPE &val);
TYPE &top();
size_type size();
```





# Vector

```c++
#inlcude<vector>

vector<int> v={1,2,3};
a=1,b=2,c=3;
vector<int> v={a,b,c}
vector<TYPE> v;
vector<TYPE> v(v1);
vector<TYPE> v(n);    //产生大小为n的vector
vector<TYPE> v(n,elem);  //n个值为elem的vector


//使用a数组初始化vector
int a[]={1,2,4,4,45}
vector<int> vv(a,a+5)    //范围也是左闭右开，此处的5也表示数组中有5个数

v.size();
v.empty();
v[n];
v1=v2;  //直接赋值，赋值完后v1原来的值清除，替换为v2的值
v1==v2;  //判断是否相等

v.begin();
v.end();
v.capacity();  //当前已经分配的可容纳元素个数
v.size();   //容器中已有有效数据的个数
v.empty();
v.erase(iter);             //移除pos位置的值，返回移除的值
v.erase(begiter,enditer);       
v.insert(iter,elem);     //pos位置插入elem，返回插入的值
v.insert(iter,v1.begin(),v1.end())  //在iter位置插入另一个vector（拼接作用
v.pop_back();   //删除最后一个数据
v.push_back(); 
//对于vector的v.begin()+pos就得到了pos位置的iterator
```

##### 注意：

- 对于vector，如果一开始分配了具体的大小，则分配的那部分就可以当作数组来用。

```c++
vector<int> v(100);  //初始化创建100个int单元，此时v.size()=100
v.psuh_back(-1); //执行后v.size()=101,-1被放在第101个位置


//对于vector 删除元素 应按照以下格式：
for(vector<int>::iterator it=v.begin();it!=v.end(); )
{
    if(*it==3)
        it=v.erase(it);   //erase返回值是删除节点的下一个节点，这样删除以后还能继续递增
    else
        it++;     //若没有找到符合的元素删除，则正常递增
}
```

**仅限c++11**：

```
vector<int> v={1,2,3};
```



## Map

```
#include<map>

map<int,string> id_name={{2015,'jim'},{2016,'Tom'}};

id_name[2015]='Bob'
id_name[2017]='ToT'

id_name.insert(make_pair(2018,'TAT'))
id_name.insert(pair<int,string>(2019,'TUT'))

//c++11开始支持，使用列表{}插入多个   
id_name.insert({ {2011,":)"}, {2012,":=)"} })

cout<<id_name[1111]   //[]不会做检查，没有则输出为空，不报错
id_name.at(1112)="BOb"   //.at()会做检查，所以此处报错


id_name.erase(2016)  //按键值删除

// 关键字查询，找到则返回指向该关键字的迭代器，否则返回指向end的迭代器
id_name.find(2016)
//用map<int,string>::iterator it接收查找值，找不到则等于end()


```





# List

``` c++
#include<list>

list<int> lst;
list<int> lst(n);
list<int> lst(n,elem);
list<int> lst1(lst);

lst.front();  //返回第一个元素
lst.back();  //返回最后一个元素
lst.empty();
lst.pop_front();//弹出第一个
lst.pop_back();  //弹出最后一个
lst.push_back(x);
lst.push_front(x);
lst.remove(x);  //删除值为x的节点
lst.erase(iterator pos);   lst.erase(iterator start,iterator end);  //移除迭代器指向的元素，返回下一个元素的迭代器。
lst.insert(iterator pos,const TYPE&val);//在pos位置插入val变量，并返回其迭代器，原pos及之后位置的元素后移。
lst.reverse(); //将list倒转
lst.sort();    lst.sort(cmp); //默认使用升序排列，可以自定义cmp函数,O(nlogn)
lst.unique(); //去除重复变量
lst.assign(n,elem);     lst.assign(lst1.begin(),lst1.end());   
int a[]={1,2,3}; lst.assign(a,a+3); //lst赋值后为1，2，3
```



list的迭代器之后不能加一个整数：

```cpp
list<int> l;
list<int>::iterator it=l.begin();
it=it+10;//错误！！
```

而**vector迭代器可以加一个整数**找到对应的位置

```cpp
vector<int> v;
vector<int>::iterator it=v.begin();
it=it+10;    //正确
```

所以**一般都用vector**代替STL中的list（毕竟vector也是可变长的，而且iterator可以加任意整数到另一位置，除此之外，vector只在移动的效率上不如list)



# Set

set中的key和value是相同的！

```c++
#include<set>

//set中的元素是按顺序排的，可以重载<
bool operator<(const node &a,const node &b)
{
    return a.x>b.x;
}
//初始化
vector<int> a={1,2,3}
int b[]={1,2,3}
set<int> s1(a.begin(),a.end());  //用数组初始化set
set<int> s2(b,b+3);
set<int> s3(s1);
set<int,greater<int> > s;  //规定set的排序方式
    
set<TYPE> s;

s.size();
s.empty();

set<TYPE>::iterator it;
for(it=s.begin();it!=s.end();it++){...}    //遍历set

set<int> s;
s.insert(3);
s.erase(4);
s.erase(iter);

iter=s.find(5);  //查找某值是否位于set中
if(iter!=s.end())    //未找到则返回end()
    cout<<"find it";


iter=s.lower_bound(x);//返回>=x中的最小值的iter
iter=s.upper_bound(x);//返回>x中的最小值的iter
```



# priority_queue优先队列

```cpp
priority_queue<int> pq

pq.empty();
pq.pop();    //将优先队列中的的首元素弹出
pq.push();  //将一个元素放入优先队列
pq.top();  //返回当前对手的元素        注意优先队列中的首元素使用top()而不是front()!!

```



# pair



### 1、pair的创建和初始化

pair包含两个数值，与容器一样，pair也是一种模板类型。但是又与之前介绍的容器不同，在创建pair对象时，必须提供两个类型名，两个对应的类型名的类型不必相同 

```c++
#include<utility>   //pair头文件

pair<string,string>anon;
pair<string,int>word_count;
pair<string, vector<int> >line;
```

当然也可以在定义时为每个成员提供初始化式：

```c++
pair<string,string>author("James","Joy");
```

pair型的使用相当的繁琐，如果定义多个相同的pair类型对象，可以使用typedef简化声明： 

```c++
typedef pair<string,string> Author;
Author proust("March","Proust");
Author Joy("James","Joy"); 
```

### 2、pair对象的操作 

对于pair类，可以直接访问其数据成员：其成员都是公有的，分别命名为first和second，只需要使用普通的点操作符.(因为pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。)

```c++
string firstBook;
if(author.first=="James" && author.second=="Joy")
    firstBook="Stephen Hero";
```

### 3、生成新的pair对象 

除了构造函数，标准库还定义了一个**make_pair**函数，由传递给它的两个实参生成一个新的pair对象

```c++
pair<string, string> next_auth;
string first,last;
while(cin>>first>>last) {
    next_auth=make_pair(first,last);
    //...
}
```

还可以用下列等价的更复杂的操作: 

```c++
next_auth=pair<string,string>(first,last);//类似于直接用结构体名/类名实例化对象并传入参数初始化
```

由于pair的数据成员是公有的，因而可如下直接地读取输入：

```c++
pair<string, string> next_auth;
while(cin>>next_auth.first>>next_auth.last) {
    //p.first和p.second的使用
}
```





# 正则表达式

c++的正则表达式包括的关键函数有 ： regex_match, regex_search, regex_repalce

```c++
#include<regex>


```





# 迭代器

```c++
int a[10];
vector<int> v;
vector<int>::iterator ite;
for(ite=v.begin();ite!=v.end();ite++)
	cout<<*ite<<endl;


//以下限制于c++11
for(auto it:v)   //对vector
    cout<<it<<endl; 
for(auto it:a)  //对普通数组
    cout<<it<<endl;
string s;  //对string
for(auto &w:s)
    cout<<w<<endl;
//上述相当于auto it=v[i];即将v的每个值依次赋值给it,所以此处改变it不会对v改变
若要实现遍历对数组元素的改动，则使用auto引用：
for(auto &it:v) //将v全部置0
    it=0;   
```



#### c++11中的auto

[auto简单使用链接](https://blog.csdn.net/tangya3158613488/article/details/86511677)

> 在c++11中定义了auto，auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导得到。
> 注意：使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto并非是一种"类型"的声明，而是一个类型声明时的“占用符”，编译器在编译期会将auto替换为变量实际的类型。

在此基础上出现**基于范围的for循环**：for循环后的括号由冒号“ ：”分为两部分：**第一部分是范围内用于迭代的变量，第二部分表示迭代的范围**。

```c++
int a[] = {1,2,3,4,5,6};
for(auto& e : a)
cout << e*2 << endl;
```

**范围for的使用条件**
1.for循环迭代的<u>范围必须是确定的</u>
2.<u>迭代的对象要实现++和==的操作</u>

所以一般将auto的遍历用在简单的数组，链表，字符串结构上（**少用在复杂结构体上**





## cmp函数和运算符重载

```c++
struct node{
    vector<int> v;
};

bool cmp(const node& n1,const node& n2)    //参数都是const变量引用
{
	for(int i=0;i<5;i++)
	{
		if(n1.v[i]<n2.v[i])
			return true;
		else if(n1.v[i]>n2.v[i])
			return false;
	}
	return true;
}

sort(a,a+10,cmp)

bool operator<(const node& n1,const node& n2)
{
	for(int i=0;i<5;i++)
	{
		if(n1.v[i]<n2.v[i])
			return true;
		else if(n1.v[i]>n2.v[i])
			return false;
	}
	return true;
}
int operator+(const node& n1,const node& n2)
{
    int sum=0;
    for(int i=0;i<5;i++)
        sum+=(n1.v[i]+n2.v[i]);
   	return sum; 
}
```



## Priority_queue优先队列自定义排序

```c++
/* 优先队列实际就是利用堆排序的有序序列
priority_queue<classtype,container,compare>
container容器一般用vector
若要自己定义排序规则，可以重载<运算符,这样可以只用写classtype
*/

struct node{
	int x,y;
};
bool operator<(const node& n1,const node& n2)  
{
    //注意在优先队列中这样写最终是递减排序，所以优先队列中的<规则和普通的刚好相反
	if(n1.x==n2.x) return n1.y<n2.y;
	else return n1.x<n2.x;
}

int main()
{
	priority_queue<node> pq;  //重载运算符后就按自定义的方式排序
	for(int i=0;i<10;i++)
	{
		pq.push(node(i,(5-i)*(5-i)));
		cout<<i<<" "<<(5-i)*(5-i)<<endl;
	}	
	cout<<endl;
	while(!pq.empty())
	{
		cout<<pq.top().x<<" "<<pq.top().y<<endl;
		pq.pop();
	}
}
```

## 运算符重载更新（sort，priority_queue：

 **priority_queue默认是最大的元素在队头（大顶堆）**

自定义排序方式的重载：  [链接](https://blog.csdn.net/qq_16234613/article/details/77448518)    [sort运算符重载](https://blog.csdn.net/hzyong_c/article/details/7791415)

```cpp
//类（结构体）的方式     重载的是 ()运算符
struct cmp{
  bool operator ()(const int& a,const int &b){
      return a>b;
  }  
};
//在类中重载运算符<（不能在类外直接重载，除非加友元(比较麻烦所以不推荐)
struct Person{
    int id;
    bool operator <(const Person& b){
    return this->b->id;
	}
};

//定义函数   **************************************************<-
bool compare(const int& a,const int& b){
    return a>b;
}
//或者 使用less<int>或者greater<int>对基本类型排序。
**************************************************👇
//对于sort推荐用 定义函数compare方式，对于priority_queue一般用 结构体方式
**************************************************👆
sort(arr,arr+n;compare);
sort(arr,arr+n,cmp());  //注意sort用结构体方式要cmp()
sort(arr,arr+n,greater<int>());  //注意要加(),是递减排序

priority_queue<int,vector<int>,cmp>;  //pq用结构体方式直接cmp
priority_queue<int,vector<int>,greater<int>> //greater<>不用加(),最小堆
    
//可以发现相同的比较函数用于sort和pq是“相反的顺序”（递增-最大堆，递减-最小堆)
```







string拼接

```c++
//注意能拼接的是string变量，只要有string就能和" "以及' '拼接。
string s="a"+"b";   //not ok 会报错
string ss=string("a")+"b";  //将其中的变成string就可以使用‘+’拼接

ss=ss+'a';   //ok
ss+='a';   //not ok,wrong!

```



c++ iomanip头文件 -控制io输出

```cpp
#include <iostream>
#include <iomanip>    
using namespace std ;
int main()
{
	double PI=3.141592654;
	cout<<PI<<endl;
	cout<<setprecision(2)<<PI<<endl;
	cout<<fixed<<setprecision(2)<<PI<<endl;	
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<PI<<endl;
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<left<<PI<<endl;
	cout<<scientific<<setprecision(10)<<PI<<endl;
	cout<<scientific<<uppercase<<setprecision(10)<<PI<<endl;	
    return 0 ;
}
-----------------------------------------------
    dec hex oct setbase(n) setfill(n) setprecision(n)
    setw(n) 
    fixed：表示输出是以小数点表示而不是科学记数法
```



fabs针对浮点数（返回值，参数），abs针对整型数

对于double类型，输入用%f,输出用%f  :`scanf("%lf",&n)`   `printf("%f",n)`  输出时用%f，因为输出时float会自动转化为double



**fgets**

```cpp
char str[100];
fgets(str,sizeof(str),stdin);  //从stdin中读取最多100个（包括\n)到str中
//fgets会读取回车, fputs不会额外输出回车	
//gets不推荐使用了，puts会额外输出回车
```





## string的操作：

```cpp
//下列所有str都是string类型
	//========================赋值========================
    string s1="abcdefghijklmnopqrstuvwxyz";
    string s2;
    s2.assign(s1);
    s2.assign(s1,3,4);
    cout<<"assign: "<<s2<<endl;
    //========================长度 length和size皆可========================
    cout<<"length:"<<s1.length()<<" size: "<<s1.size()<<endl;
    //===========比大小，两个string可以比较大小,所以可以排序===================
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
    //========================两字符串交换================================
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
```



string s的c_str()方法将s转成char数组字符串，返回的是一个const char *指针变量（8个字节）而不是字符数组的地址.通过这个可以把输入的任意字符串变量转化为const char * （相当于字符串常量。

**使用memcpy和strcpy复制：** （对于字符串一般用strcpy

``` cpp
memcpy(s1,s2,sizeof(s2));    //复制的长度是s2的大小，
strcpy(s1,s2);  //字符串的复制，因为s2以\0结尾，所以不用限制大小
```

```cpp
// c_str()返回值是指针变量
string s="sdasgagaewsadgwe";
char chs[]="sdasgagaewsadgwe";
sizeof(s.c_str());  //结果是8，因为指针变量的大小是8
sizeof(chs);   //结果是数组的大小，因为这是字符数组的地址（非指针变量，计算的是整个数组的大小
```

字符数组的初始化

```cpp
//用字符串常量初始化
char s[]="dsafsadg";
//for循环或者strcpy初始化(strcpy更高效)
string str="sdfas";
strcpy(s,str.c_str());
//不能用char s[]=str.c_str();初始化，因为c_str()是一个指针变量，无法知道字符串大小，会报错
```





分割字符串：

```cpp
//推荐使用strtok，虽然string配合find()，substr()也能做
vector<string> vs;
char s[]="     thish sahf iewt hiwe rh weri  ";
    char *head;
 	//以空格分割，注意是双引号
    head=strtok(s," ");    //初始化

    while(head!=NULL){   //循环条件
        printf("%s ",head);
        cout<<head<<endl;   //cout也能输出char[](因为以\0结尾)
        vs.push_back(head);
        //获得下一个位置
        head=strtok(NULL," ");
    }
```





## 转义字符：

**转义字符只能在编译器中出现，只在编译器中有效**

在编译器中写`string s="\n \t \\ \" "` 编译器在编译时会自动将字符串中的转义字符转义成对应的字符，如果`cout<<s<<endl`，则输出的是转义后的结果。
然而对于stdin输入的字符串，不存在转义的说法，输入什么，最终输出的就是什么，如果在stdin中输入` "\n \t \\ \" " ` 给 `string s`, cout出来还是 `"\n \t \\ \" "` （双引号也是输出值 。

**c++中不转义输出的方法： `R"(str)"`**

对于要输出的字符串中带有`\ " '` 通常是在字符串中添加`\` 转义如`cout<<"\\ \\n \\t"`输出的结果是`\ \\n \\t`  

还有一种方法就是不转义输出： `cout<<R"(\\ \\n \\t)"`  注意格式是`R"(str)"` 里面的str不用再加双引号（外面已经加了）。





**abs函数：**

在cstdlib中的abs返回值和参数都是int类型

而在cmath中的abs函数参数和返回值都是double类型