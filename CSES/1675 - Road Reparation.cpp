// Author: envy
// Problem: Road Reparation
// Attempted: 2021-11-25 22:31:04 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int ans = 0;
struct DSU{
	vector<int> p, sz;
	DSU(int n){
		p.resize(n);
		sz.resize(n,1);
		iota(p.begin(),p.end(),0);
	}
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	void unite(int a, int b, int amt){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
			ans += amt;
		}
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	vector<array<int,3>> edges(m);
	for(int i = 0; i < m; i++){
		int a,b,w; cin>>a>>b>>w;
		edges[i][0] = w, edges[i][1] = a, edges[i][2] = b;
	}
	sort(edges.begin(),edges.end());
	DSU dsu(n+1);
	for(int i = 0; i < m; i++){
		dsu.unite(edges[i][1],edges[i][2],edges[i][0]);
	}
	if(dsu.getsize(1) < n){
		cout<<"IMPOSSIBLE";
	}
	else cout<<ans;
	
}
