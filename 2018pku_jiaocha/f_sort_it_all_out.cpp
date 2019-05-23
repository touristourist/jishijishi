#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define rep(i,k) for(int i=0;i<k;i++)
#define CYCLE 0
#define UNKN  1
#define SUCC  2
#define UNJD  3
//注意此题的要求是输出第一次发生冲突/确定关系时的数字，所以每次来一个关系就重新建图，判断拓扑排序
//对于CMPLT和SUCC，哪一个先发生就输出哪一个，对于UNKN的结果，要所有的m个接受完才能判断
//若有环 -矛盾    若同时出现两个入度为0的-不确定
const int N=30;
vector<int> indg(N);
vector<int> G[N];
int n,m;
vector<int> vv;

int topoSort(){
    queue<int> qq;
    vector<int> ind=indg;
    rep(i,n) if(ind[i]==0) qq.push(i);
    int ukflag=0;
    vv.clear();
    while(!qq.empty()){
        if(qq.size()>1) ukflag=1;
        int t=qq.front();
        qq.pop();
        vv.push_back(t);
        rep(i,G[t].size()){
            ind[G[t][i]]--;
            if(ind[G[t][i]]==0) qq.push(G[t][i]);
        }
    }
//    printf("vv-size: %d ",vv.size()); rep(ii,vv.size()) printf("%c ",vv[ii]+'A');
 //   cout<<endl;

    if(vv.size()!=n) return CYCLE;
    else if(ukflag==1) return UNKN;
    else return SUCC;
}

int main(){
    while(~scanf("%d%d",&n,&m)&&(n!=0&&m!=0)){
        rep(i,n) G[i].clear();
        rep(i,n) indg[i]=0;
        int ret=UNJD;
        rep(i,m){
            string s;
            cin>>s;
            if(ret==CYCLE||ret==SUCC);
            else{
                int u=s[0]-'A',v=s[2]-'A';
                G[u].push_back(v);
                indg[v]++;
                //  judge topo sort
                ret=topoSort();
                if(ret==SUCC){
                    printf("Sorted sequence determined after %d relations: ",i+1);
                    rep(ii,vv.size()) printf("%c",char(vv[ii]+'A'));
                    printf(".\n");
                }
                else if (ret==CYCLE){
                    printf("Inconsistency found after %d relations.\n",i+1);
                }
            }
        }
        if(ret==UNKN)
            printf("Sorted sequence cannot be determined.\n");
    }

}
