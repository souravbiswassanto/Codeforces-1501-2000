#include <bits/stdc++.h>
using namespace std ;
 
#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))
 
void fastIO ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}
 
int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,ans=1;
    ll x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;
 
    cin>>q;
    while(q--){
        cin>>n;
        ll A[n+8];
        for(int i=1; i<=n; i++)cin>>A[i];
        cin>>x>>a;
        cin>>y>>b>>k;
 
        if(x<y){
            int temp,Temp;
            temp=x;Temp=a;
            x=y;a=b;
            y=temp;b=Temp;
        }
        else if(x==y){
            if(a>b){int temp=a;a=b;b=temp;}
        }
        sort(A+1,A+n+1);
        ll left=1,right=n,sum=0,cntr=0,mid=(left+right)/2,check=0;
        ll B[n+6];
        ans=n;
        while(right-left>=4)
        {
            mid=(left+right)/2;
            sum=0,cntr=n;
            for(int i=1;i<=mid;i++)B[i]=0;
            for(int i=1;i<=mid;i++){
                if(i%a==0&&i%b==0&&B[i]==0){sum+=((A[cntr--]/100)*(x+y));B[i]=1;}
            }
            for(int i=1;i<=mid;i++){
                if(i%a==0&&B[i]==0){sum+=((A[cntr--]/100)*x);B[i]=1;}
            }
            for(int i=1;i<=mid;i++){
                if(i%b==0&&B[i]==0){sum+=((A[cntr--]/100)*y);B[i]=1;}
            }
            if(sum>=k)check=1;
            if(sum<k)
            {
                left=mid+1;
                ans=left;
            }
            else if(sum>k)
            {
                right=mid-1;
                ans=mid;
            }
            else
            {
                ans=mid;
                break;
            }  
        }
        ll aa=1;
        for(int j=min(n,right+8);j>=max(aa,left-2);j--){
            sum=0,cntr=n;
            for(int i=1;i<=j;i++)B[i]=0;
            for(int i=1;i<=j;i++){
                if(i%a==0&&i%b==0&&B[i]==0){sum+=((A[cntr--]/100)*(x+y));B[i]=1;}
            }
            for(int i=1;i<=j;i++){
                if(i%a==0&&B[i]==0){sum+=((A[cntr--]/100)*x);B[i]=1;}
            }
            for(int i=1;i<=j;i++){
                if(i%b==0&&B[i]==0){sum+=((A[cntr--]/100)*y);B[i]=1;}
            }
            if(sum>=k)check=1;
            if(sum>=k)ans=j;
        }
        if(check)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
 
    return 0;
}