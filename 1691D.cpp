
// Problem: D. Max GEQ Sum
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

struct segtree{
    int n;
    vector<pair<ll, ll>> tree;
    void init(int _n){
        n = _n;
        tree.resize(4 * n);
    }
    void build(int node, int b, int e){
        if(b == e){
            tree[node].first = B[b];
            tree[node].second = B[b];
            return;
        }
        int mid = (b + e) / 2;
        int left = node * 2;
        int right = left + 1;
        build(left, b, mid);
        build(right, mid + 1, e);
        tree[node] = {max(tree[left].first, tree[right].first), min(tree[left].second, tree[right].second)};
    }
    
    pair<ll, ll> query(int node, int b, int e, int l, int r){
        if(l <= b and r >= e)return tree[node];
        if(e < l or r < b)return {-1e18, 1e18};
        int mid = (b + e) / 2;
        int left = node * 2;
        int right = left + 1;
        pair<ll, ll> L = query(left, b , mid , l , r);
        pair<ll, ll> R = query(right, mid + 1 , e, l , r);
        return {max(L.first, R.first), min(L.second, R.second)};
    }
};

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
        cin >> n;
        int L[n + 2], R[n + 2];
        for(int i = 0; i <= n; i++){
            B[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            B[i] = B[i - 1] + A[i];
        }
        for(int i = 1; i <= n; i++){
            L[i] = R[i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            int j = i - 1;
            while(j >= 1 and A[j] <= A[i]){
                L[i] += L[j];
                j -= L[j];
            }
        }
        for(int i = n - 1; i >= 1; i--){
            int j = i + 1;
            while(j <= n and A[j] <= A[i]){
                R[i] += R[j];
                j += R[j];
            }
        }
        segtree st;
        st.init(n);
        st.build(1, 1, n);
        
        check = 0;
        for(int i = 1; i <= n; i++){
            if(R[i] + L[i] - 1 == 1)continue;
            a = st.query(1, 1, n, (i - L[i] == 0)?1: i - L[i], i - 1).second;
            if(i - L[i] == 0) a = min(a, 0LL);
            b = st.query(1, 1, n, i, i + R[i] - 1).first;
            if(b - a > A[i])check = 1;
        }
        if(check)no;
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
