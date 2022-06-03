// author: envy uwu <3
// problem: Planets and Kingdoms
// created: 3/26/2022 8:09 PM

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
vector<int> graph[N], revgraph[N];
bool vis[N], vis2[N];
int ans[N];
vector<int> path;

void dfs(int node){
    vis[node] = true;
    for(int i: graph[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    path.push_back(node);
}

void dfs2(int node, int id){
    vis2[node] = true;
    for(int i: revgraph[node]){
        if(!vis2[i]){
            dfs2(i,id);
        }
    }
    ans[node] = id;
}

void solve() {
    int n,m; cin>>n>>m;
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
    int cnt = 1;
    for(int i: path){
        if(!vis2[i]){
            dfs2(i,cnt);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
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
