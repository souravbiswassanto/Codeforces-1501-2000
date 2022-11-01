
// Problem: C. Bricks and Bags
// Contest: Codeforces - Codeforces Round #831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1740/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
        vector<ll> v; ll mx = 0, mn = INT_MAX; 
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            cin >> a; A[i] = a;v.pb(a); mx = max(mx, a); mn = min(mn, a);
        }
        sort(A, A + n);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        if (v.size() == 1) {
            cout << 0 << endl; continue;
        }
        if (v.size() == 2) {
            cout << (v[1] - v[0]) * 2LL << endl;
            continue;
        }
        ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                ans = mx - v[i] + (v[i + 1] - v[i]);
            }
            else if (i == v.size() - 1) {
                a = v[i] - mn + (v[i] - v[i - 1]);
                ans = max(ans, a);
            }
            else {
                a = max(v[i] - mn, mx - v[i]);
                b = min(v[i] - v[i - 1], v[i + 1] - v[i]);
                ans = max(ans, a + b);
            }
            //cout << ans << endl;
        }
        for (int i = 0; i < n; i++) {
            if (i - 2 >= 0) ans = max(ans, A[i] * 2LL - A[i - 1] - A[0]);
            if (i + 2 < n) ans = max(ans, A[i + 1] + A[n - 1] - 2 * A[i]);
            if (i - 1 >= 0 and i + 1 < n) ans = max(ans, A[i + 1] - A[0]);
            if (i - 1 >= 0 and i + 1 < n) ans = max(ans, A[n - 1] - A[i]);
            //if (i + 2 < n) ans = max(ans, A[i + 1] + A[n - 1] - 2 * A[i]);
            //if (i - 2 >= 0) ans = max(ans, A[0] + A[i - 1] - A[i] * 2);
        }
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