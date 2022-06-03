#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+5;
const int INF = 1e18;

multiset<array<int,3>> people;
int onday[MAXN];
int days;

void dfs(int stime, int etime, int idx){
	onday[idx] = days;
	people.erase(people.find({stime,etime,idx}));
	auto it = people.upper_bound({etime,INF,0});
	if(it == people.end())return;
	else{
		array<int,3> cur = *it;
		dfs(cur[0], cur[1], cur[2]);
	}
}

void solve() {
    int n; cin>>n;
    for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		people.insert({a,b,i});
	}
	for(days = 1;!people.empty();days++){
		array<int,3> cur = *people.begin();
		dfs(cur[0], cur[1], cur[2]);
	}
	cout<<days-1<<"\n";
	for(int i = 0; i < n; i++){
		cout<<onday[i]<<" ";
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

