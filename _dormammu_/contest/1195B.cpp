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
    ll cnt=0,cntr=0,sum=0,ans=0,check=0;
    float x,y,z;
    ll Max=1e9+8;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;
 
    cin>>n>>k;
 
    ll left=0,right=n;
 
    ll mid;
 
    while(left<=right){
        mid=(left+right)/2;
 
        sum=(mid*(mid+1))/2;
 
        if(sum-(n-mid)<k){
            left=mid+1;
        }
        else if(sum-(n-mid)>k){
            right=mid-1;
        }
        else{
            ans=n-mid;
            break;
        }
    }
    cout<<ans<<endl;
 
    return 0;
}