
// Problem: F. Vlad and Unfinished Business
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1675/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
vector<int> g[MAX];
int level[MAX];
ll sum = 0, x, y;

int dfs(int u, int par, int depth){
    level[u] = depth;
    ll Or = 0;
    for(auto v: g[u]){
        if(v == par)continue;
        Or |= dfs(v, u, depth + 1);
    }
    if(C[u])Or = 1;
    if(Or and u != x) sum += 2;
    //cout << u <<" "<< C[u] <<" "<<sum << endl;
    return Or;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t;
    ll cnt = 0, cntr = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        cin >> x >> y;
        
        sum = 0;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            level[i] = 0;
            C[i] = 0;
        }
        C[y] = 1; C[x] = 1;
        for(int i = 0; i < k; i++){
            cin >> a; C[a] = 1;
        }
        for(int i =  1; i < n; i++){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        ans = dfs(x, -1, 0);
        cout << sum - level[y] << endl;

    }
    /* 
        precedence : ! * / % + - << >> 
        < > <= >= == != & ^ | && ||
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
