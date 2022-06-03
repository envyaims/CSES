// Author: envy
// Problem: Hotel Queries from CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1143
// Limits: 1000 ms, 512 MB
// Attempted: 2021-10-04 22:32:34 EST

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
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

int n, m; 
struct segtree{
	
	vector<int> seg;
	
	void init(int size){
		seg.resize(2*n,0LL);
	}
	
	void initval(int k, int x){
		k += n;
		seg[k] = x;
		k /= 2;
		while(k > 0){
			seg[k] = max(seg[2*k], seg[2*k+1]);
			k /= 2;
		}
		
	}
	
	void subval(int k, int x){
		k += n;
		seg[k] -= x;
		k /= 2;
		while(k > 0){
			seg[k] = max(seg[2*k], seg[2*k+1]);
			k /= 2;
		}
		
	}
	
	int query(int l, int r){
		l += n, r += n;
		int maxnum = 0;
		while(l <= r){
			if(l % 2 == 1){
				max_self(maxnum, seg[l]);
				l++;
			}
			if(r % 2 == 0){
				max_self(maxnum, seg[r]);
				r--;
			}
			l /= 2; r /= 2;
		}
		return maxnum;
	}
	
	int binsearch(int x){
		if(seg[n] >= x){
			return 0;
		}
		int l = 0, r = n;
		int ans = 1e9;
		while(l < r-1){
			int mid = (l+r)/2;
			debug(l,mid,query(l,mid));
			if(query(l,mid) >= x){
				r = mid;
				min_self(ans,mid);
			}
			else{
				l = mid;
			}
		}
		return ans;
	}
	
	
	
};

void doStuff(){
	cin>>n>>m;
	vector<int> hotels(n);
	vector<int> people(m);
	for(int& i: hotels)cin>>i;
	for(int& i: people)cin>>i;
	
	segtree st;
	st.init(n);
	for(int i = 0; i < n; i++){
		st.initval(i,hotels[i]);
	}
	for(int i = 0; i < m; i++){
		int target = st.binsearch(people[i]);
		if(target == 1e9){
			cout<<0<<" ";
			continue;
		}
		cout<<target+1<<" ";
		st.subval(target,people[i]);
	}
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
