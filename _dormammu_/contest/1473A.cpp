
// Problem: A. Replacing Elements
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1473/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 

using namespace std;
using Lint = long long;
using Frac = double;
const int MAX_N = 500006;

#define   pb          push_back
#define   mp          make_pair
#define   mem(a, v)   memset(a, v, sizeof(a))

vector <Lint> prime;
bool mark[10000008];

void seive (){ Lint N = 1e7; int limit = sqrt(N*1.0)+2;mark[1] = 1;for(int i = 4;i <= N; i += 2)mark[i] = 1; prime.push_back(2); for(int i = 3; i <= N; i += 2){if(!mark[i]){prime.push_back(i); if(i <= limit){for(int j = i * i; j <= N; j += i * 2)mark[j] = 1;}}}}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    cin >> testCase;
    Lint a, b, c, d, k, l, m, n, p, q, r, x, y;
    Frac X, Y, P, Q, R, Pi, G,theta,  val, avg;
    
    while (testCase--){
        cin >> n >> d;
        
        Lint sum = 0, ans = 0, cntr = 0, cnt = 0;
        string input, Answer = "", s[n + 4], Res;
        Lint A[n + 6], B[n + 6], occ[n + 6] = {0};
        vector<Lint> vec, V, Ans;
        map<Lint, Lint> M;
        
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        sort(A, A+ n);
        for(int i = 0; i < n; i++){
            if(A[i] > d){
                cntr = 1;
            }
        }
        if(!cntr){
            cout << "YES" << endl;
        }
        else {
            a = A[0] + A[1];
            if(a <= d){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        
    }

    return 0;
}