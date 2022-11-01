#include<bits/stdc++.h>
using namespace std;
#define MAX 300006
typedef long long ll;
ll B[MAX], A[MAX];
struct SegmentTree{
	vector<ll> tree;
	int n;
	SegmentTree(int _n){
	    n = _n;
	    tree.clear();
	    tree.resize(n * 4);
	}
	void build(int node, int tb, int te){
	    if(tb > te) return;
		if(tb == te){
			tree[node]  = A[tb];//value goes here
			return;
		}
		int mid=(tb + te) >> 1; 
		int left = (node * 2);
		int right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		tree[node] = __gcd(tree[left], tree[right]);
	}
	
	// Range query
	ll query(int node, int tb, int te, int qb, int qe){
        if(tb > te) return 0;
        if(qb > te || qe < tb)return 0;
        if(qb <= tb && te <= qe){
            return tree[node];
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        ll L = query(left, tb, mid, qb, qe);
        ll R = query(right, mid + 1, te, qb, qe);
        return __gcd(L,R);
    }

}; 
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &B[i]);
        }
        int m  = n - 1;
        for(int i = 1; i < n; i++){
            A[i] = abs(B[i] - B[i + 1]);
        }
        SegmentTree st(m);
        st.build(1, 1, m);
        int res = 0;
        for(int i = 1; i <= m; i++){
            int l = i;
            int r = m;
            int ans = i;
            while(l <= r){
                int mid = (l + r) / 2;
                ll G = st.query(1, 1, m, i, mid);
                if(G != 1LL){
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    ans = mid - 1;
                    r = mid - 1;
                }
            }
            res = max(res, ans - i + 1);
        }
        printf("%d\n", res + 1);
    }
    //for (auto it: st.tree) cout << it << endl;
}