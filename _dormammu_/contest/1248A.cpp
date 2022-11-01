#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n,m,t,p,q,ans;

    cin>>t;

    while(t--){
        cin>>n;
        ll A[n+2];
        ll ceven=0,codd=0,beven=0,bodd=0;
        for(int i=0;i<n;i++){
            cin>>A[i];
            if(A[i]%2)codd++;
            else ceven++;
        }
        cin>>m;
        ll B[m+2];
        for(int i=0;i<m;i++){
            cin>>B[i];
            if(B[i]%2)bodd++;
            else beven++;
        }

        cout<<(bodd*codd)+(beven*ceven)<<endl;
    }

    return 0;
}