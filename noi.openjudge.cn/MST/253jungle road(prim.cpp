#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<queue>

using namespace std;

//Prim����  ά��һ��MST�㼯�ϣ�ÿ������MST�㼯�ں͵������������̱�
//ʹ��edge�����ȶ���
//Ҳ���Բ������ȶ��У�������dijkstra�㷨�е�vis[],d[]��������ݽṹ

#define mst(a) memset(a,-1,sizeof(a))
//#define debug
#define out(name) cout<<name<<endl

struct edge{
    int u,v,cost;
    edge(int _u,int _v,int _cost):u(_u),v(_v),cost(_cost){}
    edge(){}
};

struct cmp{
    bool operator ()(const edge & a,const edge& b){
        return a.cost>b.cost;
    }
};

int n;

int M[50][50];   //ʹ���ڽӾ��󣬵��о�Ӧ��ʹ���ڽӱ��ڽӾ�����Ҫ�ж�M[i][j]�Ƿ���ڱ�M[i][j]==-1/INF

int main(){
    #ifdef debug
    freopen("253.txt","r",stdin);
    #endif // debug

    while(cin>>n&&n){
        mst(M);
        int temn=n;
        temn--;
        while(temn--){
            char sch,ech;
            int nums,cost;
            cin>>sch>>nums;
            while(nums--){
                cin>>ech>>cost;
                int st=sch-'A'+1,et=ech-'A'+1;
                M[st][et]=cost;
                M[et][st]=cost;
            }
        }

        set<int> setint;
        priority_queue<edge,vector<edge>,cmp> pq;
        int res=0;
        for(int i=1;i<=n;i++){
            if(M[1][i]!=-1)
                pq.push(edge(1,i,M[i][1])); //edgeǰһ�����Ǽ��뼯���еı�
        }

        setint.insert(1);
        int edgcnt=0;
        while(true){  //�ҵ�n-1���߼���
            edge e=pq.top();
            pq.pop();
            int tu=e.u,tv=e.v,tcost=e.cost;
            if(setint.find(tv)==setint.end()){
                setint.insert(tv);
                res+=tcost;
                edgcnt++;
                for(int j=1;j<=n;j++){
                    if(setint.find(j)==setint.end()&&M[tv][j]!=-1)
                        pq.push(edge(tv,j,M[tv][j]));
                }
            }
            if(edgcnt==n-1) break;

        }
        cout<<res<<endl;

    }

}
