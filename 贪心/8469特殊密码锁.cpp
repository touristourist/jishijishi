#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

//从左往右， 从0~n-1依次处理nowstr（因为每个位置的锁最多按一次，所以从左往右依次判断是不是要按 
//对第一个锁 按/不按 都可以，所以要比较这两个分支的结果
//最后能否得到aim的结果  ：通过判断结束后，最后一把锁是否和aim相同即可 


string nowstr;
string aimstr;

int main(){
	
//	freopen("8469.txt","r",stdin);
	
	cin>>nowstr>>aimstr;
	int len=nowstr.length();
	int op1=0,op2=0;
	string s1=nowstr,s2=nowstr;
	//不按下
	s1[0]=s1[0];    
	 //按下第一把锁！！！          注意按下第一把锁的操作也要统计在内！！！ 
	s2[0]=(s2[0]=='0')?'1':'0';   
	s2[1]=(s2[1]=='0')?'1':'0'; 
	op2++; 
	
	for(int i=1;i<len;i++)
	{
		if(s1[i-1]!=aimstr[i-1]){   //对s1 
			op1++;
			s1[i-1]=(s1[i-1]=='0')?'1':'0';
			s1[i]=(s1[i]=='0')?'1':'0';
			if(i<len-1)
				s1[i+1]=(s1[i+1]=='0')?'1':'0'; 
		}
		
		if(s2[i-1]!=aimstr[i-1]){   //对s2 
			op2++;
			s2[i-1]=(s2[i-1]=='0')?'1':'0';
			s2[i]=(s2[i]=='0')?'1':'0';
			if(i<len-1)
				s2[i+1]=(s2[i+1]=='0')?'1':'0';
		}
	}
	bool tag1=(s1[len-1]==aimstr[len-1])?true:false;
	bool tag2=(s2[len-1]==aimstr[len-1])?true:false;
	if(!tag1&&!tag2)
		printf("impossible");
	else  if(tag1&&tag2)
		printf("%d",(op1>op2?op2:op1));
	else if(tag1)
		printf("%d",op1);
	else 
		printf("%d",op2);
		
	
}
