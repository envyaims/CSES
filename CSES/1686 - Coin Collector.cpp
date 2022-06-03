// author: envy uwu <3
// problem: Coin Collector
// created: 3/23/2022 7:13 PM

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
const int N = 1e5+5;
vector<int> graph[N], revgraph[N], compgraph[N];
bool vis[N], vis2[N];
int val[N], comp[N], compval[N], dp[N];
vector<int> path;
int cmpcnt = 1;

void dfs(int node){
    vis[node] = true;
    for(int i: graph[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    path.push_back(node);
}

void dfs2(int node){
    vis2[node] = true;
    for(int i: revgraph[node]){
        if(!vis2[i]){
            dfs2(i);
        }
    }
    comp[node] = cmpcnt;
}

int dfs3(int cmp){
    if(dp[cmp]) return dp[cmp];
    dp[cmp] = compval[cmp];
    // travel to another component
    for(int i: compgraph[cmp]){
        dp[cmp] = max(dp[cmp], dfs3(i) + compval[cmp]);
    }
    return dp[cmp];
}

void solve() {
    int n,m; cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>val[i];
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(all(path));
    for(int i: path){
        if(!vis2[i]){
            dfs2(i);
            cmpcnt++;
        }
    }

    for(int i = 1; i <= n; i++){
        compval[comp[i]] += val[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j: graph[i]){
            if(comp[i] != comp[j]){
                compgraph[comp[i]].push_back(comp[j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < cmpcnt; i++){
        ans = max(ans, dfs3(i));
    }
    cout<<ans<<endl;

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
