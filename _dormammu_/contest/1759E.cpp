
// Problem: E. The Humanoid
// Contest: Codeforces - Codeforces Round  #834 (Div. 3)
// URL: https://codeforces.com/contest/1759/problem/E
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

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, h, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> h;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A, A+ n); a = -1; ans = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < h) {
                h += (A[i] / 2);
                a = i;
                ans = i + 1;
            }
            else break;
        }
        
        b = h;
        b *= 3LL; cntr = 0;
        for (int i = a + 1; i < n; i++) {
            if (A[i] < b) {
                b += A[i] / 2;
                ans = i + 1;
            }
            else if (cntr < 2) {
                cntr++; b *= 2; i--;
            }
            else break;
        }
        
        b = h;
        b *= 2; cntr = 0;
        for (int i = a + 1; i < n; i++) {
            if (A[i] < b) {
                b += A[i] / 2;
                ans = max(ans, (ll)i + 1);
            }
            else if (cntr == 0) {
                cntr++; b *= 3; i--;
            }
            else if (cntr == 1) {
                cntr++; b *= 2LL; i--;
            }
            else break;
        }
        
        b = h;
        b *= 2; cntr = 0;
        for (int i = a + 1; i < n; i++) {
            if (A[i] < b) {
                b += A[i] / 2;
                ans = max(ans, (ll)i + 1);
            }
            else if (cntr == 0) {
                cntr++; b *= 2; i--;
            }
            else if (cntr == 1) {
                cntr++; b *= 3LL; i--;
            }
            else break;
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