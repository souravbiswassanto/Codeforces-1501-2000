
// Problem: D. Paths on the Tree
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
ll A[MAX], B[MAX], C[MAX], ans;
vector<ll> g[MAX], v[MAX];

ll dfs(ll source, ll par, ll k) {
    ans += (k * 1LL * A[source]);
    ll a = g[source].size();
    if(par != 0) a--;
    ll b = 0;
    if (a) b = k % a;
    ll sum = 0;
    ll mx = 0;
    for (auto V: g[source]) {
        if (V == par) continue;
        ll c = dfs(V, source, k / a);
        v[source].pb(c);
    }
    sort(v[source].rbegin(), v[source].rend());
    
    for (int i = 0; i < b; i++) {
        sum += v[source][i];
    }
    if (v[source].size() > b) mx = v[source][b];
    else if(b and v[source].size() == b)mx = v[source][0];
    ans += sum;
    //cout << source <<" " << mx + A[source] <<" " << sum << endl;
    return mx + A[source];
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        for (int i = 0; i <= n + 2; i ++) {
            g[i].clear(); v[i].clear();
        }
        ans = 0;
        for (int i = 2; i <= n; i ++) {
            cin >> a; g[a].pb(i);
            g[i].pb(a);
        }
        for (int i = 1; i <= n; i ++) {
            cin >> A[i];
        }
        dfs(1, 0, k);
        cout << ans << endl;

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
