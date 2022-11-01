#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair

vector <ll> G[200006];

ll Mark[200006];

vector <ll> ans;

struct edge{
    ll node;
    edge(ll a)
    {
        node=a;
    }
};

bool operator<(edge a, edge b)
{
    return a.node>b.node;
}

void BFS(int S)
{
    Mark[S]=1;
    priority_queue<edge> PQ; PQ.push(S);

    while(!PQ.empty())
    {
        ll U=PQ.top().node; PQ.pop();

        ans.pb(U);

        for(int i=0;i<G[U].size();i++)
        {
            ll V=G[U][i];

            if(Mark[V]==0)
            {
                Mark[V]=1;
                PQ.push(edge(V));
            }
        }
    }
}

int main()
{

    ll T,N,M,X,Y,W;

    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        cin>>X>>Y;
        G[X].pb(Y);
        G[Y].pb(X);
    }

    BFS(1);

    for(int i=0;i<N;i++) cout<<ans[i]<<" "; cout<<endl;

    return 0;
}