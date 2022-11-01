
// Problem: E. Robot on the Board 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
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
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 0;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m;
        cin >> s;
        l = 0, r = 0; d = 0; int u = 0; x = 0, y = 0;
        int ml = 0, mr = 0, md = 0, mu = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U'){
                y++;
                mu = max(mu, y);
                if(mu + md >= n){
                    mu--;
                    break;
                }
            }
            if(s[i] == 'D'){
                y--;
                md = max(md, abs(y < 0?y: 0));
                if(mu + md >= n)break;
            }
            if(s[i] == 'R'){
                x++;
                mr = max(mr, x);
                if(mr + ml >= m)break;
            }
            if(s[i] == 'L'){
                x--;
                ml = max(ml, abs(x < 0?x: 0));
                if(mr + ml >= m){
                    ml--; break;
                }
            }
            
        }
        cout << mu + 1 <<" "<< ml + 1 << endl;

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