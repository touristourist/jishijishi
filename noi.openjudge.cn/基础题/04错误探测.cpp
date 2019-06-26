#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int m[105][105];
int row[105]; //每行1的个数 
int col[105];
int n;


bool jud(){
	bool result=true;
	for(int i=0;i<n;i++){
		if(row[i]%2==1||col[i]%2==1){
			result=false;
			break;
		}
	}
	return result;
} 

int main(){
	cin>>n;
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		cin>>m[i][j];
		if(m[i][j]==1){
			row[i]++;
			col[j]++;
		}
		
	}
	
	if(jud()) cout<<"OK";
	else {
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(m[i][j]==1){
				row[i]--;
				col[j]--;
				if(jud()){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				row[i]++;
				col[j]++;
			}
			else if(m[i][j]==0){
				row[i]++;
				col[j]++;
				if(jud()){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				row[i]--;
				col[j]--;
			}
		}
		
		cout<<"Corrupt";
	}
	
}
