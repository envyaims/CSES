// Author: envy
// Problem: Course Schedule
// Attempted: 2021-11-27 14:06:19 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int n,m;
vector<int> graph[100001];
vector<int> state(100001);
vector<int> topo;
bool no = false;

void dfs(int node){
	state[node] = 1;
	for(int i: graph[node]){
		if(state[i] == 0){
			dfs(i);
		}
		else if(state[i] == 1){
			no = true;
			break;
		}
	}
	state[node] = 2;
	topo.push_back(node);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++){
		if(state[i] == 0){
			dfs(i);
		}
	}
	
	if(no)cout<<"IMPOSSIBLE";
	else{
		reverse(topo.begin(),topo.end());
		for(int i: topo)cout<<i<<" ";
	}
	
}
