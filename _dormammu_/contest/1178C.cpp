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

ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    ll height,width;
    ll rem=(ll)998244353;

    cin>>width>>height;

    m=width;
    n=height;
//
//    width=max(n,m);
//    height=min(n,m);
//
//    for(int i=1;i<=width+1;i++){
//        ans=(ans*2)%rem;
//    }
//    for(int i=1;i<=height;i++){
//
//        sum=(sum+(ans%rem))%rem;
//    }

    for(int i=1;i<=n+m;i++){
        ans=(ans*2)%rem;
    }

    cout<<ans<<endl;

    return 0;
}