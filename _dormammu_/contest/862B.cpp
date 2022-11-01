#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  300006
#define  mem(a,v)   memset(a,v,sizeof(a))

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

vector<int>graph[MAX];

ll color[MAX];
ll visited[MAX];
ll C[MAX];

void DFS(int source){

    visited[source]=1;

    for (int i=0;i<graph[source].size();i++){

        int child = graph[source][i];
        if (child==source)continue;
        if (color[source]==0){
            color[child]=1;
        }
        else color[child]=0;

        if (visited[child]==0){
            DFS(child);
        }

    }

}

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>n;

    for (int i=1;i<n;i++){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    color[1]=1;
    DFS(1);

    for (int i=1;i<=n;i++){
        if (color[i]==1)cntr++;
        else cnt++;
    }

    for (int i=1;i<=n;i++){
        if(color[i]==1)ans=cnt;
        else ans=cntr;
        sum+=(ans-graph[i].size());
    }

    cout<<sum/2<<endl;

    return 0;
}