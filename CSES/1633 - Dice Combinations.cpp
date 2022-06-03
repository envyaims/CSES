/**
 * @author   : envifly 
 * @Date     : 12/08/2021
 * @Time     : Thursday Aug 12, 2021 16:05:34 Eastern Daylight Time
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};
#define sp(x) setprecision(x)
#define bpop(x) __builtin_popcount(x)

int n;
vector<ll> dp(1000001,0);
ll sum = 1;

void doShit(int now){
	ll sum = 0;
	for(int i = now-1; i >= now-6; i--){
		sum += dp[i] % MOD;
	}
	dp[now] = sum;
	if(now >= n){
		return;
	}
	doShit(now+1);
}
void doStuff(){
	cin>>n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 8;
	dp[5] = 16;

	doShit(6);
	print(dp[n] % MOD);
	
	
	
	
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
	* maybe just stop being dumb lol
*/


