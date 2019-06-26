## 对于不定量组数据的输入：

**1.**

```c++
while(scanf("%d",&a)!=EOF) {...} 	或者写成
while(~scanf("%d",&a)) {...}
```

​	scanf()函数返回成功赋值的<u>数据项数</u>，出错时则返回EOF，EOF定义为-1。

​	<u>~是按位取反</u>，-1十六进制补码表示为0x ffffffff，f是二进制的1111，取反后就全部变成0了，于是while结束。只有返回值为EOF（即-1）时，其取反的的值（即while循环的判断条件）才为0，才能结束循环，其它输入情况下（无论是否输入成功）while循环的判断条件为非0，即为真。

　　<u>但这种写法的漏洞在于</u>：一但输入的值为字母、符号之类的，scanf赋值不成功把读到的内容又返回到stdin的缓冲区（假设这个值为t），其取反得到的值使while又进入到下一次循环，scanf又从stdin缓冲区里读到了原先吐回的t，如此成了死循环……

**所以此种写法在oj中可能会产生output limit exceed**

**2.**

```c++
 while(cin>>a)	
 	{cout << a << endl;}
```

但这种输入方法对于一行中有空格的输入无能为力，解决方法如下。

**3.istringstream类**

```c++
#include<iostream> 
#include<sstream>  //使用istringstream
#include<string>   //c++使用string类
using namespace std; 
int main()  
{   
    string str, line;   
 	while(getline(cin, line))      //类似于while(cin>>line);输入多组带有空格的字符串  
    {         
        istringstream stream(line);   //创建istringstream对象并同搜索时初始化，使其和字符串line绑定        
     while(stream>>str)    //以空格为分隔符把该行分割开来 	
     {			
         cout<<str.c_str(); //逐个输出 
     }		
     cout<<endl;                      
    }         
    return 0;  //若上述输入的是数字，则用sscanf转化
} 
```

istringstream是C++里面的一种输入输出控制类，它可以创建一个对象，然后这个对象就可以绑定一行字符串，然后输出该对象时**以空格为分隔符**把该行分隔开来。

​	c++中定义的标准输入输出流是istream和ostream，他们是iostream类的父类，而cin是istream的对象，cout是ostream的对象。**头文件fstream（对文件操作的流）**包含了ifstream和ofstream，**头文件sstream（对字符串操作的流）**包含了istringstream和ostringstream，这些类都是继承自istream和ostream的。它们的关系如下图：

​	![img](http://img.blog.csdn.net/20160430174326537)

有两种情况会使一个istream对象（例如cin）的bool转型为false: **读到EOF**(文件结束标志)或**遇到一个无效的值**(输入流进入fail状态)。

缺省情况下，输入操作符**丢弃空白符、空格符、制表符、换行符以及回车**。

**4.对于从文件中读入有空格的一行：**

```c++
ifstream fin(fname);
int a,b,c;
string s;
getline(fin, s);   //getline()读到\n终止
istringstream ss(s);
ss >> a>>b>>c;
```



## cin   getline()   fgets() ~~cin.get()   cin.getline()  gets()~~ 解析

1. cin会跳过所有空白符。

2. getline(cin,str)的原型是 **istream& getline ( istream &is , string &str , char delim );**

其中 istream &is 表示一个输入流，譬如cin；string&str表示把从输入流读入的字符串存放在这个字符串中（可以自己随便命名，str什么的都可以）；char delim表示遇到这个字符停止读入，在不设置的情况下系统默认该字符为'\n'，也就是回车换行符（遇到回车停止读入，停止符不读入）。

其返回值是一个istream对象（若istream & is是cin则返回就是cin），当读到EOF或者读入失败时，istream对象的bool会返回false。

**fgets（char * ,size_t,file *）:读到\n就停止读入，\n会读入,终止符就是\n不能改变。**

**getline(cin,string,delim)  :从cin中读入到string中，终止符为delim, <u>不会读入终止符delim</u>**









## 对于string

- string 的单个字符是char类型，查询类型使用typeid(var).name(),要引入#include<typeinfo>

- 实数使用float或者double,对应的是%f , %lf

- 对二维数组（或者直接对数组来说）初始化时，不用对每个位置赋值：

```c++
int table[10][5]={{1,},                 //不赋值的位置自动初始化为0
				  {1,1},
				  {4,2,4,8,6},
				  {4,3,9,7,1},
				  {2,4,6,0,0},
				  {1,5,0,0,0},
				  {1,6,},
				  {4,7,9,3,1},
				  {4,8,4,2,6},
				  {2,9,1}};        //以这种方式只能创建n行m列的矩阵，每行矩阵列数相同
```





*Runtime Error 就是ACM中常说的RE，出现这种错误往往是数组越界造成的，你应该检查数组开的是否足够大，或者在程序处理过程中是否存在数组下表越界的情况。*



## [windows和Linux评测系统的区别](https://tieba.baidu.com/p/3396793081?red_tag=2288962602)：

注意一下，代码中有个replace(\*\r\*,**)方法，它的作用就是将\r替换成空字符串。为什么要做这个替换呢？因为在windows下，文本的换行是"\r\n",而在Linux下是"\n"。因为不能确定测试数据来源与windows还是Linux，增加一个\r，就是增加一个字符，如果不删除的话，两个文本就是不一样的，就会造成wrong answer结果。或许你曾经遇到过在windows下用记事本打开一个纯文本文件，格式全乱了，所有文本都在一行内，非常影响阅读。你可以通过用写字板打开来解决这个问题。据说"\r\n"来源于比较古老的打印机，每打印完一行，都要先“回车(\r)”，再“换行”(\n)。同样一个C语言的printf("\n")函数，在windows下将生成"\r\n"，而在Linux下生成"\n"，因为评测程序为你自动处理了，因此你就不必关注这些细节的东西了。 



## memset使用注意

memset是对每个字节进行赋值，所以**对于char数组，memset初始化的值就是每个元素的值**。

```c++
char a[100];
memset(a,12,sizeof(a))    //将每个char元素初始化为12
```

但针对**int数组，只有0和-1可以这样用**，其他数字的值不能简单确定。

```c++
int a[100];
memset(a,0,sizeof(a));   //每个int元素初始化为0（00000000 00000000 00000000 00000000就是0）
memset(a,-1,sizeof(a));  //每个int初始化为-1 （11111111 11111111 11111111 11111111就是-1）

memset(a,127,sizeof(a));   //每个int初始化为01111111 01111111 01111111 01111111 
```

**由上述int的特性，可以简单的用127表示INF，128表示-INF。**





## OJ错误原因

Waiting:正在评测程序。 
Compiling:正在编译程序。 
Accepted:程序正确。 
Wrong Answer:程序运行结果与正确结果不一样。 
Time Limit Exceeded:运行时间超出了要求。 
Memory Limit Exceeded:程序运行占用内存超出了标准。 
Runtime Error:程序在运行的时候异常退出。 
Compile Error:编译错误。（可能是提交环境选错了） 
Presentation Error:格式错误，结果与正确结果就差一点。

**Runtime Error**

1.数组开的太小，**访问了不该访问的内存区域**，数组范围可以是上限+5 。 
2.**很大的数组在main函数中定义，应该定义为全局变量**。main函数中的数组和临时变量一样会被放在栈区，如果数组过大，就会导致栈发生上溢。 
3.发生**除0错误**。 
4.**指针指向错误**。 
5.程序抛出了未接受的异常。（没遇到）

**Time Limit Exceeded** 
1.程序时间复杂度较高，优化算法。 
2.存在死循环。 
3.（新手错误）程序有system(“pause“)。







对于scanf("%c",&ch);  会吞回车，所以要用getchar()接受回车。

或者用cin就不用考虑误读回车的问题。





常用define：

```c++
#define INF 0x7FFFFFFF
#define IMIN -(1<<31)
#define eps 10^(-6)
#define mem(a) memset(a,0,sizeof(a))
#define mem_bool(a) memeset(a,false,sizeof(a))
#define rep(i,n) for(int i=0;i<n;i++)
#define FIN freopen("in.txt","r",stdin)
#define FOUT feopen("out.txt","w",stdout)


#define debug(s)  cout<<"---"<<s<<"---"<<endl
```





**对于OJ来说，输出的最后一个空格和一个换行的区别不会影响最终的判断结果。**



对于c++输出结果，如果跳出命令行后一直不显示，有可能是scanf没有&，有可能是**死循环**。