// 90 points
 
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif
 
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
struct frac{
	int num, den;
	void reduce(){
		bool is_neg = false;
		if(num < 0){
			num = -num;
			is_neg = true;
		}
		int g = gcd(num, den);
		num /= g;
		den /= g;
		if(is_neg) num = -num;
	}
	string toString(){
		if(den == 1){
			return to_string(num);
		}
		return to_string(num) + "/" + to_string(den);
	}
};
 
frac sub(frac a, frac b){
	int lc = lcm(a.den, b.den);
	int a_num = (lc / a.den) * a.num;
	int b_num = (lc / b.den) * b.num;
	frac ret = {a_num - b_num, lc};
	ret.reduce();
	return ret;
}
 
frac add(frac a, frac b){
	int lc = lcm(a.den, b.den);
	int a_num = (lc / a.den) * a.num;
	int b_num = (lc / b.den) * b.num;
	frac ret = {a_num + b_num, lc};
	ret.reduce();
	return ret;
}
 
bool eq(frac a, frac b){
	return a.num == b.num && a.den == b.den;
}
 
frac div(frac a, int b){
	a.den *= b;
	a.reduce();
	return a;
}
 
int comp(frac a, frac b){
	if(a.num * b.den > b.num * a.den) return 1;
	if(a.num * b.den < b.num * a.den) return -1;
	return 0;
}
 
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
 
void uwu(){
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			string s; cin >> s;
			if(s == ".") g[i][j] = -10000;
			else g[i][j] = stoi(s);
		}
	}
	
	// case no num;
	const int nul = -10000;
	int cnt = 0;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] != nul){
				cnt++;
				v.push_back({i, j});
			}
		}
	}
	
	if(!cnt){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				g[i][j] = 69420;
			}
		}
	}
	
	const frac null = {-10000, -10000};
	vector<vector<frac>> fg(n, vector<frac>(m, null));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] != -10000){
				fg[i][j] = {g[i][j], 1};
			}
		}
	}
	
	vector<vector<frac>> orig = fg;
 
	auto works = [&](){
		while(1){
			// while we can fill...
			// account for row first
			bool can_fill = false;
			for(int i = 0; i < n; i++){
				vector<int> not_empty;
				for(int j = 0; j < m; j++){
					if(!eq(fg[i][j], null)){
						not_empty.push_back(j);
					}
				}
				if(not_empty.size() == m) continue;
				
				if(not_empty.size() >= 2){
					can_fill = true;
					int l = not_empty[0], r = not_empty[1];
					frac ratio = div(sub(fg[i][r], fg[i][l]), r - l);
					// debug(i, l, r, ratio.toString());
					ratio.reduce();
					assert(ratio.den > 0);
					frac cur = fg[i][l];
					for(int j = l + 1; j < m; j++){
						cur = add(cur, ratio);
					//	debug(i, j, cur.toString());
						cur.reduce();
						if(!eq(fg[i][j], null) && !eq(fg[i][j], cur)){
							return comp(cur, fg[i][j]);
						}
						fg[i][j] = cur;
					}
					cur = fg[i][l];
					for(int j = l - 1; j >= 0; j--){
						cur = sub(cur, ratio);
					//	debug(i, j, cur.toString());
						cur.reduce();
						if(!eq(fg[i][j], null) && !eq(fg[i][j], cur)){
							return comp(cur, fg[i][j]);
						}
						fg[i][j] = cur;
					}
				}
			}
			
			for(int j = 0; j < m; j++){
				vector<int> not_empty;
				for(int i = 0; i < n; i++){
					if(!eq(fg[i][j], null)){
						not_empty.push_back(i);
					}
				}
				if(not_empty.size() == n) continue;
				
				if(not_empty.size() >= 2){
					can_fill = true;
					int l = not_empty[0], r = not_empty[1];
					frac ratio = div(sub(fg[r][j], fg[l][j]), r - l);
					// debug(i, l, r, ratio.toString());
					ratio.reduce();
					assert(ratio.den > 0);
					frac cur = fg[l][j];
					for(int i = l + 1; i < n; i++){
						cur = add(cur, ratio);
					//	debug(i, j, cur.toString());
						cur.reduce();
						if(!eq(fg[i][j], null) && !eq(fg[i][j], cur)){
							return comp(cur, fg[i][j]);
						}
						fg[i][j] = cur;
					}
					cur = fg[l][j];
					for(int i = l - 1; i >= 0; i--){
						cur = sub(cur, ratio);
					//	debug(i, j, cur.toString());
						cur.reduce();
						if(!eq(fg[i][j], null) && !eq(fg[i][j], cur)){
							return comp(cur, fg[i][j]);
						}
						fg[i][j] = cur;
					}
				}
			}
				
			
			if(!can_fill) break;
		}
		
		//for(int i = 0; i < n; i++){
				//for(int j = 0; j < m; j++){
					//cout << fg[i][j].toString() << " ";
				//}
				//cout << "\n";
			//}
		//cout << "\n";
		
		return 69420;
	};
	
	
	auto is_bad = [&](){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(eq(fg[i][j], null)){
					return true;
				}
			}
		}
		return false;
	};
	
	if(works() != 69420){
		cout << "No solution." << endl;
		return;
	}
	
	auto arb_fill = [&](){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(eq(fg[i][j], null)){
					for(int den = 1; den <= 100; den++){
						int l = -2000, r = 2000;
						while(l < r - 1){
							int mid = (l + r) / 2;
							fg[i][j] = {mid, den};
							fg[i][j].reduce();
							int ret = works();
							if(ret == 69420){
								if(!is_bad()){
									return true;
								}
								break;
							}
							if(ret == 1){
								r = mid;
							}
							else{
								l = mid;
							}
							fg = orig;
						}
						for(int mid: {l, r}){
							fg[i][j] = {mid, den};
							fg[i][j].reduce();
							if(works() == 69420){
								if(!is_bad()){
									return true;
								}
							}
							fg = orig;
						}
						
						//for(int num = -100; num <= 100; num++){
							//fg[i][j] = {num, den};
							//fg[i][j].reduce();
							//if(works() == 69420 && !is_bad()) {
								//debug(i, j, num, den);
								//goto outer;
							//}
							//fg = orig;
						//}
					}
					// break;
				}
			}
		}
		return false;
	};
	
	if(is_bad()){
		if(arb_fill()) goto outer;
	}
	
	//if(is_bad()){
		//cout << "No solution." << endl;
		//return;
	//}
	if(cnt < 4){
		set<int> bad_r, bad_c;
		debug("hi");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!bad_r.count(i) && !bad_c.count(j) && eq(fg[i][j], null)){
					bad_r.insert(i);
					bad_c.insert(j);
					fg[i][j] = {1, 1};
					cnt++;
					if(cnt == 4) break;
				}
			}
			if(cnt == 4) break;
		}
		orig = fg;
		arb_fill();
		//for(int i = 0; i < n; i++){
			//for(int j = 0; j < m; j++){
				//cout << fg[i][j].toString() << " ";
			//}
			//cout << "\n";
		//}
		
	}
	
	
	if(m > 1){
		for(int i = 0; i < n; i++){
			frac ratio = sub(fg[i][1], fg[i][0]);
			ratio.reduce();
			frac cur = fg[i][0];
			for(int j = 1; j < m; j++){
				cur = add(cur, ratio);
				cur.reduce();
				if(!eq(cur, fg[i][j])){
					// debug(i, j);
					cout << "No solution." << endl;
					return;
				}
			}
		}
	}
	debug(n, m);
	
	if(n > 1){
		for(int j = 0; j < m; j++){
			frac ratio = sub(fg[1][j], fg[0][j]);
			ratio.reduce();
			frac cur = fg[0][j];
			for(int i = 1; i < n; i++){
				cur = add(cur, ratio);
				// debug(j, i, ratio.toString());
				//debug(i, j);
				cur.reduce();
				if(!eq(cur, fg[i][j])){
					cout << "No solution." << endl;
					return;
				}
			}
		}
	}
	
	outer:
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << fg[i][j].toString() << " ";
		}
		cout << "\n";
	}
	
}
 
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	for(int _ = 0; _ < T; _++){
		uwu();
	}
}
 
/*   /\_/\
*   (= ._.)
*   / >  \>
*/
