
// Problem: G. SlavicG's Favorite Problem
// Contest: Codeforces - Codeforces Round #835 (Div. 4)
// URL: https://codeforces.com/contest/1760/problem/G
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
vector<pair<int, int>> g[MAX];
vector<int> vec;
bool found = false;
void dfs(int source, int Xor, int par) {
    
    for (auto pr: g[source]) {
        int v = pr.first;
        int w = pr.second;
        if (v == par) continue;
        vec.pb(Xor ^ w);
        if ((Xor ^ w) == 0) found = true;
        dfs(v, Xor ^ w, source);
    }
}

ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;

void dfs1(int source, int Xor, int par) {
    
    for (auto pr: g[source]) {
        int v = pr.first;
        int w = pr.second;
        if (v == par or v == b) continue;
        
        if (binary_search(vec.begin(), vec.end(), Xor^ w)) found = true;
        dfs1(v, Xor ^ w, source);
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> a >> b;
        vec.clear(); found = false;
        for (int i = 0; i <= n + 2; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> p >> q >> x;
            g[p].pb({q, x});
            g[q].pb({p, x});
        }
        dfs(b, 0, -1);
        sort(vec.begin(), vec.end());
        
        if(binary_search(vec.begin(), vec.end(), 0)){
            yes; continue;
        }
        dfs1(a, 0, -1);
        if (found) yes;
        else no;
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