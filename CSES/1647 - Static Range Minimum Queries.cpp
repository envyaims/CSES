// author: uwuenvy <3
// problem: Static Range Minimum Queries
// created: 1/25/22 1:09 PM

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else

#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"

#endif

using namespace std;
#define int long long

const int MAXN = 2e5+5, L = 20;
int sparse[MAXN][L];

void solve() {
    int n,q; cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>sparse[i][0];
    for(int k = 1; k < L; k++){
        for(int i = 1; i + (1<<k) <= n+1; i++){
            sparse[i][k] = min(sparse[i][k-1],sparse[i + (1<<(k-1))][k-1]);
        }
    }
    while(q--){
        int l,r; cin>>l>>r;
        int v = log2(r-l+1);
        cout<<min(sparse[l][v],sparse[r - (1<<v)+1][v])<<"\n";
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}




