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

vector<int>prime;
set<int>se;
map<int,int>B;

int N=1e5;
bool mark[MAX];
void seive (){

    int limit = sqrt(N*1.0)+2;
    mark[1]=1;

    for (int i=4;i<=N;i+=2)mark[i]=1;

    prime.push_back(2);

    for (int i=3;i<=N;i+=2){
        if(!mark[i]){
            prime.push_back(i);

            if(i<=limit){
                for (int j=i*i;j<=N;j+=i*2)mark[j]=1;
            }
        }
    }

}


ll A[MAX];
ll C[MAX];
map<ll,ll>M;
map<ll,pair<ll,ll> >total_prime;

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;
    seive();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
        M[A[i]]=0;
    }
    sort(A,A+n);
    a=A[0];
    for(int i=0;prime[i]*prime[i]<=a;i++){
        if(a%prime[i])continue;
        cntr=0;
        while(a%prime[i]==0){
            a/=prime[i];
            cntr++;
        }
        if(prime[i]==2||prime[i]==3)continue;
        total_prime[prime[i]]=mp(1,cntr);
    }
    if(a!=1&&a!=2&&a!=3){
        total_prime[a]=mp(1,1);
    }
    int Size=total_prime.size();
    for(int i=1;i<n;i++){
        cnt=0;
        a=A[i];
        if(M[a]==1)continue;
        if(M[a]==0)M[a]=1;
        for(int j=0;prime[j]*prime[j]<=a;j++){
            cntr=0;
            if(a%prime[j])continue;
            while(a%prime[j]==0){
                a/=prime[j];
                cntr++;
            }
            if(prime[j]==2||prime[j]==3)continue;
            cnt++;
            if(total_prime[prime[j]].first==1){
                if(total_prime[prime[j]].second!=cntr){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            else {
                cout<<"No"<<endl;
                return 0;
            }
        }

        if(a!=1&&a!=2&&a!=3){
            if(total_prime[a].first==1){
                if(total_prime[a].second!=1){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            else {
                cout<<"No"<<endl;
                return 0;
            }
            cnt++;
        }
        if(cnt!=Size){
            cout<<"No"<<endl;return 0;
        }


    }
    cout<<"Yes"<<endl;


    return 0;
}