#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define max(x,y) x>y?x:y

int n;
int ntime[1005];


int main(){
	
	while(cin>>n){
		int totalsum=0,largest=-1;
		for(int i=0;i<n;i++){
			cin>>ntime[i];
			largest=max(largest,ntime[i]);
			totalsum+=ntime[i];
		} 
		int rest=totalsum-largest;
		if(rest<largest) printf("%.1f\n",(float)rest);
		else printf("%.1f\n",(float)totalsum/2);
		
	}	
} 
