// author: envy uwu <3
// problem: Planets Queries I
// created: 1/24/2022 10:05 PM

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

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int MAXN = 2e5+5, L = 30;
int up[MAXN][L];

void solve() {
    int n,q; cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>up[i][0];
    }
    for(int k = 1; k < L; k++){
        for(int i = 1; i <= n; i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }

    auto query = [&](int i, int k){
        for(int v = 0; v < L; v++){
            if(k&(1<<v))
                i = up[i][v];
        }
        return i;
    };

    while(q--){
        int x,k; cin>>x>>k;
        cout<<query(x,k)<<"\n";
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
