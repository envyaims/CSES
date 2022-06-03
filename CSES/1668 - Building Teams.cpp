// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-04 15:46:36 EST

#include <bits/stdc++.h>
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

typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())

vector<int> graph[200001];
bool visited[200001];
bool group[200001];
bool valid = true;

void dfs(int node, int gru = false){
	visited[node] = true;
	group[node] = gru;
	for(auto n: graph[node]){
		if(visited[n]){
			if(group[n] == gru){
				valid = false;
				return;
			}
		}
		else{
			dfs(n,!gru);
		}
	}
}

void doStuff(){
	int n,m; ri(n,m);
	for(int i = 0; i < m; i++){
		int a,b; ri(a,b);
		graph[a].pb(b);
		graph[b].pb(a);

	}
	
	for(int i = 1; i <= n && valid; i++){
		if(!visited[i]){
			dfs(i);
		}

	}
	
	if(!valid){
		print("IMPOSSIBLE");
	}
	else{
		for(int i = 1; i <= n; i++){
			cout<< group[i]+1<<" ";
		}
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}

