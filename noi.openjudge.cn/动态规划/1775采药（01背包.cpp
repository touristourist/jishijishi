#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//dp[i][j]��ʾ��ǰi����1~i����Ʒ����ѡ������������j�������ĵ������ż۸� 

#define oj
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define mst(a) memset(a,0,sizeof(a)) 
#define max(x,y) x>y?x:y


int t,m;
int p[105],wt[105];
int dp[105][1005];    //ע�⣡���� T��1000������TҪ����1000+ ������������ 
//��i�д���ǰi����������j�б�ʾ��ǰ��������Ϊj���к��ж�����ɢ������ 

int main(){
	
#ifndef oj
	freopen("1775.txt","r",stdin);
	scanf("%d %d",&t,&m);
	
	rep(i,1,m){	
		cin>>wt[i]>>p[i];
	}
	mst(dp);
	rep(i,1,m)
	rep(j,1,t){
		//��ѡ���˵�i������ֻ��ǰi-1������ 
		if(j<wt[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+p[i]); 
		//����ѡ��i����Ʒ�����в�ѡ��ѡ���������
		//��ѡ���򲻿��ǵ�i����ֱ�ӿ��Ǵ�ǰi-1����ѡ������������j
		//��ѡ����ʣ��j-wt[i]����ǰi-1����ѡ�� 
	}
	
	rep(i,0,m){
		rep(j,0,t)
		printf("%d ",dp[i][j]);
		printf("\n");
	}
	
	printf("%d",dp[m][t]);
#endif
#ifdef oj
	scanf("%d %d",&t,&m);
	rep(i,1,m){	
		cin>>wt[i]>>p[i];
	}
	mst(dp);
	rep(i,1,m)
	rep(j,1,t){
		//��ѡ���˵�i������ֻ��ǰi-1������ 
		if(j<wt[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+p[i]); 
		//����ѡ��i����Ʒ�����в�ѡ��ѡ���������
		//��ѡ���򲻿��ǵ�i����ֱ�ӿ��Ǵ�ǰi-1����ѡ������������j
		//��ѡ����ʣ��j-wt[i]����ǰi-1����ѡ�� 
	}
	printf("%d",dp[m][t]);
#endif
	
}
