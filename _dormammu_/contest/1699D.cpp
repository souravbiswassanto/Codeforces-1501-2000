// Problem: D. Almost Triple Deletions
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/D
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
ll A[MAX], B[5002][5002], C[MAX], D[MAX];

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
        for(int i = 0; i <= n + 1; i++){
        	for(int j = 0; j <= n + 1; j ++){
        		B[i][j] = 0;
        	}
        	C[i] = 0; D[i] = -INT_MAX;
        }
        for(int i = 1; i <= n; i++){
        	cin >> A[i];
        }
        A[0] = INT_MAX;
        for(int i = 1; i <= n; i++){
        	Max = 0;
        	for(int j = i; j <= n; j++){
        		C[A[j]]++;
        		Max = max(Max, C[A[j]]);
        		B[i][j] = Max;
        	}
        	for(int j = i; j <= n; j++){
        		C[A[j]]--;
        	}
        }
        D[0] = 0;
        for(int i = 1; i <= n; i++){
        	if(A[i] == A[i - 1])D[i] = D[i - 1] + 1;
        	else{
        		for(int j = i - 1; j >= 0; j--){
        			if(A[i] == A[j] or j == 0){
        				a = B[j + 1][i - 1];
						b = i - j - 1;
						c = 0;
						if(a * 2 > b){
							c = b - a * 2;
						}
						else if(b % 2)c = -1;
						D[i] = max(D[j] + c + 1, D[i]);
        			}
        		}
        		
				
        	}
        }
        
        Max = 0;
        for(int i = n; i >= 1; i--){
        	a = B[i + 1][n];
			b = n - i;
			c = 0;
			if(a * 2 > b){
				c = b - a * 2;
			}
			else if(b % 2)c = -1;
			Max = max(Max, D[i] + c);
        }
        cout << Max << endl;

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