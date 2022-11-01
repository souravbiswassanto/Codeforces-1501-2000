/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
int mark[500006];

queue< pair<int,int> > a;
//priority_queue< pair<int,int> > b;

struct ff{
    int first,second;
    ff(int a,int b){
        first=a;
        second=b;
    }
};
bool operator<(ff a,ff b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
//bool operator<(node a,node b)
//{
//    return a.Cost>b.Cost;
//}


priority_queue<ff> b;

int main()
{
    int q;
    cin>>q;
    int i=1;
    while(q--){
        int t,n;
        cin>>t;
        if(t==1){
            cin>>n;
            a.push(mp(n,i));
            b.push(ff(n,i));
            i++;
            //cout<<n<<"  "<<i<<endl;
        }
        else if(t==2){
            while(mark[a.front().second]){
                a.pop();
            }
            cout<<a.front().second<<" ";
            mark[a.front().second]=1;
            a.pop();
        }
        else{
            while(mark[b.top().second]){
                b.pop();
            }
            cout<<b.top().second<<" ";
            mark[b.top().second]=1;
            b.pop();
        }
    }
    cout<<endl;

    return 0;
}