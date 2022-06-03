// Author: envy
// Problem: Game Routes
// Attempted: 2021-11-27 17:05:01 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> graph[100001];
int n,m;
const int MOD = 1e9+7;
vector<int> ways(100001);
int indegree[100001];
bool visited[100001];

void dfs(int node){
	visited[node] = true;
	for(int i: graph[node]){
		ways[i] += ways[node];
		ways[i] %= MOD;
		indegree[i]--;
		if(indegree[i] == 0){
			dfs(i);
		}
	}
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	ways[1] = 1;
	for(int i = 1; i <= n; i++){
		if(!visited[i] && indegree[i] == 0){
			dfs(i);
		}
	}
	
	cout<<ways[n];
	
}
