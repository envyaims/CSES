// author: envy uwu <3
// problem: Subtree Queries
// created: 1/24/2022 9:22 PM

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else

#include "C:\programmingfunnyxd\debug.cpp"

#endif

using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int val[MAXN], start[MAXN], leave[MAXN], sz[MAXN];
int tim = 1;

struct segtree {

    vector<int> seg;
    int _n;

    segtree(int nn) {
        seg.resize(2 * nn, 0LL);
        _n = nn;
    }

    void update(int k, int x) {
        k += _n;
        seg[k] = x;
        k /= 2;
        while (k > 0) {
            seg[k] = seg[2 * k] + seg[2 * k + 1];
            k /= 2;
        }

    }


    int query(int l, int r) {
        l += _n, r += _n;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum += seg[l];
                l++;
            }
            if (r % 2 == 0) {
                sum += seg[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return sum;
    }

};

void dfs(int node, int p){
    start[node] = tim++;
    for(int i: graph[node]){
        if(i != p){
            dfs(i,node);
        }
    }
    leave[node] = tim-1;
}

void solve() {
    int n,q; cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>val[i];
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,0);
    segtree st(n+1);
    for(int i = 1; i <= n; i++){
        st.update(start[i],val[i]);
    }
    while(q--){
        int t; cin>>t;
        if(t == 1){
            int s,x; cin>>s>>x;
            st.update(start[s],x);
        }
        else{
            int s; cin>>s;
            cout<<st.query(start[s],leave[s])<<"\n";
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
