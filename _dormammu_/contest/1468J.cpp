/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

struct ff{
    int u,v,w;
    ff(int a,int b,int c){
        u=a; v=b; w=c;
    }
};
bool cmp(ff a,ff b){
    return a.w<b.w;
}
int par[200005];
int Find(int r){
    if(par[r]==r) return r;
    return par[r]=Find(par[r]);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        int x,y,w;
        vector<ff> E;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
            E.pb(ff(x,y,w));
        }

        sort(E.begin(),E.end(),cmp);

        int mn=INT_MAX;
        int mx=INT_MAX;
        int tt=n;

        vector<int> temp;

        for(int i=0;i<m;i++){
            x=E[i].u; y=E[i].v; w=E[i].w;
            int px=Find(x);
            int py=Find(y);
            if(px!=py){
                par[py]=px;
                if(w>k) temp.pb(w);
                tt--;
            }
            if(tt==1){
                if(w<k) mn=min(mn,abs(w-k));
                if(w>=k) mx=min(mx,abs(w-k));
            }
        }

        ll cnt=0;

        for(int x:temp){
            cnt+=(x-k);
        }

        //cout<<cnt<<" "<<mn<<" "<<mx<<endl;

        if(temp.size()==0){
            cnt=min(mn,mx);
        }

        cout<<cnt<<endl;

    }

    return 0;
}