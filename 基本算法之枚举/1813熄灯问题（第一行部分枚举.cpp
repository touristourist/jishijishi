#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//һ��������ఴһ�Σ��ҿ��ذ���˳������ν�����Կ��صĽ��һ��������Ψһ�ģ����� 

#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a))
//#define debug
#define outc(na) cout<<na<<" ";

int deng[50][50],kai[50][50];
int tem[50][50];   //deng[][]����ԭʼ�ƣ�tem[][]���ڱ��浱ǰ���ĵ� 

void op(int i,int j){
	tem[i][j]=!tem[i][j];  //0�ķǾ���1
	int di[]={-1,1,0,0};
	int dj[]={0,0,-1,1};
	for(int k=0;k<4;k++){  //�������������ĸ���ķ�ʽ������������ 
		int dii=di[k],djj=dj[k];
		int ni=i+dii,nj=j+djj;
		if(ni>=1&&ni<=5&&nj>=1&&nj<=6)
			tem[ni][nj]=!tem[ni][nj];
	}
}

bool solve(){
	//���յ�һ�п��ذ�
	for(int i=1;i<=6;i++){
		if(kai[1][i]) op(1,i);
	}
	//�ӵڶ��п��ؿ�ʼ��ÿ�е�Ŀ�궼�ǰ���һ�еĵư��� 
	//˼���ǣ���һ�п�����ô���Ѿ��޷��ı䣬Ҫ����һ�е���ֻ�ܿ����п����� 
	for(int i=2;i<=5;i++){
		for(int j=1;j<=6;j++){
			if(tem[i-1][j]){
				op(i,j);
				kai[i][j]=1;
			} 
			else kai[i][j]=0;   //ע����Ϊkai[]ÿ�β�memset������Ҫ��ȷ��ֵ1/0 
		}
	}
	bool res=true;
	for(int i=1;i<=6&&res;i++)  //֮ǰ����ֻ������һ�е�������ǰ����һ����ȫ��ģ�ֻҪ������ȫ��ͳɹ� 
		if(tem[5][i]) res=false;
	return res;
}


int main(){
	#ifdef debug
	freopen("1813.txt","r",stdin);
	#endif
//	cout<<"afd";
//	outc("af");
	mst(deng);
	mst(kai);
	mst(tem);
	rep(i,1,5)
	rep(j,1,6){
		cin>>deng[i][j];
		tem[i][j]=deng[i][j];
	}
	

	for(int i=0;i<64;i++){  //ö�ٵ�һ�� 
		for(int j=0;j<6;j++){
			int thisbit=1<<j;
			if(i&thisbit) kai[1][j+1]=1;
			else kai[1][j+1]=0;
		}
	
		if(solve()) break; 
	
		//һ���жϺ�tem[][]ԭʼ�ƵĽ���Ѿ�������Ҫ���ó�ԭʼֵ 
		for(int i=1;i<=5;i++)
		for(int j=1;j<=6;j++)
		tem[i][j]=deng[i][j];
	}
	
	for(int i=1;i<=5;i++){
		for(int j=1;j<=6;j++)
			cout<<kai[i][j]<<" ";
		cout<<endl;
		}
	
	
	

}
