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
    ll cnt=0,cntr=1,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>n;

    for (int i=1;i<=n;i++){
        cin>>A[i];
    }


    for (int i=n+1;i<=16;i++)A[i]=-1;
    for (int i=1;i<16;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==16){
        cout<<16<<endl;
        return 0;
    }
    cntr=1;
    for (int i=1;i<8;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==8){
        cout<<8<<endl;
        return 0;
    }
    cntr=1;
    for (int i=9;i<16;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==8){
        cout<<8<<endl;
        return 0;
    }
    cntr=1;

    for (int i=1;i<4;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==4){
        cout<<4<<endl;
        return 0;
    }
    cntr=1;
    for (int i=5;i<8;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==4){
        cout<<4<<endl;
        return 0;
    }
    cntr=1;
    for (int i=9;i<12;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==4){
        cout<<4<<endl;
        return 0;
    }
    cntr=1;
    for (int i=13;i<16;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==4){
        cout<<4<<endl;
        return 0;
    }
    cntr=1;

    for (int i=1;i<2;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;

    for (int i=3;i<4;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=5;i<6;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=7;i<8;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=9;i<10;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=11;i<12;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=13;i<14;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;
    for (int i=15;i<16;i++){
        if(A[i]==-1)continue;
        if (A[i]<=A[i+1])cntr++;
    }

    if (cntr==2){
        cout<<2<<endl;
        return 0;
    }
    cntr=1;

    cout<<1<<endl;

    return 0;
}