#include <bits/stdc++.h>
using namespace std;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))

template <typename T>
T mymax (T a,T b){return (a>b)?a:b;}
template <typename T>
T mymin (T a,T b){return (a<b)?a:b;}
template <typename T>
T myabs (T a){return (a<0)?(-1*a):a;}
template <typename T>
T mysqrt (T x){if (x == 0 | x == 1)return x;int start = 1, End = x, ans;while (start <= End){int mid = (start + End) / 2;if (mid*mid == x)return mid;if (mid*mid < x){start = mid + 1;ans = mid;}else End = mid-1;}return ans;}

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

int main()
{

    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>q;
    while(q--){
        cin>>n>>r;
        ll A[n+5],B[n+5];
        cntr=1;
        cnt=0,ans=0;
        for(int i=1;i<=n;i++) cin>>A[i];
        sort(A+1,A+n+1);
        for(int i=2;i<=n;i++){
            if(A[i]==A[i-1])A[i-1]=-1;
        }
        for(int i=1;i<=n;i++){
            if(A[i]!=-1)B[cntr++]=A[i];
        }
        sort(B+1,B+cntr);
        for(int i=cntr-1;i>=1;i--){
            m=B[i]-cnt*r;
            if(m>0)ans++,cnt++;
        }
        cout<<ans<<endl;
    }

    return 0;
}