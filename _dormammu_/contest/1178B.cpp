#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  1000006
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

    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='v'&&s[i+1]=='v'){
            cntr++;
        }

        if(s[i]=='o'){
            A[i]=cntr;

        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='v'&&s[i-1]=='v'){
            cnt++;
        }

        if(s[i]=='o'){
            B[i]=cnt;
        }
    }



    for(int i=0;i<s.size();i++){
        //cout<<i<<" "<<A[i]<<" "<<B[i]<<endl;
        if(s[i]=='o'){
            sum+=(A[i]*B[i]);
        }
    }

    cout<<sum<<endl;

    return 0;
}