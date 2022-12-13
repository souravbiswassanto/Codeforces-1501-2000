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
vector<ll>prime;
bool mark[MAX1];
ll N = 38006;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
const int mod = 1000000007;
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

    seive();
    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        map<ll, ll> M; check = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; prime[j] * 1LL * prime[j] <= A[i]; j++) {
                if (A[i] % prime[j] != 0) continue;
                M[prime[j]]++;
                if (M[prime[j]] >= 2) {
                    check = 1; break;
                } 
                while(A[i] % prime[j] == 0) {
                    A[i] /= prime[j];
                }
            }
            if(A[i] != 1) {
                M[A[i]]++;
                if (M[A[i]] >= 2) {
                    check = 1; break;
                }
            }
            if(check == 1)break;
        }
        if(!check) no;
        else yes;

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