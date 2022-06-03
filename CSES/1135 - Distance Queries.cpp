// author: uwuenvy <3
// problem: Distance Queries
// created: 1/25/22 12:44 PM

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else

#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"

#endif

using namespace std;
#define int long long

const int MAXN = 2e5+5, L = 20;
int pref[MAXN], up[MAXN][L], enter[MAXN], leave[MAXN], par[MAXN];
int t = 1;
vector<int> graph[MAXN];

void dfs(int node){
    enter[node] = t++;
    for(int i: graph[node]){
        if(i != par[node]){
            par[i] = node;
            pref[i] = pref[node]+1;
            dfs(i);
        }
    }
    leave[node] = t-1;
}

bool anc(int a, int b){
    return enter[b] >= enter[a] && leave[a] >= leave[b];
}

int lca(int a, int b){
    if(anc(a,b))return a;
    for(int k = L-1; k >= 0; k--){
        if(!anc(up[a][k],b))a = up[a][k];
    }
    return up[a][0];
}

void solve() {
    int n,q; cin>>n>>q;
    vector<int> deg(n+1);
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            par[i] = i;
            dfs(i);
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        up[i][0] = par[i];
    }

    for(int k = 1; k < L; k++){
        for(int i = 1; i <= n; i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }

    while(q--){
        int a,b; cin>>a>>b;
        cout<<pref[a] + pref[b] - 2*pref[lca(a,b)]<<"\n";
    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}




