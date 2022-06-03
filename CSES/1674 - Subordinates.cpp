// Problem: Subordinates
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1674
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-06 14:30:00 EST

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
const int MOD = 1e9+7, MN = 1e5 + 5;
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
int n;
ll cnt[200001];

void dfs(int node, int parent){
	cnt[node] = 1;
	for(int i: graph[node]){
		if(i == node)continue;
		dfs(i,parent);
		cnt[node] += cnt[i];
	}
}
void doStuff(){
	ri(n);
	for(int i = 1; i < n; i++){
		int a; ri(a);
		graph[a-1].pb(i);
		
	}
	dfs(0,0);
	for(int i = 0; i < n; i++){
		cout<<cnt[i]-1<<" ";
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* most importantly stop being an dumb
*/

