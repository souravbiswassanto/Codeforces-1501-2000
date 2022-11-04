// Problem: E. Binary Deque
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: B. All Distinct
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/B
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
        cin >>  n >> k;
        sum = 0;
        for(int i = 0; i < 2 * n + 2; i++){
        	B[i] = 0;
        }
        for(int i = 0; i < n; i++){
        	cin >> A[i];
        	sum += A[i];
        	A[i + n] = A[i];
        }
        B[0] = A[0];
        for(int i = 1; i < 2 * n; i++){
        	B[i] = B[i - 1] + A[i];
        }
        ans = sum;
        if(sum < k){
        	cout << -1 << endl;
        	continue;
        }
        if(sum == k){
        	cout << 0 << endl;
        	continue;
        }
        l = 1; r = n;
        b = ans - k;
        while(l <= r){
        	int mid = (l + r) / 2;
        	Max = 0;
        	for(int i = n - mid; i <= n; i++){
        		Max = max(Max, B[i + mid - 1] - B[i - 1]);
        	}
        	if(Max >= b){
        		r = mid - 1;
        	}
        	else l = mid + 1;
        }
		cout << l << endl;
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