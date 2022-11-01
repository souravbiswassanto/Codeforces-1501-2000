#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char A[]={'0','m','p','s'};

bool OK(string sp,string ss,string sr){
    if(sp==ss && ss==sr) return true;
    if(sp[1]==ss[1] && ss[1]==sr[1]){
        vector<ll> S;
        S.push_back(sp[0]-48);
        S.push_back(ss[0]-48);
        S.push_back(sr[0]-48);
        sort(S.begin(),S.end());
        for(int i=0;i<2;i++){
            if(S[i]+1!=S[i+1]) return false;
        }
        return true;
    }
    return false;
}

int main()
{

    ll T,N,M,X,Y,W,K,Q,R,P;
    string S;
    vector<string> V;
    for(int i=1;i<=3;i++){
        cin>>S;
        V.push_back(S);
    }
    sort(V.begin(),V.end());
    ll ans=1000000;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                for(int k=1;k<=9;k++){
                    for(int l=1;l<=3;l++){
                        string sp,ss,sr;
                        sp+=(i+48);
                        sp+=A[l];
                        ss+=(j+48);
                        ss+=A[l];
                        sr+=(k+48); sr+=(A[l]);
                        if(OK(sp,ss,sr)){
                            ll cnt=0;
                            if(sp!=V[0]) cnt++;
                            if(ss!=V[1]) cnt++;
                            if(sr!=V[2]) cnt++;
                            ans=min(ans,cnt);
                        }
                    }
                }
            }
        }

        cout<<ans<<endl;

    return 0;
}