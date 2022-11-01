#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[300005];


int main()
{
    ll N,M;
    cin>>N;

    M=0;
    ll I=0;

    for(int i=1;i<=N;i++){
        cin>>A[i];

        if(A[i]>M){
            M=A[i];
            I=i;
        }
    }

    ll l=I-1,r=I+1;

    bool check=true;

    while(l>=1 || r<=N){
        if(A[I]>A[r] && A[r]>A[l]){
            I=r;
            r++;
        }
        else if(A[I]>A[l] && A[l]>A[r]){
            I=l;
            l--;
        }
        else{
            cout<<"NO"<<endl; return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}