#include<bits/stdc++.h>
using namespace std;

int main (){

    int n;
    long long ans;
    long long A[100006];
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(A+1,A+n+1);
    int m=n;
    long long sum=0,res=0;
    for(int i=1;i<=n/2;i++){
        sum+=A[i];
        res+=A[m--];
    }
    if(n%2)res+=(A[n/2+1]);
    cout<<(sum*sum)+(res*res)<<endl;
    return 0;
}