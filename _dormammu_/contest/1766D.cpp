
// Problem: D. Lucky Chains
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
#define   ll     int
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
int A[MAX], B[MAX], C[MAX];
//bool mark[MAX1];
int N = 1e7;
int spf[10000004];
void seive ()
{
    for(int i = 1; i <= N; i++)spf[i] = i;
    int limit = sqrt(N*1.0)+2; spf[1] = 1; spf[2] = 2;
    for (int i=4; i<=N; i += 2)spf[i]=2;
    //i*i <=N kora jave
    for (int i=3; i<=N; i+=2)
    {
        if(spf[i]==i)
        {
            if(i<=limit)
            {
                for (int j=i*i; j<=N; j+=i*2){
                    if(spf[j]==j)spf[j] = i;
                }
            }
        }
    }
}




int main ()
{
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    string s, s1, s2;
    
    seive();

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &x, &y);
        ll gap = (y - x);
        if(__gcd(x, y) > 1) {
            printf("0\n"); continue;
        }
        if (gap == 1) {
            printf("-1\n"); continue;
        }
        ans = INT_MAX;
        while (gap != 1){
            a = x % spf[gap];
            b = y % spf[gap];
            if (a == b) {
                ans = min(ans, spf[gap] - a);
            }
            gap = gap / spf[gap];
        }
        if(ans == INT_MAX) printf("-1\n");
        else {
            printf("%d\n", ans);
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