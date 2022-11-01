#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
template <typename T>
T mymax (T a,T b){return (a>b)?a:b;}
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}


ll digitmul (ll n){
    ll mul=1,rem;
    while(n!=0){
        rem=n%10;
        mul*=rem;
        n/=10;
 }
    return mul;
}

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1;

    cin>>n;m=n;
    while(m){
        m/=10;cntr++;
    }
    m=n;
    Max=digitmul(n);
    for(int i=1;i<cntr;i++){
        p=digitmul(n);
        Max=mymax(p,Max);
        a=(m%10)+1;

        n-=(a*ans);
        if(n<=0)break;
        q=digitmul(n);

        Max=mymax(q,Max);
        ans*=10;
        m=n;
        m/=ans;
    }
    cout<<Max<<endl;
    return 0;
}