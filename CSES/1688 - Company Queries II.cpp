// author: envy uwu <3
// problem: Company Queries II
// created: 1/24/2022 10:14 PM
 
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
 
const int MAXN = 2e5+5, L = 20;
int up[MAXN][L], enter[MAXN], leave[MAXN];
int tim = 1;
vector<int> graph[MAXN];
 
void dfs(int node, int p){
    enter[node] = tim++;
    for(int i: graph[node]){
        if(i != p)
            dfs(i,node);
    }
    leave[node] = tim-1;
}
 
bool anc(int a, int b){
    return (enter[a] <= enter[b] && leave[b] <= leave[a]);
}
 
int lca(int a, int b){
    if(anc(a,b))return a;
    for(int v = L-1; v >= 0; v--){
        if(!anc(up[a][v],b)) a = up[a][v];
    }
    debug(a);
    return up[a][0];
}
 
void solve() {
    int n,q; cin>>n>>q;
    for(int i = 2; i <= n; i++){
        int v; cin>>v;
        up[i][0] = v;
        graph[v].push_back(i);
    }
	up[1][0] = 1;
 
    dfs(1,0);
    for(int k = 1; k < L; k++){
        for(int i = 1; i <= n; i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }
 
    while(q--){
        int a,b; cin>>a>>b;
        cout<<lca(a,b)<<"\n";
        //cout<<lca(b,a)<<"\n";
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

