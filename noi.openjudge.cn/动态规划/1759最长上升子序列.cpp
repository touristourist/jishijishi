#include<iostream>
#include<cstdio>

using namespace std;

//ʱ�临�Ӷ�O(n^2)
//dp[i]��ʾ��a[i]��β��LIS���ȣ���Ҫ����i֮ǰ������a[j]������ֵ����dp[i]��ֵ
//��ʼ��ʱdp[]ȫΪ1 

#define MINF -10000

int n;
int a[1005];
int dp[1005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		dp[i]=1;
	int finalMax=MINF;
	for(int i=0;i<n;i++)
	{
		int max=1;  //dp[]����Сֵ 
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])	max=max>(dp[j]+1)?max:(dp[j]+1);
		}
		dp[i]=max;
		finalMax=finalMax>max?finalMax:max;  //ע������������е����ֵ��һ�������ȡ�ã�������;��¼���ֵ 
	}
	printf("%d",finalMax);
}
