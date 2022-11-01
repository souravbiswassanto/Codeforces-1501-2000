#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    string s;
    cin>>s;
    int len=s.length();
    vector< pair<char,ll> > v;
    map<char,ll> vv;
    for(int i=0;i<len;i++){
        ll cnt=1;
        int j=i+1;
        while(s[j]==s[i] && j<len){
            cnt++;j++;
        }
        v.pb(mp(s[i],cnt));
        vv[s[i]]++;
        i=j-1;
    }

//    for(auto it:v){
//        cout<<it.first<<" "<<it.second<<endl;
//    }

    if(v.size()%2==0){
        cout<<0<<endl; return 0;
    }
    auto md=v[v.size()/2];

    if(md.second<2){
        cout<<0<<endl; return 0;
    }
    ll mid=v.size()/2;
    for(int i=mid-1,j=mid+1;i>=0,j<v.size();i--,j++){
        ll cnt=v[i].second+v[j].second;
        if(v[i].first==v[j].first){
            if(cnt<3){
                cout<<0<<endl; return 0;
            }
        }
        else{
            cout<<0<<endl; return 0;
        }
    }

    cout<<md.second+1<<endl;

    return 0;
}