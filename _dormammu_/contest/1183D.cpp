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

ll rev (ll a,ll b){
    return a>b;
}

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=1e9,cntr=0,sum=0,ans=0,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>q;

    while(q--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a;
            B[a]++;
        }

        sort(B+1,B+n+1,rev);

        for(int i=1;i<=n;i++){
            if(cnt<1||B[i]==0)break;
            if(C[B[i]]==1){
                cnt--;
                sum+=(max(ans,cnt));
                C[max(cnt,ans)]=1;
            }
            else if(C[B[i]]==0){
                sum+=B[i];
                cnt=B[i];
                C[B[i]]=1;
            }


        }
        cout<<sum<<endl;
        for(int i=1;i<=n;i++){B[i]=0;C[i]=0;}
        sum=0;
        cnt=1e9;
    }

    return 0;
}