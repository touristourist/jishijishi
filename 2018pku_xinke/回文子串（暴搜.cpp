#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

bool ishui(string s){
	char stem[105];
	int len=s.length();
	for(int i=len-1;i>=0;i--)
		stem[len-i-1]=s[i];
	stem[len]='\0';
	string sstem=stem;
//	cout<<sstem<<" stem\n";
//	cout<<s<<" s\n";
	if(sstem==s) return true;
	else return false;
}

string longest(string s){
	int st=0,en=0,leng=0;
	int len=s.length();
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j<len;j++){
			string sub=s.substr(i,j-i+1);
			if(ishui(sub)){
				int slen=j-i+1;
				if(slen>leng){
					st=i;
					en=j;
					leng=slen;
				}
			}
		}
	}
	return s.substr(st,en-st+1);
}


int main(){
	
	
//	printf("%d",ishui("saas"));
	
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		cout<<longest(s)<<endl;
	}
	
}
