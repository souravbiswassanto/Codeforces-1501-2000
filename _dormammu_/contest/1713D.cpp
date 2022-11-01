// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1713/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

ll get(int a, int b, int c, int d){
	cout << "? " << a <<" " << c << endl;
	int p;
	cin >> p;
	if(p == 0){
		cout << "? " << b <<" " << d << endl;
		cin >> p;
		if(p == 1) return b;
		else return d;
	}
	else if(p == 1) {
		cout << "? " << a <<" " << d << endl;
		cin >> p;
		if(p == 1) return a;
		else return d;
	}
	else{
		cout << "? " << b <<" " << c << endl;
		cin >> p;
		if(p == 1) return b;
		return c;
		
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
        cin >>  n;
        a = 1 << n; 
        for(int i = 1; i <= a; i++) A[i] = i;
        while(a > 4){
        	cntr = 1;
	        for(int i = 1; i <= a; i += 4) {
	        	A[cntr++] = get(A[i], A[i + 1], A[i + 2], A[i + 3]);
	        }
	        a /= 4;
		}
		
		if(a == 4) {
			p = get (A[1], A[2], A[3], A[4]);
			cout << "! "<< p << endl;
		}
		else{
			cout <<"? "<< A[1] <<" "<< A[2] << endl;
			cin >> p;
			if(p == 1) p = A[1];
			else p = A[2];
			cout << "! " << p << endl;
		}
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