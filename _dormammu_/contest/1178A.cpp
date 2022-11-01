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
vector<int>Ans;

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=0,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>A[i];
        B[i]=B[i-1]+A[i];
    }

    if(A[1]>B[n]-A[1]){
        cout<<1<<endl<<1<<endl;
        return 0;
    }
    ans=B[n];

    for(int i=1;i<=n;i++){
        if(i>1&&A[1]<A[i]*2)continue;
        sum+=A[i];
        ans-=A[i];
        Ans.pb(i);
        if(sum>ans){
            check=1;
            break;
        }
    }
    if(check){cout<<Ans.size()<<endl;

    for(int i=0;i<Ans.size();i++)cout<<Ans[i]<<" ";
    }
    else cout<<0<<endl;

    return 0;
}