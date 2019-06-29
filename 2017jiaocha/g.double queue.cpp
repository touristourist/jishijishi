#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define debug

struct node{
	int k,p;
	node(int _k,int _p):k(_k),p(_p) {}
};

vector<node> vq;

void deletemax(){
	int maxp=-1;
	int len=vq.size();
	if(len==0){
		cout<<0<<endl;
		return;
	}
	int index=0;
	for(int i=0;i<len;i++){
		if(maxp<vq[i].p){
			maxp=vq[i].p;
			index=i;
		}
	}
	auto it=vq.begin();
	cout<<(it+index)->k<<endl;
	vq.erase(it+index);
	
}
void deletemin(){
	int minp=10000;
	int len=vq.size();
	if(len==0){
		cout<<0<<endl;
		return;
	} 
	int index=0;
	for(int i=0;i<len;i++){
		if(minp>vq[i].p){
			minp=vq[i].p;
			index=i;
		}
	}
	auto it=vq.begin();
	cout<<(it+index)->k<<endl;
	vq.erase(it+index);
	
}

int main(){
	#ifdef debug
	freopen("g.txt","r",stdin);
	#endif
	
	
	int op;
	int kk,pp;
	while(cin>>op){
		switch(op){
			case 0: break;
			case 1:
				cin>>kk>>pp;
				vq.push_back(node(kk,pp));
				break;
			case 2:
				deletemax();
				break;
			case 3:
				deletemin();
				break;		
		}
	
	}
	
	
	
}


//使用vector模拟链表 
