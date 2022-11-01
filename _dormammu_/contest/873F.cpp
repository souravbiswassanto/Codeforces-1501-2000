
// Problem: F. Forbidden Indices
// Contest: Codeforces - Educational Codeforces Round 30
// URL: https://codeforces.com/problemset/problem/873/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// Problem: Substrings and Repetitions
// Contest: CodeChef - COOK46
// URL: https://www.codechef.com/problems/ANUSAR
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
using namespace std;

#define MAX 300006
#define ll long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vil;

const int MAX_N = 450010;                        // can go up to 450K chars
char T[MAX_N],temp[MAX_N];
char P[MAX_N];

class SuffixArray {
private:
  vi RA;                                         // rank array
  
  void countingSort(int k) {                     // O(n)
    int maxi = max(300, n);                      // up to 255 ASCII chars
    vi c(maxi, 0);                               // clear frequency table
    for (int i = 0; i < n; ++i)                  // count the frequency
      ++c[i+k < n ? RA[i+k] : 0];                // of each integer rank
    for (int i = 0, sum = 0; i < maxi; ++i) {
      int t = c[i]; c[i] = sum; sum += t;
    }
    vi tempSA(n);
    for (int i = 0; i < n; ++i)                  // sort SA
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    swap(SA, tempSA);                            // update SA
  }

  void constructSA() {                           // can go up to 400K chars
    SA.resize(n);
    iota(SA.begin(), SA.end(), 0);               // the initial SA
    RA.resize(n);
    for (int i = 0; i < n; ++i) RA[i] = T[i];    // initial rankings
    for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
      // this is actually radix sort
      countingSort(k);                           // sort by 2nd item
      countingSort(0);                           // stable-sort by 1st item
      vi tempRA(n);
      int r = 0;
      tempRA[SA[0]] = r;                         // re-ranking process
      for (int i = 1; i < n; ++i)                // compare adj suffixes
        tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
          ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k])) ?
            r : ++r;
      swap(RA, tempRA);                          // update RA
      if (RA[SA[n-1]] == n-1) break;             // nice optimization
    }
  }

  void computeLCP() {
    vi Phi(n);
    vi PLCP(n);
    PLCP.resize(n);
    Phi[SA[0]] = -1;                             // default value
    for (int i = 1; i < n; ++i)                  // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];                      // remember prev suffix
    for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
      if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
      while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L]))
        ++L;                                     // L incr max n times
      PLCP[i] = L;
      L = max(L-1, 0);                           // L dec max n times
    }
    LCP.resize(n);
    for (int i = 0; i < n; ++i)                  // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];                      // restore PLCP
  }
  

public: // bar bar input nile const ta change kora lagte pare may be
    const char* T;                                 // the input string
    int n;                               // the length of T specail character included
    vi SA;                                         // Suffix Array
    vi LCP;  
    vi L, R; vil D;                                      // of adj sorted suffixes
    void init(const char* initialT,  int _n){
        T = initialT;
        n = _n;
        constructSA();                               // O(n log n)
        computeLCP();                                // O(n)
    }                                             // where P is found
    
    void LRarray() {
        L.resize(n + 3, 0); R.resize(n + 3, 0);
        stack<int> stk; stk.push(0);
        for (int i = 1; i < n; i++) {
            while(!stk.empty() and LCP[stk.top()] >= LCP[i]) {
                if (LCP[stk.top()] == LCP[i]) {
                    L[i] = -1; R[i] = -1;
                }
                stk.pop();
            }
            if (L[i] != -1) {
                L[i] = stk.size() == 0? 0: stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        stk.push(n);
        for (int i = n - 1; i >= 1; i--) {
            while(!stk.empty() and stk.top() < n and LCP[stk.top()] >= LCP[i]) {
                stk.pop();
            }
            if (L[i] != -1) {
                R[i] = stk.top();
            }
            else R[i] = -1;
            stk.push(i);
        }
        
    }
    void solve() {
        LRarray();
        D.resize(n + 3, 0);
        scanf("%s", P); string s = P; reverse(s.begin(), s.end());
        int len = (int)strlen(P);
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            int x = s[SA[i]] - 48;
            D[i] = D[i - 1] + x;
        }
        for (int i = 0; i < len; i++) {
            if (P[i] == '0') ans = i + 1;
        }
        
        for (int i = 1; i < n; i++) {
           
            if (LCP[i] == 0 or L[i] == -1 or R[i] == -1) continue;
            ll a = R[i] - L[i]; int mx = 0;
            if (L[i] != 0) {
                mx = max(mx, LCP[L[i]]);
            }
            if (R[i] != n) {
                mx = max(mx, LCP[R[i]]);
            }
            ans = max(ans, (a - D[R[i] - 1] + D[L[i] - 1]) * 1LL * LCP[i]);
        }
        
        printf("%lld\n", ans);
        
    }
    
  
};

int main() {
    
    int test;
    test = 1;
    while(test--) {
        int k; scanf("%d", &k);
        scanf("%s", P); int m = (int)strlen(P);                       // read T
        int n = 0;
        for (int i = m - 1; i >= 0; i--) T[n++] = P[i];                  // count n
        T[n++] = '$';                     // add terminating symbol
        SuffixArray S; 
        S.init(T, n);    
        S.solve();
    }
    
    return 0;
}