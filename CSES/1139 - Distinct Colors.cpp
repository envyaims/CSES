// author: envy uwu <3
// problem: Distinct Colors
// created: 1/27/2022 9:25 PM

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
set<int> cols[MAXN];
int query[MAXN], col[MAXN];
vector<int> graph[MAXN];

void dfs(int node, int p){
    cols[node].insert(col[node]);
    for(int i: graph[node]){
        if(i != p){
            dfs(i,node);
            if(cols[i].size() > cols[node].size()){
                swap(cols[node],cols[i]);
            }
            for(int j: cols[i]){
                cols[node].insert(j);
            }
        }
    }
    query[node] = cols[node].size();
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>col[i];
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,1);
    for(int i = 1; i <= n; i++){
        cout<<query[i]<<" ";
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
