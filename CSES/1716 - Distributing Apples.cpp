#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;

vector<int> facts = {1,1};
vector<int> inverse;
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

int ncr(int n, int k){
   return facts[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}
signed main()
{
    int n,k; cin>>k>>n;
    inverse.resize(n+k);
    inverse[0] = 1;
    inverse[1] = 1;
    for(int i = 2; i <= n+k-1; i++){
        facts.push_back(facts.back() * i % MOD);
        inverse[i]= pow(facts.back(),MOD-2,MOD);
    }
    cout<<ncr(n+k-1,n);
}

