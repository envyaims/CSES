// Problem: Sum of Three Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1641
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-01 15:29:19 EST

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


void doStuff(){
	int n; ll x; ri(n,x);
	vector<pair<int,int>> nums(n);
	for(int i = 0; i < n; i++){
		int a; ri(a);
		nums[i] = mp(a,i+1);
	}
	sort(all(nums));
	for(int i = 0; i < n; i++){
		int l = 0, r = n-1;
		while(l != r){
			int dif = x - nums[i].first;
			if(l != i && r != i && nums[l].F + nums[r].F == dif){
				cout<<nums[i].second<<" "<<nums[l].second<<" "<<nums[r].second;
				return;
			}
			else{
				if(nums[l].F + nums[r].F > dif){
					r--;
				}
				else l++;
			}
		}
	}
	print("IMPOSSIBLE");
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}

