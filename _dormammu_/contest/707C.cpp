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

vector<ll>prime;
bool mark[100006];
ll N=1e5+6;

void seive (){

    int limit = sqrt(N*1.0)+2;
    mark[1]=1;

    for (int i=4;i<=N;i+=2)mark[i]=1;

    prime.push_back(2);

    for (int i=3;i<=N;i+=2){
        if(!mark[i]){
            prime.push_back(i);

            if(i<=limit){
                for (int j=i*i;j<=N;j+=i*2)mark[j]=1;
            }
        }
    }
}

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;
    seive();

    cin>>n;

    if(n==1||n==2){
        cout<<-1<<endl;
        return 0;
    }
    if(n%4==0){
        cout<<3*(n/4)<<" "<<5*(n/4)<<endl;///if p q r is a pht triple then pk qk rk is also
        return 0;
    }
    m=n;
    ///finding a prime.for a prime, rest two triples are (prime*prime)/2,(prime*prime)/2+1.then just multipling acording to the above method
    for(int i=0;prime[i]*prime[i]<=m;i++){
        while(m%prime[i]==0){
            m/=prime[i];
            a=prime[i];
        }
    }
    if(m!=1){
        a=m;
    }

    b=n/a;
    ll square=a*a;
    ll ans1,ans2;
    ans1=square/2;
    ans2=ans1+1;
    ans1*=b;
    ans2*=b;

    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}