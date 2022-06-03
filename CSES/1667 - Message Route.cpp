// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-23 08:07:55 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif

using namespace std;

inline namespace fastio {
	const int BSZ = 1<<15; 
	char ibuf[BSZ]; int ipos, ilen;
	char nc() {
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T> void rc(T& x){ // read char
		x = nc();
		while(isspace(x)){
			x = nc();
		}
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	template<class str>void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
}

struct minsecond{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.second > b.second; 
	}
};
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond> secondpq;
typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

int n,m;
vector<int> graph[100001];

pair<vector<int>,vector<int>> dijkstra(int start, int end){
	vector<int> dist(n+1,1e9);
	vector<bool> visited(n+1,false);
	vector<int> prev(n+1,-1);
	dist[start] = 0;
	
	secondpq pq;
	pq.push(mp(start,0));
	while(!pq.empty()){
		int index = pq.top().F;
		int mindist = pq.top().S;
		pq.pop();
		visited[index] = true;
		if(dist[index] < mindist){
			continue;
		}
		for(auto node: graph[index]){
			if(visited[node])continue;
			int newdist = dist[index] + 1;
			if(newdist < dist[node]){
				prev[node] = index;
				dist[node] = newdist;
				pq.push(mp(node,newdist));
			}
		}
		
		if(index == end){ // if know end
			return mp(dist,prev);
		}
		
	}
	return mp(dist,prev);
}

vector<int> shortestpath(int start, int end){
	pair<vector<int>,vector<int>> info = dijkstra(start,end);
	vector<int> dist = info.F;
	vector<int> prev = info.S;
	vector<int> path;
	if(dist[end] == 1e9){
		// cannot be reached, returns empty path
		return path;
	}
	for(int i = end; i != -1; i = prev[i]){
		path.pb(i);
		
	}
	reverse(all(path));
	return path;
}

void doStuff(){
	ri(n,m);
	for(int i = 0; i < m; i++){
		int a,b; ri(a,b);
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	vector<int> path = shortestpath(1,n);
	if(path.empty()){
		print("IMPOSSIBLE");
	}
	else{
		print(path.size());
		for(int i: path){
			cout<<i<<" ";
		}
	}
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
	// int t; ri(t);
	// while(t--){
		// doStuff();
	// }
    
    
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/

