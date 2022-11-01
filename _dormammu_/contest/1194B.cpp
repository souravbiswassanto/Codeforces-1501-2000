#include<bits/stdc++.h>
using namespace std;

int main(){


    int q;
    cin>>q;

    while(q--){
        int n,m;
        cin>>n>>m;
        int Ans=INT_MAX;
        int cntr=0;

        int A[n+1][m+1];
        string s[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)A[i][j]=0;
        }

        for(int i=1;i<=n;i++){
            cin>>s[i-1];
        }
        for(int i=0;i<n;i++){
            cntr=0;
            for(int j=0;j<m;j++){
                if(s[i][j]=='.')cntr++;
            }

            for(int j=0;j<m;j++){
                A[i][j]=cntr;
            }
        }

        for(int i=0;i<m;i++){
            cntr=0;
            for(int j=0;j<n;j++){
                if(s[j][i]=='.')cntr++;
            }
            for(int j=0;j<n;j++){
                if(s[j][i]=='.')A[j][i]+=(cntr-1);
                else A[j][i]+=cntr;
                Ans=min(Ans,A[j][i]);
            }
        }
        cout<<Ans<<endl;

    }

    return 0;
}