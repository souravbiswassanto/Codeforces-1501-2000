
// Problem: C. Phase Shift
// Contest: Codeforces - Codeforces Round #824 (Div. 2)
// URL: https://codeforces.com/contest/1735/problem/C
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
int B[27];
vector<int> g[30];

void dfs(int u, int par) {
    B[u] = 1;
    for(auto v: g[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        cin >> s;
        int A[30], taken[30];
        for (int i = 0; i < 26; i++) {
            g[i].clear();
        }
        mem(A, -1);
        mem(taken, 0);
        s1 = "";
        for (int i = 0; i < n; i++) {
            a = s[i] - 97;
            if (A[a] != -1) {
                s1 += char(97 + A[a]);
                continue;
            }
            mem(B, 0);
            dfs(a, -1);
            cntr = 0;
            for (int j = 0; j < 26; j++) {
                if (B[j])cntr++;
            }
            for (int j = 0; j < 26; j++) {
                if (B[j] or taken[j]) continue;
                g[j].pb(a);
                A[a] = j; taken[j] = 1;
                s1 += char(97 + j);
                break;
            }
            if (cntr == 26) {
                for (int j = 0; j < 26; j++) {
                    if (taken[j] == 0) {
                        taken[j] = 1;
                        s1 += char(97 + j);
                        A[a] = j;break;
                    }
                }
            }
        }
        cout << s1 << endl;

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