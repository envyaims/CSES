// Problem: Factory Machines
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1620
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-03 07:21:50 EST

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
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())

ll n; 
ll k;
vector<ll> nums;

bool check(ll x){
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += (x/nums[i]);
		if(sum >= k)break;
	}
	return (sum >= k);
}

ll firstTrue(ll start, ll end, function<bool(long long)> f){
	for(end++; start < end; ){
		ll mid = start + (end-start)/2;
		if(f(mid)) end = mid;
		else start = mid+1;
	}
	return start;
}

void doStuff(){
	ri(n,k);
	for(int i = 0; i < n; i++){
		ll a; ri(a);
		nums.pb(a);
	}
	
	cout<< firstTrue(0,INF,check);
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();

    return 0;
}

