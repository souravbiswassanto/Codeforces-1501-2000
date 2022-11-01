/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 105
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

int n,k;


vector<int> g[maxn];

int curdist,curnode,par[maxn];

void dfs(int u,int p,int d){
	par[u]=p;
	if(d>curdist){
		curdist=d;
		curnode=u;
	}
	for(int v:g[u]){
		if(v==p) continue;
		dfs(v,u,d+1);
	}
}

int mark[maxn];

bool cmp(int a,int b){
	return mark[a]<mark[b];
}


void dfs2(int u,int par){
	//cout<<u<<" "<<par<<" "<<k<<endl;
	if(k<=0) return;
	for(int v:g[u]){
		//if(v==par) continue;
		if(v==par || mark[v] || k<=0) continue;
		//cout<<u<<" "<<v<<endl;
		mark[v]=1;
		k--;
		dfs2(v,u);
	}
}

bool found=false;

vector<int> print;

void init(int n){
	for(int i=1;i<=n;i++){
		g[i].clear();
		par[i]=-1;
		mark[i]=0;
	}
	print.clear();
	found=false;
	curdist=0; curnode=1;
}

void dfs3(int u,int par){
	//cout<<u<<" "<<curnode<<endl;
	if(!found)
		print.pb(u);//cout<<u<<" ";
	if(u==curnode) found=1;
	bool check=false;
	for(int v:g[u]){
		if(v==par || mark[v]==0) continue;
		//cout<<v<<endl;
		check=true;
		dfs3(v,u);
	    if(!found)
	    	print.pb(u);//cout<<u<<" ";
	   if(v==curnode) found=1;
	}
	//if(check) cout<<u<<endl;
}


int main()
{
	//what the hell are youing? Think again before coding.
	
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>n>>k;
		
		init(n);
		
		for(int i=2;i<=n;i++){
			cin>>x;
			g[x].pb(i);
			g[i].pb(x);
		}
		//cout<<k<<endl;
		curnode=1; curdist=0;
		
		dfs(1,-1,0);
		
		//cout<<curnode<<endl;
		
		vector<int> v;
		//v.pb(1);
		x=curnode;
		mark[1]=1;
		while(x!=1){
			v.pb(x);
			mark[x]=1;
			x=par[x];
		}
		v.pb(1);
		reverse(v.begin(),v.end());
		
		for(int i=1;i<=n;i++){
			sort(g[i].begin(),g[i].end(),cmp);
		}
		
		//for(int x:v) cout<<x<<" "; cout<<endl;
		
		//cnt=k-curdist-1;
		
		//dfs2(1,-1);
		//cout<<v.size()<<" "<<k<<endl;
		if(v.size()>=k){
			 cout<<k-1<<endl;
			for(int i=0;i<k;i++){
				 cout<<v[i]<<" ";
			 }
			 cout<<endl;
			 continue;
		 }
		 
		 
		
		 k=max(0,k-curdist-1);
		 //dfs2(1,-1);
		 
		 //cout<<k<<endl;
		
		 for(int x:v){
			 dfs2(x,-1);
		 }
		 dfs3(1,-1);
		 cout<<print.size()-1<<endl;
		 for(int x:print) cout<<x<<" ";
		 cout<<endl;
		
		//for(int i=1;i<=n;i++) cout<<i<<" "<<mark[i]<<endl;
		
		for(int i=1;i<=n;i++){
			g[i].clear();
			mark[i]=0;
			par[i]=-1;
		}
		found=false;
		print.clear();
	}

    return 0;
    //you should actually read the stuff at the bottom
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smooth instead of nothing and stay organized
	* don't get stuck on one approach, try another
	* don't waste time in one problem, try another
	* check PI value acos(-1.0)
*/