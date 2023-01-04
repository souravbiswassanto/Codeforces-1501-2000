
// Problem: C. Least Prefix Sum
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/C
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
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m;
        cntr = 0;
        for (int i = 0; i <= n + 4; i++) {
            B[i] = 0; C[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> A[i]; 
        }
        
        for (int i = 1; i <= m; i++) {
            B[i] = B[i - 1] + A[i];
        }
        priority_queue<ll> pq, pq1;
        for (int i = m; i >= 1; i--) {
            
            while(pq.size() and B[m] > B[i]) {
                a = pq.top(); pq.pop();
                B[m] -= 2LL * a; cntr++;
                //cout << i << " ";
            }
            if (A[i] > 0) {
                pq.push(A[i]);
            }
        }
        while(pq.size() and B[m] > B[1]) {
            a = pq.top(); pq.pop();
            B[m] -= 2LL * a; cntr++;
            //cout << i << " ";
        }
        ll last = B[m];
        for (int i = m + 1; i <= n; i++) {
            B[i] = last + A[i];
            if (A[i] < 0) {
                pq1.push(A[i] * -1LL);
            }
            while(pq1.size() and B[m] > B[i]) {
                a = pq1.top(); pq1.pop();
                B[i] += 2LL * a;
                cntr++;
                //cout << i << " ";
            }
            last = B[i];
        }
        cout << cntr << endl;

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