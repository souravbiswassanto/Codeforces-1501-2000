#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  100006
#define  mem(a,v)   memset(a,v,sizeof(a))

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];

vector<int>graph[MAX];
vector<int>Ans;
int cntr;

void DFS (int root){

    B[root]=1;

    for (int i=0;i<graph[root].size();i++){

        if(graph[root].size()==1&&A[root]==1){
            Ans.pb(root);
        }
        int v=graph[root][i];

        if (B[v]==0){

            DFS(v);
            if (A[root]==1&&A[v]==1)C[root]++;
            if (C[root]==graph[root].size()-1){Ans.pb(root);}
        }

    }

}

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>n;
    int root;

    for (int i=1;i<=n;i++){
        cin>>a>>b;

        A[i]=b;
        if(a==-1){
            root=i;
            graph[i].pb(i);
            continue;
        }
        graph[a].pb(i);
        graph[i].pb(a);
    }

    DFS(root);

    if(Ans.size()==0){
        cout<<-1<<endl;
        return 0;
    }

    sort(Ans.begin(),Ans.end());

    for (int i=0;i<Ans.size();i++){
        cout<<Ans[i]<<" ";
    }

    return 0;
}