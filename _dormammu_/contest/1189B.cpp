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

    cin>>n;

    for(int i=1;i<=n;i++)cin>>A[i];

    sort(A+1,A+n+1);

    sum=A[n-1]+A[n-2];

    if(sum<=A[n]){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;

        cout<<A[n-1]<<" "<<A[n]<<" "<<A[n-2]<<" ";
        for(int i=n-3;i>=1;i--)cout<<A[i]<<" ";
        cout<<endl;
    }

    return 0;
}