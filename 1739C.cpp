
// Problem: C. Card Game
// Contest: Codeforces - Educational Codeforces Round 136 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1739/problem/C
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
const int mod = 998244353 ;
int inv[MAX],fact[MAX];

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

void pre(){
	fact[0] = inv[0] = 1;
	for(int i = 1; i < MAX; i++){
		fact[i] = mul(fact[i - 1], i);
	}
	inv[MAX - 1] = bin_pow(fact[MAX - 1], mod - 2);
	for(int i = MAX - 2; i >= 1; i--){
		inv[i] = mul(inv[i + 1] , (i + 1));
	}
}
int ncr(int n, int r){
    if(n < 0 || r < 0 || n < r) return 0;
	int x = fact[n];
	int y = mul(inv[r],inv[n-r]);
	return mul(x, y);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t; pre();

    while(t--){
        cin >> n; sum = 0; r = n/2; a = r; cntr = 0; c = 2;
        
        for (int i = n; i >= 2; i -= 2) {
            if (cntr % 2 == 0) {
                b = ncr(i - 2, a - 2);
                sum = sum + b; sum %= mod;
                
            }
            else {
                b = ncr(i - 1, a - 1);
                sum = sum + b; sum %= mod;
            }
            a--;
            cntr++;
        }
        a = ncr(n, n/ 2);
        a = (a - sum - 1) % mod;
        if (a < 0) a += mod;
        cout << a <<" " << sum << " " << 1 << endl;

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
