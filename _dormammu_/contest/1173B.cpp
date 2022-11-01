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

    cin>>x;
    a=int(x);
    x++;
    x/=2.0;
    ans=ceil(x);
    cout<<ans<<endl;

    for(int i=1;i<=ans;i++){
        cout<<1<<" "<<i<<endl;
    }
    for(int i=1;i<=a-ans;i++){
        cout<<ans<<" "<<i+1<<endl;
    }


    return 0;
}