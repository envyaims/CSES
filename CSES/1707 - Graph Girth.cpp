// Author: envy
// Problem: Graph Girth
// Attempted: 2021-11-21 15:46:07 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> graph[2501];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int ans = 1e9;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		vector<int> dist(n+1,1e9);
		q.push(i);
		dist[i] = 0;
		
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int j: graph[node]){
				if(dist[j] == 1e9){
					dist[j] = dist[node]+1;
					q.push(j);
				}
				else if(dist[j] >= dist[node]){
					ans = min(ans,dist[node]+1+dist[j]);
				}
			}
		}
	}
	if(ans == 1e9){
		cout<<-1;
	}
	else cout<<ans;
	
	
}
