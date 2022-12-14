#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))

template <typename T>
T mymax (T a,T b){return (a>b)?a:b;}
template <typename T>
T mymin (T a,T b){return (a<b)?a:b;}
template <typename T>
T myabs (T a){return (a<0)?(-1*a):a;}
template <typename T>
T mysqrt (T x){if (x == 0 | x == 1)return x;int start = 1, End = x, ans;while (start <= End){int mid = (start + End) / 2;if (mid*mid == x)return mid;if (mid*mid < x){start = mid + 1;ans = mid;}else End = mid-1;}return ans;}

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< ll >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>q;

    while(q--){
        cin>>n>>k;
        set<ll>S;
        cin>>s;
        for(int i=0;i<26;i++)A[i]=0;
        for(int i=0;i<n;i++){
            A[s[i]-'a']++;
            S.insert(s[i]-'a');
        }

        int pos,pos1,pos2;
        for(int i=0;i<26;i++){
            if(A[i]){
                pos=i;break;
            }
        }
        for(int i=pos+1;i<26;i++){
            if(A[i]){
                pos1=i;break;
            }
        }
        for(int i=pos1+1;i<26;i++){
            if(A[i]){
                pos2=i;break;
            }
        }

        if(S.size()==1){

            for(int i=0;i<n/k;i++){
                cout<<char(97+pos);
            }
            if(n%k)cout<<char(97+pos);
            cout<<endl;
        }
        else if(A[pos]<k){
            for(int i=0;i<26;i++){
                k-=A[i];
                if(k<=0){
                    cout<<char(97+i)<<endl;break;
                }
            }
        }
        else if(A[pos]>k){
            sort(s.begin(),s.end());
            for(int i=k-1;i<n;i++){
                cout<<s[i];
            }
            cout<<endl;
        }
        else {
            if(S.size()==2){
                cout<<char(97+pos);
                for(int i=0;i<A[pos1]/k;i++)cout<<char(97+pos1);
                if(A[pos1]%k)cout<<char(97+pos1);
                cout<<endl;
            }
            else{
                cout<<char(97+pos);
                for(int i=pos+1;i<26;i++){
                    for(int j=0;j<A[i];j++){
                        cout<<char(97+i);
                    }
                }
                cout<<endl;
            }
        }
    }



    return 0;
}