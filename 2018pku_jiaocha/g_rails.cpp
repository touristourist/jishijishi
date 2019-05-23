#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

//用栈模拟，看原始序列出栈入站后能不能匹配
//将原始序列依次入栈，若当前栈顶的元素等于ind指向的元素，就要弹栈且ind加一

int n;
int a[1005];
stack<int> s;

void clear(stack<int> &s){
	stack<int> empty;
	swap(empty,s);
}

int main(){
	while(scanf("%d",&n)&&n!=0){
		
		while(scanf("%d",a)&&a[0]!=0){
			for(int i=1;i<=n-1;i++)
				scanf("%d",a+i);
			clear(s);
			int ind=0;
			for(int i=1;i<=n;i++){    //按顺序将1~n压栈，遇到相等的再弹栈 
				s.push(i);
				if(s.top()==a[ind]){
					s.pop();
					ind++;
					while(!s.empty()){
						if(s.top()==a[ind]){
							s.pop();
							ind++;
						}
						else break;
					}
				}
			}
			while(!s.empty()){  //n个数全压完后再判断还有没有要弹栈的 
				if(s.top()==a[ind]){
					s.pop();
					ind++;
				}
				else break;
			}
			if(!s.empty()) printf("No\n");    //没有全部弹完，说明不匹配 
			else printf("Yes\n");
		}
		printf("\n");
	}
	
}
