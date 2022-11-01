
// Problem: D. Counting Arrays
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/D
// Memory Limit: 512 MB
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
ll dp1[MAX], dp2[MAX];
const ll mod = 998244353;
vector<ll>prime;
bool mark[MAX1];
ll N = 1e5;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    seive();
    cin >> n >> m; 
    ll M = m;
    m %= mod;
    for (int i = 1; i <= n; i++) {
        ans = (ans * m) % mod;
        dp1[i] = (dp1[i - 1] + ans) % mod;
    }
    ll Lcm = 1LL;
    for (int i = 1; i <= n; i++) {
        if(Lcm <= M and binary_search(prime.begin(), prime.end(), i)) Lcm = Lcm * 1LL * i;
       A[i] = M / Lcm; A[i] %= mod;
    }
    ans = 1LL;
    
    for (int i = 1; i <= n; i++) {
        ans = (ans * 1LL * A[i]) % mod;
        dp2[i] = (dp2[i - 1] + ans) % mod;
    }
    ans = dp1[n] - dp2[n];
    if (ans < 0) ans += mod;
    cout << ans << endl;
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