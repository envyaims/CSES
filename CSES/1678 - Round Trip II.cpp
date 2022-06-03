// Author: envy
// Problem: Round Trip II
// Attempted: 2021-11-27 16:17:35 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> graph[100001];
vector<int> status(100001);
vector<int> cycle;

bool dfs(int node){
	status[node] = 1;
	for(int i: graph[node]){
		if(status[i] == 1 && i != node){
			cycle.push_back(node);
			status[i] = 2;
			status[node] = 2;
			return true;
		}
		else if(status[i] == 0){
			if(dfs(i)){
				cycle.push_back(node);
				if(status[node] == 1){
					status[node] = 2;
					return true;
				}
				else return false;
			}
		}
		if(!cycle.empty()){
			return false;
		}
	}
	status[node] = 2;
	return false;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i= 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++){
		if(status[i] == 0){
			dfs(i);
			if(!cycle.empty()){
				reverse(cycle.begin(),cycle.end());
				cout<<cycle.size()+1<<"\n";
				for(int i: cycle)cout<<i<<" ";
				cout<<cycle[0];
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
	
	
}
