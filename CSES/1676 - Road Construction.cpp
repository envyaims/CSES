// Author: envy
// Problem: Road Construction
// Attempted: 2021-11-25 15:46:45 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

struct dsu{
	vector<int> p, sz;
	int components;
	int maxsize = 1;
	
	void init(int n){
		p.resize(n);
		sz.resize(n,1);
		iota(p.begin(),p.end(),0);
		components = n;
	}
	
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	
	void unite(int a, int b){
		a = get(a);
		b = get(b);
		if(sz[a] < sz[b]){
			swap(a,b);
		}
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
			components--;
			maxsize = max(maxsize,sz[a]);
		}
	}
	
	int getmaxsize(){
		return maxsize;
	}
	
	int getcnt(){
		return components;
	}
	
};
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin>>n>>q;
	dsu dis;
	dis.init(n+1);
	while(q--){
		int a,b; cin>>a>>b;
		dis.unite(a,b);
		cout<<dis.getcnt()-1<<" "<<dis.getmaxsize()<<endl;
	}
	
}
