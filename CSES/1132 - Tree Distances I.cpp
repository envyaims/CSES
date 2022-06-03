#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define int long long

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int dist[3][MAXN];
// dist[0] will be from whatever node i start from
// dist[1] will be from one diameter
// dist[2] will be from the other

void dfs(int node, int p, int id){
	for(int i: graph[node]){
		if(i != p){
			dist[id][i] = dist[id][node]+1;
			dfs(i,node,id);
		}
	}
}

int getfarthest(int id){
	int curmax = 0, far = 0;
	for(int i = 1; i < MAXN; i++){
		if(dist[id][i] > curmax){
			far = i;
			curmax = dist[id][i];
		}
	}
	return far;
}

void solve(){
	int n; cin>>n;
	for(int i = 0; i < n-1; i++){
		int u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1,1,0);
	int farone = getfarthest(0);
	dfs(farone,farone,1);
	int fartwo = getfarthest(1);
	dfs(fartwo,fartwo,2);
	for(int i = 1; i <= n; i++){
		cout<<max(dist[1][i],dist[2][i])<<" ";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}


