#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//ֻ����#�����в��ܰڷ����� 
//����û�пհ���/�հ��У�����ÿһ�ж�������һ�������ӵ�λ��
//����N�ʺ󣬵��в�ͬ��ֻ��#�ܷţ��Լ�����ÿ�ж�һ��Ҫ��
//���N�ʺ�ķ��������д����Ҵ��� 
//����ʹ��dfs(i,j)��ʾ��ǰ�Ǵ���ŵ�i�����ӣ�i=0~n-1),�ҵ�ǰӦ�ôӵ�j�п�ʼ��
//������Ŀ�е������������ 

//#define debug
int n,k;
char bod[20][20];

int rowlist[20];  //�±�0~n         rowlist[i]�ŵ�i�е����� 

bool check(int i,int ind){  //ind��ʾ���� ��ind�� 
	for(int ii=0;ii<ind;ii++){
		if(rowlist[ii]==i) return false;
	}
	return true;
}

void put(int i,int j){
	
}

int cnt;

void dfs(int i,int nowcol){   //�´����������ĵ�i������( i=0~n-1 )������һ���ڵ�i�� 
	if(i>=k){ 
		cnt++;
		return ;
	} 
	for(int col=nowcol;col<=n-k+i;col++)  //�ӵ�ǰ��nowcol��n-k+i�ǵ�i�������ܷŵ��еķ�Χ 
	for(int ii=0;ii<n;ii++){
		if(check(ii,col)&&bod[ii][col]=='#'){
			rowlist[col]=ii;
			dfs(i+1,col+1);
			rowlist[col]=-1;    //��λ�÷����λ��׼���Ŵ�����һ��λ�� 
		} 
	}
}

int main(){
	#ifdef debug
	freopen("323.txt","r",stdin);
	#endif
	
	while(cin>>n>>k&&n!=-1&&k!=-1){
		cnt=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>bod[i][j];
		
			memset(rowlist,-1,sizeof(rowlist));
			dfs(0,0);
		
			
		cout<<cnt<<endl;
	}
	
	
}
