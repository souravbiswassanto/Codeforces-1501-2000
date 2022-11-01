#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll T,N,M,X,Y,W,K,Q,R,P;

    ll A[100];

    for(int i=1;i<=3;i++) cin>>A[i];

    sort(A+1,A+4);

    cin>>X;

    ll a=A[2]-A[1]; ll b=A[3]-A[2];

    if(a>=X && b>=X){
        cout<<0<<endl; return 0;
    }

    if(a<X && b>=X){
        cout<<(X-a)<<endl;
        return 0;
    }

    if(b<X && a>=X){
        cout<<(X-b)<<endl;
        return 0;
    }

    cout<<(X-a)+(X-b)<<endl;

    return 0;
}