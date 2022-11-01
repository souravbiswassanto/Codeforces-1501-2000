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

    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='0')cntr++;
        if(s[i]=='1')cnt++;
    }

    if(cntr!=cnt)cout<<1<<endl<<s<<endl;
    else {cout<<2<<endl;for(int i=0;i<s.size()-1;i++)cout<<s[i];cout<<" "<<s[n-1]<<endl;}

    return 0;
}