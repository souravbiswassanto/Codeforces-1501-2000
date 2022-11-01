#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back


int main()
{

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;

    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        else if(n==2)
        {
            if(s[0]==s[1] || s[0]<s[1])
                cout<<1<<1<<endl;
            else
                cout<<21<<endl;
            continue;
        }
        set<char> ss;
        for(int i=0; i<n; i++)
            ss.insert(s[i]);
        //reverse(ss.begin(),ss.end());
        vector<char> vv;
        for(auto it:ss)
        {
            vv.pb(it);
        }
        reverse(vv.begin(),vv.end());
        int idx=n-1;
        int idx1=n;
        ll ans[n+5]= {0};
        for(char it:vv)
        {
            bool check=false;
            bool check1=false;
            for(int i=n-1; i>=0; i--)
            {
                if(s[i]==it)
                {
                    idx=i;
                    check=true;
                    if(idx>idx1)
                    {
                        check1=true;
                    }
                    if(idx<idx1)ans[i]=2;
                }

            }
            //cout<<idx1<<" "<<idx<<" "<<it<<endl;
            idx1=idx;
            if(check==false)
                break;
            if(check1==true)
                break;
        }
        //for(int i=0;i<n;i++) cout<<s[i]<<ans[i]<<" "; cout<<endl;
        reverse(vv.begin(),vv.end());
        vector<char> v1;
        for(int i=0; i<n; i++)
        {
            if(ans[i]!=2)
            {
                v1.pb(s[i]);
            }
        }
        bool check=true;
        for(int i=1; i<v1.size(); i++)
        {
            if(v1[i]<v1[i-1])
            {
                check=false;
                break;
            }
        }
        if(!check)
        {
            cout<<"-"<<endl;
            continue;
        }
        for(int i=0; i<n; i++)
        {
            if(ans[i]==2)
                cout<<2;
            else
                cout<<1;
        }
        cout<<endl;
    }

    return 0;
}