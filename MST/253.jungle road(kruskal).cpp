#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

//kruskal并查集做法

//#define debug

int bin[100];

struct edge{
    int u,v,cost;
    edge(int _u,int _v,int _cost):u(_u),v(_v),cost(_cost){}
    edge(){}
};
bool cmp(edge a, edge b){
    return a.cost<b.cost;
}
int find(int x){
    int result= x;
    while(result!=bin[result])
        result=bin[result];
    return result;
}

void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        bin[fy]=fx;
    }
}

int n;
edge alledge[1000];

int main(){
    #ifdef debug
    freopen("253.txt","r",stdin);
    #endif // debug

    while(cin>>n&&n){
        memset(alledge,0,sizeof(alledge));
        for(int i=0;i<=n;i++)
            bin[i]=i;
            int edgcnt=0;
        n-=1;
        while(n--){
            char sch,ech;
            int num,cost;
            cin>>sch>>num;
            while(num--){
                cin>>ech>>cost;
                int sn=sch-'A'+1,en=ech-'A'+1;  //'A' equals 1 in array
                edge e(sn,en,cost);
                alledge[edgcnt++]=e;
            }
        }
        int res=0;
        sort(alledge,alledge+edgcnt,cmp);
        for(int i=0;i<edgcnt;i++){  //可以变成找到n-1条边的循环
            edge teme=alledge[i];
            int tu=teme.u,tv=teme.v,tcost=teme.cost;
            if(find(tu)!=find(tv)){
                res+=tcost;
                merge(tv,tu);
            }
        }
        cout<<res<<endl;


    }

}
