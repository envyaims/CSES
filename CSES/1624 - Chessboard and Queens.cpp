#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
const int n = 8;
char grid[n][n];
bool hascol[n], diag[2*n], revdiag[2*n];
int ans = 0;

void test(int cnt){
	if(cnt == n){
		++ans;
		return;
	}
	for(int i = 0; i < n; i++){
		if(grid[cnt][i] == '.' && !hascol[i] && !diag[cnt+i] && !revdiag[i-cnt+7]){
			hascol[i] = diag[cnt+i] = revdiag[i-cnt+7] = true;
			test(cnt+1);
			hascol[i] = diag[cnt+i] = revdiag[i-cnt+7] = false;
		}
	}
}

void solve() {
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}
	test(0);
	cout<<ans;
	
	
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("uwu","r",stdin);
    freopen("owo","w",stdout);
    #endif
    int t = 1;
    //cin>>t;
    for(int i = 1; i <= t; i++){
		debug(t);
		solve();
	}
 
}

