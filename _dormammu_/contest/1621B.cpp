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
#define   ll     long long
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
ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        map<ll, ll> M;
        map<pair<ll, ll>, ll> MP;
        for(int i = 1; i <= n; i++){
            cin >> A[i] >> B[i] >> C[i];
            M[A[i]] = M[B[i]] = INT_MAX;
            MP[{A[i], B[i]}] = INT_MAX;
        }

        Min = 1e18; Max = 0;
        for(int i = 1; i <= n; i++){
            Min = min(A[i], Min);
            Max = max(B[i], Max);
            if(Min == A[i])M[Min] = min(M[Min], C[i]);
            if(Max == B[i])M[Max] = min(M[Max], C[i]);
            MP[{A[i], B[i]}] = min(MP[{A[i], B[i]}], C[i]);
            a = INT_MAX;
            if(MP[{Min, Max}] != 0) a = MP[{Min, Max}];
            if(Min == Max){
                b = M[Min];
            }
            else b = M[Min] + M[Max];
            cout << min(a, b) << endl;
        }

    }
    /*
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}