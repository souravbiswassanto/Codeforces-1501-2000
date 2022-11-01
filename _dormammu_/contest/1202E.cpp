
// Problem: E. You Are Given Some Strings...
// Contest: Codeforces - Educational Codeforces Round 70 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1202/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/* I love to solve string Problems.
My idea to solve this problem ->
for N strings,
divide strings into two set, the set which has length greater than
350, put them into heavy set, the strings which has length less 
than 350, put them into light set, now hash the strings of heavy set.
and build a trie with the stings of light set.Keep two array, one is endpoint array
which will keep count of strings ending at index i of Pattern T. another one is 
startpoint, which will keep the count of start index of any string s in pattern T at index
i. Now for each index of pattern
string T, do the following,
heavy set,
for each string of heavy set, match the hashes of strings on that set and  increase 
the counts respectively.
now for light set,
run a trie search on pattern from each index and  check how many endpoints are
there on the trie.
after counting whole thing,
answer should be summation of endpoint[i] * startpoint[i + 1] for each i from 1 to |T| - 1
*/
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
const int heavy = 450;
vector<string> heavyset, lightset;
ll Hash[MAX], p1[MAX], p2[MAX], endstr[MAX], startstr[MAX];
ll h1[MAX], h2[MAX], inv1[MAX], inv2[MAX];
const int mod1 = 1000000123, mod2 = 1000000007;
const int base1 = 39, base2 = 233;

ll binpow(ll b, ll e, int mod){
    if(e == 0)return 1;
    if(e == 1)return b % mod;
    ll d = binpow(b, e / 2, mod);
    d = (d * 1LL * d) % mod;
    if(e % 2 == 1) d = (d * 1LL * b) % mod;
    return d;
}

void pre(){
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= 200005; i++){
        p1[i] = (p1[i - 1] * 1LL * base1) % mod1;
        p2[i] = (p2[i - 1] * 1LL * base2) % mod2;
    }
    ll invp1 = binpow(base1, mod1 - 2, mod1);
    ll invp2 = binpow(base2, mod2 - 2, mod2);
    inv1[0] = inv2[0] = 1;
    for(int i = 1; i <= 200001; i++){
        inv1[i] = (inv1[i - 1] * 1LL * invp1) % mod1;
        inv2[i] = (inv2[i - 1] * 1LL * invp2) % mod2;
    }
}

ll get(int l, int r){
    ll x = ((h1[r] - h1[l - 1]) * 1LL * inv1[l - 1]) % mod1;
    if(x < 0) x += mod1;
    ll y = ((h2[r] - h2[l - 1]) * 1LL * inv2[l - 1]) % mod2;
    if(y < 0) y += mod2;
    
    return ((ll)x << 32) + y;
}

struct node{
    int endpoint;
    node* nxt[26];
    node(){
        endpoint = 0;
        for(int i = 0; i < 26; i++){
            nxt[i] = NULL;
        }
    }
};

void insert(string s, node* head){
    node* cur = head;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 97;
        if(cur->nxt[id] == NULL){
            cur->nxt[id] = new node();
        }
        cur = cur->nxt[id];
    }
    cur->endpoint++;
}

int search(string s, node* head){
    node* cur = head; int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 97;
        
        if(cur->nxt[id] == NULL)break;
        cur = cur->nxt[id];
        ans += cur->endpoint;
    }
    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    pre(); node* headfwd = new node(); node* headrev = new node();
    ll a, b, c, d, n, m, k, l, p, q, r,  x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0, Max = 0;
    string s, s1, s2, t;
    
    cin >> t;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(s.size() >= heavy)heavyset.pb(s);
        else {Max = max(Max, (ll)s.size()); lightset.pb(s);}
    }
    
    for(int i = 0; i < heavyset.size(); i++){
        x = 0, y = 0;
        s = heavyset[i];
        for(int j = 0; j < s.size(); j++){
            x = (x + (s[j] - 96) * 1LL * p1[j]) % mod1;
            y = (y + (s[j] - 96) * 1LL * p2[j]) % mod2;
        }
        Hash[i] = ((ll)x << 32) + y;
    }
    
    for(int i = 0; i < t.size(); i++){
        h1[i + 1] = (h1[i] + (t[i] - 96) * 1LL * p1[i]) % mod1;
        h2[i + 1] = (h2[i] + (t[i] - 96) * 1LL * p2[i]) % mod2;
    }
    
    for(int i = 0; i < lightset.size(); i++){
        s = lightset[i];
        s1 = s; reverse(s1.begin(), s1.end());
        insert(s, headfwd); insert(s1, headrev);    
    }
    
    for(int i = 0; i < t.size(); i++){
        cntr = 0;
        for(int j = 0; j < heavyset.size(); j++){
            if(i + 1 >= heavyset[j].size()){
                r = i + 1; l = r - heavyset[j].size() + 1;
                ll thash = get(l, r);
                ll shash = Hash[j];
                if(thash == shash)endstr[i]++;
            }
            if(t.size() >= i + heavyset[j].size()){
                l = i + 1;
                r = l + heavyset[j].size() - 1;
                ll thash = get(l, r);
                ll shash = Hash[j];
                if(thash == shash)startstr[i]++;
            }
        }
        if(Max == 0)continue;
        a = max(0LL, (i - Max) + 1);
        s = t.substr(a, i - a + 1); reverse(s.begin(), s. end());
        a = min((ll)t.size() - 1, i + Max - 1);
        s1 = t.substr(i, a - i + 1);
        endstr[i] += search(s, headrev);
        startstr[i] += search(s1, headfwd);
    }
    for(int i = 0; i < t.size() - 1; i++){
        sum += (endstr[i] * 1LL * startstr[i + 1]);
    }
    cout << sum << endl;
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