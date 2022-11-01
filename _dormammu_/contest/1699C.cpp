// Problem: C. The Third Problem
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define   maxn   500006
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
const ll MOD = 1e9 + 7;

ll bin_pow(ll o, ll s, ll mod) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    ll d = bin_pow(o, s/2, mod);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

ll inv[maxn],fact[maxn];
void pre(){
	fact[0]=inv[0]=1;
	for(ll i=1;i<maxn;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	inv[maxn-1]=bin_pow(fact[maxn-1],MOD-2,MOD);
	for(ll i=maxn-2;i>=1;i--){
		inv[i]=(inv[i+1]*(i+1))%MOD;
	}
}
ll ncr(ll n,ll r){
	ll x=fact[n];
	ll y=(inv[n-r])%MOD;
	return (x*y)%MOD;
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
    pre();

    while(t--){
        cin >>  n;
        set<int> S;
        
        for(int i = 0; i < n; i++){
        	cin >> A[i];
        	B[A[i]] = i;
        }
        S.insert(0); ans = 1LL;
        l = B[0]; r = B[0]; int cur = 0; int last = 1;
        for(int i = 1; S.size() != n; i++){
        	int pos = B[cur + 1];
        	if(pos < l){
        		a = pos; b = l - 1; l = a;
        	}
        	else{
        		b = pos; a = r + 1; r = pos;
        	}
        	for(int j = a; j <= b; j++){
        		S.insert(A[j]);
        	}
        	while(S.find(cur + 1) != S.end()){
        		cur++;
        	}
        	int range = r - l + 1;
        	range -= (last + 1);
        	c = ncr(range, cur - last);
        	
        	ans = (ans * 1LL * c) % MOD;
        	last = cur + 1;
        }
        cout << ans << "\n";

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