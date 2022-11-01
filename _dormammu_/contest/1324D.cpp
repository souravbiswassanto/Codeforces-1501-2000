/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
 
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);
 
    ll t,n,m,x,y,w,k,q,r,p,cs;
 
    oset< pair<ll,ll> > s;
 
    cin>>n;
    ll a[n+2],b[n+2];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
 
    s.insert({a[1]-b[1],1});
    ll ans=0;
    for(int i=2;i<=n;i++){
        x=1-(a[i]-b[i]);
        r=s.order_of_key({x,0});
        //cout<<i<<" "<<x<<" "<<r<<" "<<i-r-1<<endl;
        ans+=(i-r-1);
        s.insert({a[i]-b[i],i});
    }
 
    cout<<ans<<endl;
 
    return 0;
}