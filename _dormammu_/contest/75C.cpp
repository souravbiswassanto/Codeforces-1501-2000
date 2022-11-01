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

map<ll,ll>A;
map<ll,ll>B;

ll C[MAX];
vector<int>V;

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>a>>b;

    cin>>n;

    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            A[i]=1;
            if(i*i!=a)A[a/i]=1;
        }
    }

    for(ll i=1;i*i<=b;i++){
        if(b%i==0){
            B[i]=1;
            if(i*i!=b)B[b/i]=1;
        }
    }

    for(auto it=A.begin();it!=A.end();it++){
        if(B[it->first]==1){
            V.pb(it->first);
        }
    }

    sort(V.begin(),V.end());

    for (ll i=1;i<=n;i++){
        cin>>p>>q;

        auto it=upper_bound(V.begin(),V.end(),q);
        ll low = V[it-V.begin()-1];
        if(low>=p)cout<<low<<endl;
        else cout<<-1<<endl;
    }



    return 0;
}