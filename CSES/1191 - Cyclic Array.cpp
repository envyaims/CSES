#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
const int MAXL = 20; // approx maximum log of n

// binary lifting arrays:

/*
 * next[i][j] stores the start point of the next
 * 2^j'th subarray if we choose this subarray starting at i
 */
array<array<int,MAXL>,MAXN> nxt;

/* len[i][j] stores the total amount of elements between
 * subarray starting at i and the next 2^j'th subarray
 */ 
array<array<ll,MAXL>,MAXN> len;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	
	// edge case: every element can go into one subarray
	if(k >= sum){
		printf("%d",1);
		return 0;
	}
	
	sum = 0;
	for(ll l = 0, r = 0; l < n; l++){
		while(sum + a[r % n] <= k){
			sum += a[r % n];
			r++;
		}
		
		// initialize binary lifting arrays
		nxt[l][0] = r % n;
		len[l][0] = r - l;
		
		sum -= a[l];
	}
	
	for(int j = 1; j < MAXL; j++){
		for(int i = 0; i < n; i++){
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
			// add lengths from the left and the right
			len[i][j] = len[i][j-1] + len[nxt[i][j-1]][j-1];
		}
	}
	
	/* 
	 * returns the number of elements between the subarray 
	 * starting at x and the next y subarrays
	 */
	auto len_between = [&](int x, int y) -> ll{
		ll total = 0;
		for(int i = 0; i < MAXL; i++){
			if(y & (1 << i)){
				total += len[x][i];
				x = nxt[x][i];
			}
		} 
		
		return total;
	};
	
	/* 
	 * return true if there is a series of x subarrays
	 * that uses the whole array
	 */
	auto check = [&](int x) -> bool{
		for(int i = 0; i < n; i++){
			if(len_between(i, x) >= n){
				return true;
			}
		}
		return false;
	};
	
	/* 
	 * binary search over the least amount of subarrays
	 * needed to cover the whole array
	 */
	 int l = 0, r = n;
	 while(l < r - 1){
		 int mid = l + (r - l) / 2;
		 if(check(mid)){
			 r = mid;
		 }
		 else l = mid;
	 }
	 
	 printf("%d",r);
}

