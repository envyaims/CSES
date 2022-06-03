// Problem: Array Division
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1085
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-03 08:14:46 EST

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
const int INF = 1e18, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


bool check(ll x, vector<ll> nums, int k){
	ll sum = 0;
	int groups = 1;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] > x)return false;
		if(sum + nums[i] > x){
			groups++;
			sum = 0;
		}
		sum += nums[i];
	}
	return (groups <= k);
}


void doStuff(){
	int n,k;
	cin>>n>>k;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	
	ll start = 0;
	ll end = 1e18;
	ll ans = 0;
	while(start <= end){
		ll mid = start + (end-start)/2;
		if(check(mid,nums,k)){
			end = mid-1;
			ans = mid;
		}
		else start = mid+1;
	}
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}

