// Author: envy
// Problem: Grid Paths from CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1625
// Limits: 1000 ms, 512 MB
// Attempted: 2021-09-25 08:53:07 EST
// im going to go bald by the time i solve this

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define readarr(arr) for(int &i: arr)ri(i);
#define readchararr(arr)for(int &i: arr)rc(i);
#define readgrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)ri(arr[i][j]);
#define readchargrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)rc(arr[i][j]);
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

string s;
bool visited[7][7];
int cnt = 0;

//if its not possible to reach the end
void brutepossible(int r, int c, bool& ok){
	if(r < 0 || r >= 7 || c < 0 || c >= 7 || visited[r][c])return;
	visited[r][c] = true;
	if(r == 6 and c == 0){
		ok = true;
		return;
	}
	for(int i = 0; i < 4; i++){
		brutepossible(dx[i]+r, dy[i]+c,ok);
	}
	visited[r][c] = false;
	
}

//if the end is blocked off by a whole row or column of things but only works for straight lines lol
bool possible(int r, int c){
	if(visited[5][0] and visited[6][1])return false;
	bool ok = true;
	for(int i = r+1; i <= 6; i++){
			bool allvisited = true;
			for(int j = 0; j < 7; j++){
				if(!visited[i][j]){
					allvisited = false;
					break;
				}
			}
			if(allvisited){
				return false;
			}
	}
	for(int i = 0; i < c; i++){
			bool allvisited = true;
			for(int j = 0; j < 7; j++){
				if(!visited[j][i]){
					allvisited = false;
					break;
				}
			}
			if(allvisited){
				return false;
			}
	}
	
	

	return true;
}

// idek what this is
bool possible2(int r, int c){
	bool allvis = true;
	for(int col = 0; col < 7; col++){
		bool hasvis = false;
		for(int row = r+1; row < 7; row++){
			if(visited[row][col]){
				hasvis = true;
				break;
			}
		}
		if(!hasvis){
			allvis = false;
			break;
		}
	}
	
	for(int row = r+1; row < 7; row++){
		bool hasvis = false;
		for(int col = 0; col < c; col++){
			if(visited[row][col]){
				hasvis = true;
				break;
			}
		}
		if(!hasvis){
			allvis = false;
			break;
		}
	}
	if(allvis)return false;
	else return true;

}

bool check(int r, int c, char dir){
	// if last or first col and youre going up its a fruit rollup that rhymes
	// if((c == 6 || c == 0) and dir == 'U')return false;
	// if(r == 0 and dir == 'L')return false;
	// if(r == 6 and dir == 'R')return false;
	// if(visited[5][0] and visited[6][1])return false;
	
	if((visited[r-1][c] or r == 0) and (visited[r+1][c] or r == 6) and !(visited[r][c+1] or c == 6) and !(visited[r][c-1] or c == 0))return false;
	if((visited[r][c+1] or c == 6) and (visited[r][c-1] or c == 0) and !(visited[r+1][c] or r == 6) and !(visited[r-1][c] or r == 0))return false;
	
	
	// attempt 1 - 1.2s
	// if(dir == 'U' and visited[r-1][c] and !(visited[r][c-1] or visited[r][c+1] or c == 6 or c == 0))return false;
	// if(dir == 'R' and visited[r][c+1] and !(visited[r-1][c] or visited[r+1][c] or r == 6 or r == 0))return false;
	// if(dir == 'L' and visited[r][c-1] and !(visited[r-1][c] or visited[r+1][c] or r == 6 or r == 0))return false;
	// if(dir == 'D' and visited[r+1][c] and !(visited[r][c-1] or visited[r][c+1] or c == 6 or c == 0))return false;
	
	// attempt 2 - 1.4s
	// if(visited[r][c-1] and visited[r][c+1] and !(visited[r-1][c] or visited[r+1][c] or r == 6 or r == 0))return false;
	// if(visited[r+1][c] and visited[r-1][c] and !(visited[r][c-1] or visited[r][c+1] or c == 6 or c == 0))return false;
	
	// if(visited[r-1][c] and !(visited[r][c-1] or visited[r][c+1] or c == 6 or c == 0))return false;
	
	
	return true;
}
void bfs(int r, int c, int length, char dir = 'X'){
	if(r < 0 || r >= 7 || c < 0 || c >= 7 || visited[r][c])return;
	if(r == 6 and c == 0){
		if(length == 48){
			cnt++;
			return;
		}
		else return;
	}
	if(!check(r,c,dir))return;
	visited[r][c] = true;

	
	if(s[length] == 'R'){
		bfs(r,c+1,length+1,'R');
	}
	if(s[length] == 'L'){
		bfs(r,c-1,length+1,'L');
	}
	if(s[length] == 'D'){
		bfs(r+1,c,length+1,'D');
	}
	if(s[length] == 'U'){
		bfs(r-1,c,length+1,'U');
	}
	if(s[length] == '?'){
		bfs(r,c+1,length+1,'R');
		bfs(r,c-1,length+1,'L');
		bfs(r+1,c,length+1,'D');
		bfs(r-1,c,length+1,'U');
	}
	visited[r][c] = false;
} 
void doStuff(){
	cin>>s;
	// visited[6][0] = true;
	bfs(0,0,0);
	print(cnt);
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
