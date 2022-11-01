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

ll B[MAX];
ll C[MAX];

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,t,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>t;


    while(t--){
        cin>>n;
        int A[n+1];
        int cn=2;

        for(int i=0;i<n;i++)cin>>A[i];

        sort(A,A+n);
        int AA=A[n-2]-1,BB=n-2;

        ans=min(AA,BB);

        cout<<ans<<endl;
    }
    return 0;
}